#include "Framework.h"

#include "Component.h"

#include <glog/logging.h>

Framework::Framework()
{
}

Framework::~Framework()
{
    while (!m_componentList.empty()) {
        Component *component = m_componentList.front();
        removeComponent(component);
        delete component;
    }
}

void Framework::addComponent(Component *component)
{
    m_componentList.push_back(component);
    component->setParent(this);
}

void Framework::removeComponent(Component *component)
{
    m_componentList.remove(component);
    component->setParent(nullptr);
}

void Framework::startOperator()
{
    for (Component *component : m_componentList) {
        component->startOperator();
    }
}

void Framework::stopOperator()
{
    for (Component *component : m_componentList) {
        component->stopOperator();
    }
}
