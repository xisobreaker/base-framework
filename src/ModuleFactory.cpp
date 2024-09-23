#include "ModuleFactory.h"

std::unique_ptr<BaseModule> ModuleFactory::get_Module(const std::string &name)
{
    if (m_modules_creator.find(name) == m_modules_creator.end()) {
        return nullptr;
    }
    return m_modules_creator[name]();
}

void ModuleFactory::register_Module(const std::string &name, ModuleCreator &&creator)
{
    m_modules_creator.insert(std::make_pair(name, std::move(creator)));
}
