#include "Application.h"
#include "ModuleA.h"
#include "ModuleB.h"
#include "ModuleC.h"

#include <iostream>
using namespace std;

#include <glog/logging.h>

int main(int argc, char *argv[])
{
    Application *framework = new Application();
    BaseModule  *moduleA   = new ModuleA();
    BaseModule  *moduleB   = new ModuleB();
    BaseModule  *moduleC   = new ModuleC();

    // 添加子模块
    framework->addComponent(moduleA);
    framework->addComponent(moduleB);
    framework->addComponent(moduleC);

    // 启动子模块
    framework->startOperator();

    // 停止模块 B 并从  framework 内删除
    moduleB->stopOperator();
    delete moduleB;

    framework->stopOperator();

    delete framework;
    return 0;
}