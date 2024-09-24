#include "Application.h"
#include "ModuleA.h"
#include "ModuleB.h"
#include "ModuleC.h"
#include "ModuleFactory.h"

#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
using namespace std;

int main(int argc, char *argv[])
{
    xiso::google_glog_initialize(".", argv[0]);

    auto framework = std::make_shared<xiso::Application>();

    framework->init(".");
    framework->start();

    for (int i = 0; i < 10; i++) {
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    framework->stop();

    return 0;
}
