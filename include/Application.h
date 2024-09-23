#pragma once

#include "Component.h"

#include <list>

class Application : public Component
{
public:
    Application();
    ~Application();

public:
    void addComponent(Component *component) override;
    void removeComponent(Component *component) override;
    void startOperator() override;
    void stopOperator() override;

private:
    std::list<Component *> m_componentList;
};