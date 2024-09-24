#pragma once

#include "BaseModule.h"

#include <functional>
#include <memory>
#include <unordered_map>

namespace xiso {

template <typename T>
inline std::unique_ptr<T> create_unique_ptr()
{
    return std::make_unique<T>();
}

class ModuleFactory
{
public:
    template <typename Inherit>
    class Register_t
    {
    public:
        Register_t(const std::string &key)
        {
            auto &factory = ModuleFactory::get_instance();
            factory.m_modules_creator.insert(std::make_pair(key, []() {
                return new Inherit();
            }));
        }
    };

protected:
    ModuleFactory()                                 = default;
    ~ModuleFactory()                                = default;
    ModuleFactory(const ModuleFactory &)            = delete;
    ModuleFactory(ModuleFactory &&)                 = delete;
    ModuleFactory &operator=(const ModuleFactory &) = delete;

public:
    static ModuleFactory &get_instance();
    BaseModule           *module_create(const std::string &name);

private:
    std::unordered_map<std::string, std::function<BaseModule *()>> m_modules_creator;
};

} // namespace xiso

/**
 * @brief register to factory
 *
 */
#define MODULE_REGISTER_FACTORY(T, key) static xiso::ModuleFactory::Register_t<T> g_##T##_Register(key)