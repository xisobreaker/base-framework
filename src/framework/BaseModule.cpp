#include "BaseModule.h"

#include "Component.h"

namespace xiso {

BaseModule::BaseModule()
{
}

BaseModule::~BaseModule()
{
    Component *parent = getParent();
    if (parent)
        parent->removeComponent(this);
}

void BaseModule::addComponent(Component *component)
{
}

void BaseModule::removeComponent(Component *component)
{
}

} // namespace xiso