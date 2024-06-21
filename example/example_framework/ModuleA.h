#pragma once

#include "BaseModule.h"
#include "Component.h"

#include <iostream>

class ModuleA : public BaseModule
{
public:
    ModuleA(){};
    ~ModuleA(){};

public:
    void startOperator() override
    {
        std::cout << "ModuleA startOperator" << std::endl;
    }

    void stopOperator() override
    {
        std::cout << "ModuleA stopOperator" << std::endl;
    }
};