#pragma once

#include "BaseModule.h"

#include <iostream>

class ModuleB : public BaseModule
{
public:
    ModuleB(){};
    ~ModuleB(){};

public:
    void startOperator() override
    {
        std::cout << "ModuleB startOperator" << std::endl;
    }

    void stopOperator() override
    {
        std::cout << "ModuleB stopOperator" << std::endl;
    }
};