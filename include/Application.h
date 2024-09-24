#pragma once

#include "Component.h"

#include <list>
#include <mutex>

namespace xiso {

class Application : public Component
{
public:
    Application();
    ~Application();

protected:
    void addComponent(Component *component) override;
    void removeComponent(Component *component) override;

public:
    bool init(const std::string &config_path) override;
    void start() override;
    void stop() override;

private:
    std::mutex             m_componentLock;
    std::list<Component *> m_componentList;
};

} // namespace xiso