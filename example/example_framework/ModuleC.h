#pragma once

#include "BaseModule.h"
#include "GoogleGlog.h"
#include "ModuleFactory.h"

#include <iostream>

class ModuleC : public BaseModule
{
public:
    ModuleC(){};
    ~ModuleC(){};

public:
    bool init(const std::string &config_path) override
    {
        return true;
    }

    void start() override
    {
        LOG(INFO) << "ModuleC startOperator";
    }

    void stop() override
    {
        LOG(WARNING) << "ModuleC stopOperator";
    }
};

MODULE_REGISTER_FACTORY(ModuleC, "ModuleC");
