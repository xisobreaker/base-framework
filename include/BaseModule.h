#pragma once

#include "Component.h"

class BaseModule : public Component
{
public:
    BaseModule();
    virtual ~BaseModule();

private:
    void addComponent(Component *component) final;
    void removeComponent(Component *component) final;
};