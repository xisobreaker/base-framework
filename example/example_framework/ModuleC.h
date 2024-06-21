#pragma once

#include "BaseModule.h"

#include <iostream>

class ModuleC : public BaseModule
{
public:
    ModuleC(){};
    ~ModuleC(){};

public:
    void startOperator() override
    {
        std::cout << "ModuleC startOperator" << std::endl;
    }

    void stopOperator() override
    {
        std::cout << "ModuleC stopOperator" << std::endl;
    }
};