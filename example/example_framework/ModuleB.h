#pragma once

#include "BaseModule.h"
#include "GoogleGlog.h"
#include "ModuleFactory.h"

#include <iostream>

class ModuleB : public xiso::BaseModule
{
public:
    ModuleB(){};
    ~ModuleB(){};

public:
    bool init(const std::string &config_path) override
    {
        return true;
    }

    void start() override
    {
        LOG(INFO) << "ModuleB startOperator";
    }

    void stop() override
    {
        LOG(WARNING) << "ModuleB stopOperator";
    }
};

MODULE_REGISTER_FACTORY(ModuleB, "ModuleB");