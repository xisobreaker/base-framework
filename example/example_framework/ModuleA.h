#pragma once

#include "BaseModule.h"
#include "Component.h"
#include "GoogleGlog.h"
#include "ModuleFactory.h"

#include <iostream>

class ModuleA : public BaseModule
{
public:
    ModuleA(){};
    ~ModuleA(){};

public:
    bool init(const std::string &config_path) override
    {
        return true;
    }

    void start() override
    {
        LOG(INFO) << "ModuleA startOperator";
    }

    void stop() override
    {
        LOG(WARNING) << "ModuleA stopOperator";
    }
};

MODULE_REGISTER_FACTORY(ModuleA, "ModuleA");