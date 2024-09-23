#pragma once

#include "BaseModule.h"
#include "GoogleGlog.h"

#include <iostream>

class ModuleB : public BaseModule
{
public:
    ModuleB(){};
    ~ModuleB(){};

public:
    void startOperator() override
    {
        LOG(INFO) << "ModuleB startOperator";
    }

    void stopOperator() override
    {
        LOG(WARNING) << "ModuleB stopOperator";
    }
};