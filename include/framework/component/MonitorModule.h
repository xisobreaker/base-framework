#pragma once

#include "BaseModule.h"
#include "Scheduled.h"

#include <memory>
#include <thread>

namespace xiso {

struct MEM_OCCUPY {
    unsigned long MemTotal;
    unsigned long MemFree;
    unsigned long MemAvailable;
    unsigned long Buffers;
    unsigned long Cached;
    unsigned long SwapCached;
};

struct CPU_OCCUPY {
    char          name[64];
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
};

class MonitorModule : public BaseModule
{
public:
    MonitorModule();
    ~MonitorModule();

public:
    bool init(const std::string &config_path);
    void start();
    void stop();

private:
    bool getMemOccupy(MEM_OCCUPY *mem_occupy);
    bool getCpuOccupy(CPU_OCCUPY *cpu_occupy);

private:
    std::unique_ptr<Scheduled> m_scheduled;
};

} // namespace xiso
