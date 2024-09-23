#pragma once

#include "BaseModule.h"
#include "Singleton.h"

#include <functional>
#include <memory>
#include <unordered_map>

template <typename T>
inline std::unique_ptr<T> create_unique_ptr()
{
    return std::make_unique<T>();
}

class ModuleFactory
{
    friend Singleton<ModuleFactory>;
    typedef std::function<std::unique_ptr<BaseModule>()> ModuleCreator;

protected:
    ModuleFactory()                                 = default;
    ~ModuleFactory()                                = default;
    ModuleFactory(const ModuleFactory &)            = delete;
    ModuleFactory(ModuleFactory &&)                 = delete;
    ModuleFactory &operator=(const ModuleFactory &) = delete;

public:
    std::unique_ptr<BaseModule> get_Module(const std::string &name);
    void                        register_Module(const std::string &name, ModuleCreator &&creator);

private:
    std::unordered_map<std::string, ModuleCreator> m_modules_creator;
};

inline ModuleFactory *get_ModuleFactory_instance()
{
    return Singleton<ModuleFactory>::getInstance();
}

#define MODULE_REGISTER_FACTORY(class_name)              \
    class class_name##Register                           \
    {                                                    \
    public:                                              \
        class_name##Register()                           \
        {                                                \
            auto factory = get_ModuleFactory_instance(); \
            factory->register_Module(#class_name, []() { \
                return create_unique_ptr<class_name>();  \
            });                                          \
        };                                               \
        ~class_name##Register() = default;               \
    };
