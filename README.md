# xiso-framework

## 第三方库版本需求

1. glog 0.7.1
2. protobuf 3.17.3



```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
 
std::vector<std::string> split(const std::string &s) {
    std::vector<std::string> result;
    std::istringstream iss(s);
    std::string token;
    while (iss >> token) {
        result.push_back(token);
    }
    return result;
}
 
std::pair<unsigned long, unsigned long> get_cpu_times() {
    std::ifstream file("/proc/stat");
    std::string line;
    std::getline(file, line);
    auto parts = split(line);
    if (parts.empty() || parts[0] != "cpu") {
        throw std::runtime_error("Unexpected /proc/stat format");
    }
    unsigned long total = 0, idle = 0;
    for (size_t i = 1; i < parts.size(); ++i) {
        try {
            total += std::stoul(parts[i]);
            if (i == 4) {
                idle = std::stoul(parts[i]);
            }
        } catch (const std::invalid_argument &e) {
            // Skip non-numeric fields
        }
    }
    return {total, idle};
}
 
int main() {
    auto start = get_cpu_times();
    // Do some work here
    // ...
    auto end = get_cpu_times();
 
    unsigned long total_diff = end.first - start.first;
    unsigned long idle_diff = end.second - start.second;
    double cpu_usage = (total_diff - idle_diff) * 100.0 / total_diff;
 
    std::cout << "CPU Usage: " << cpu_usage << "%" << std::endl;
    return 0;
}
```