#pragma once

#include "Component.h"

#include <list>
#include <memory>
#include <mutex>

namespace xiso {

class Application : public Component
{
public:
    Application();
    ~Application();

protected:
    /**
     * @brief 注册组件
     *
     * @param component
     */
    void addComponent(Component *component) override;

    /**
     * @brief 移除组件
     *
     * @param component
     */
    void removeComponent(Component *component) override;

public:
    /**
     * @brief Application 初始化
     *
     * @param config_path 配置文件路径
     * @return true
     * @return false
     */
    bool init(const std::string &config_path) override;

    /**
     * @brief 运行所有已注册的组件
     *
     */
    void start() override;

    /**
     * @brief 停止所有已注册的组件
     *
     */
    void stop() override;

private:
    std::mutex             m_componentLock;
    std::list<Component *> m_componentList;
};

} // namespace xiso