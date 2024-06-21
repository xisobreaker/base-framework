#pragma once

#include <iostream>

class Component
{
public:
    virtual ~Component() = default;

public:
    void setParent(Component *parent)
    {
        m_parent = parent;
    }

    Component *getParent()
    {
        return m_parent;
    };

public:
    virtual void addComponent(Component *component)    = 0;
    virtual void removeComponent(Component *component) = 0;
    virtual void startOperator()                       = 0;
    virtual void stopOperator()                        = 0;

private:
    Component *m_parent;
};