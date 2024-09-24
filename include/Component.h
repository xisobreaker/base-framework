#pragma once

#include <iostream>

class Component
{
public:
    Component() : m_parent(nullptr){};
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

public:
    virtual bool init(const std::string &config_path) = 0;
    virtual void start()                              = 0;
    virtual void stop()                               = 0;

private:
    Component *m_parent;
};