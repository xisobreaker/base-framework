#include "ModuleFactory.h"

namespace xiso {

ModuleFactory &ModuleFactory::get_instance()
{
    static ModuleFactory instance;
    return instance;
}

BaseModule *ModuleFactory::module_create(const std::string &name)
{
    if (m_modules_creator.find(name) == m_modules_creator.end()) {
        return nullptr;
    }
    return m_modules_creator[name]();
}

} // namespace xiso