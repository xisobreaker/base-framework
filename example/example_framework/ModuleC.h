#pragma once

#include "BaseModule.h"
#include "GoogleGlog.h"

#include <iostream>

class ModuleC : public BaseModule
{
public:
    ModuleC(){};
    ~ModuleC(){};

public:
    void startOperator() override
    {
        LOG(INFO) << "ModuleC startOperator";
    }

    void stopOperator() override
    {
        LOG(WARNING) << "ModuleC stopOperator";
    }
};