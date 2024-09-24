#include "Application.h"
#include "ModuleA.h"
#include "ModuleB.h"
#include "ModuleC.h"
#include "ModuleFactory.h"

#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

int main(int argc, char *argv[])
{
    google_glog_initialize(".", argv[0]);

    Application *framework = new Application();

    framework->init(".");
    framework->start();

    for (int i = 0; i < 1; i++) {
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    framework->stop();
    delete framework;

    return 0;
}
