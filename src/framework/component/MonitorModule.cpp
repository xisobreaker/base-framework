#include "MonitorModule.h"

#include "GoogleGlog.h"
#include "Scheduled.h"

#include <cstdio>
#include <fstream>
#include <memory>
#include <unordered_map>

namespace xiso {

MonitorModule::MonitorModule()
{
}

MonitorModule::~MonitorModule()
{
}

bool MonitorModule::init(const std::string &config_path)
{
    return true;
}

void MonitorModule::start()
{
    m_scheduled = std::make_unique<Scheduled>();
    m_scheduled->addTask(
        [&]() {
            auto mem_occupy = std::make_shared<MEM_OCCUPY>();
            if (getMemOccupy(mem_occupy.get())) {
                LOG(INFO) << "Total Memory: " << mem_occupy->MemTotal / 1000.0
                          << ", Available Memory: " << mem_occupy->MemAvailable / 1000.0;
            }

            auto cpu_occupy = std::make_shared<CPU_OCCUPY>();
            if (getCpuOccupy(cpu_occupy.get())) {
                LOG(INFO) << "Name: " << cpu_occupy->name << ", user: " << cpu_occupy->user << ", sys: " << cpu_occupy->system;
            }
        },
        std::chrono::milliseconds(100),
        true);
}

void MonitorModule::stop()
{
    m_scheduled = nullptr;
}

bool MonitorModule::getMemOccupy(MEM_OCCUPY *mem_occupy)
{
    std::unordered_map<std::string, unsigned int> meminfo_map;

    // 打开内存信息文件
    std::ifstream meminfo("/proc/meminfo");
    if (!meminfo.is_open()) {
        LOG(ERROR) << "Check Meminfo Failed: can't open /proc/meminfo";
        return false;
    }

    std::string line;
    while (getline(meminfo, line)) {
        std::istringstream iss_line(line);

        std::string  key, unit;
        unsigned int value;
        iss_line >> key >> value >> unit;
        meminfo_map[key] = value;
    }
    meminfo.close();

    mem_occupy->MemTotal     = meminfo_map["MemTotal:"];
    mem_occupy->MemFree      = meminfo_map["MemFree:"];
    mem_occupy->MemAvailable = meminfo_map["MemAvailable:"];
    mem_occupy->Buffers      = meminfo_map["Buffers:"];
    mem_occupy->Cached       = meminfo_map["Cached:"];
    mem_occupy->SwapCached   = meminfo_map["SwapCached:"];
    return true;
}

bool MonitorModule::getCpuOccupy(CPU_OCCUPY *cpu_occupy)
{
    std::ifstream cpustat("/proc/stat");
    if (!cpustat.is_open()) {
        LOG(ERROR) << "Check CPUTime Failed: can't open /proc/stat";
        return false;
    }

    std::string line;
    getline(cpustat, line);
    sscanf(
        line.c_str(), "%s %ld %ld %ld %ld", cpu_occupy->name, &cpu_occupy->user, &cpu_occupy->nice, &cpu_occupy->system, &cpu_occupy->idle);
    cpustat.close();
    return true;
}

} // namespace xiso
