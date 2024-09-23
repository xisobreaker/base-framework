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
    void startOperator() override
    {
        LOG(INFO) << "ModuleA startOperator";
    }

    void stopOperator() override
    {
        LOG(WARNING) << "ModuleA stopOperator";
    }
};

MODULE_REGISTER_FACTORY(ModuleA);