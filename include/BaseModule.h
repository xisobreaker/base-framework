#pragma once

#include "Component.h"

class BaseModule : public Component
{
public:
    BaseModule();
    virtual ~BaseModule();

public:
    virtual void addComponent(Component *component) override;
    virtual void removeComponent(Component *component) override;
};