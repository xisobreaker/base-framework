#include "Application.h"

#include "Component.h"

#include <glog/logging.h>

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
    m_componentList.push_back(component);
    component->setParent(this);
}

void Application::removeComponent(Component *component)
{
    m_componentList.remove(component);
    component->setParent(nullptr);
}

void Application::startOperator()
{
    for (Component *component : m_componentList) {
        component->startOperator();
    }
}

void Application::stopOperator()
{
    for (Component *component : m_componentList) {
        component->stopOperator();
    }
}
