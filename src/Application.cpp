#include "Application.h"

#include "Component.h"
#include "GoogleGlog.h"
#include "ModuleFactory.h"
#include "ProtobufConfig.h"
#include "proto/ApplicationParam.pb.h"

#include <memory>
#include <mutex>
#include <thread>

Application::Application()
{
}

Application::~Application()
{
    while (!m_componentList.empty()) {
        Component *component = m_componentList.front();
        removeComponent(component);
        delete component;
    }
}

void Application::addComponent(Component *component)
{
    std::lock_guard<std::mutex> guard(m_componentLock);
    m_componentList.push_back(component);
    component->setParent(this);
}

void Application::removeComponent(Component *component)
{
    std::lock_guard<std::mutex> guard(m_componentLock);
    m_componentList.remove(component);
    component->setParent(nullptr);
}

bool Application::init(const std::string &config_path)
{
    // 读取配置文件
    base::ApplicationParam param;
    std::string            config_file = config_path + "/" + "application.conf";
    if (!protobuf_read_from_file(param, config_file)) {
        LOG(ERROR) << "read config file " << config_file << " failed!";
        return false;
    }

    auto &factory = ModuleFactory::get_instance();
    for (int i = 0; i < param.components_size(); i++) {
        auto component_param = param.components(i);
        // 添加组件
        auto module = factory.module_create(component_param.module_name());
        if (!module) {
            LOG(ERROR) << component_param.module_name() << " 组件获取失败!";
            continue;
        }

        // 组件添加到队列
        if (component_param.enable_module())
            addComponent(module);
    }

    std::lock_guard<std::mutex> guard(m_componentLock);
    for (Component *component : m_componentList) {
        component->init(config_path);
    }
    return true;
}

void Application::start()
{
    auto start_func = [](Component *component) {
        component->start();
    };

    std::lock_guard<std::mutex>               guard(m_componentLock);
    std::vector<std::unique_ptr<std::thread>> m_threads;
    for (Component *component : m_componentList) {
        std::unique_ptr<std::thread> th;
        th.reset(new std::thread(start_func, component));
        m_threads.push_back(std::move(th));
    }
    for (int i = 0; i < m_threads.size(); i++) {
        if (m_threads[i]->joinable())
            m_threads[i]->join();
    }
}

void Application::stop()
{
    auto stop_func = [](Component *component) {
        component->stop();
    };

    std::lock_guard<std::mutex>               guard(m_componentLock);
    std::vector<std::unique_ptr<std::thread>> m_threads;
    for (Component *component : m_componentList) {
        std::unique_ptr<std::thread> th;
        th.reset(new std::thread(stop_func, component));
        m_threads.push_back(std::move(th));
    }
    for (int i = 0; i < m_threads.size(); i++) {
        if (m_threads[i]->joinable())
            m_threads[i]->join();
    }
}
