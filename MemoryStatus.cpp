#include "MemoryStatus.h"


#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>

//struct MemoryStatus::Impl {
//    SYSTEM_POWER_STATUS powerStatus;
//
//    void update() {
//        GetSystemPowerStatus(&powerStatus);
//    }
//};
//
//int MemoryStatus::getBatteryLevel() {
//    pImpl->update();
//    return static_cast<int>(pImpl->powerStatus.BatteryLifePercent);
//}
//
//bool MemoryStatus::isCharging() {
//    pImpl->update();
//    return (pImpl->powerStatus.BatteryFlag & 8) != 0;
//}
//

#elif defined(__linux__)

#include <fstream>
#include <string>
#include <sstream>

struct MemoryStatus::Impl {
    float totalMemory;
    float availableMemory;

    void update() {
        std::ifstream meminfoFile("/sys/proc/meminfo");

        if (meminfoFile.is_open()) {
            std::string line;
            std::istringstream iss;
            std::string key;
            int value;
            std::string unit;


            for (int i = 0; i < 3; ++i) {

                std::getline(meminfoFile, line);

                switch (i) {
                    case 0:
                        iss.str(line);
                        iss >> key >> value >> unit;
                        totalMemory = float(value) / 1000;
                        break;
                    case 2:
                        iss.str(line);
                        iss >> key >> value >> unit;
                        availableMemory = float(value) / 1000;
                        break;
                    default:
                        break;
                }
            }
        }
    };
};

#endif

void MemoryStatus::update() {
    pImpl->update();
}

float MemoryStatus::getTotalMemory() {
    return pImpl->totalMemory;
}

float MemoryStatus::getAvailableMemory() {
    return pImpl->availableMemory;
}

float MemoryStatus::getUsedMemory() {
    return pImpl->totalMemory - pImpl->availableMemory;
}

MemoryStatus::MemoryStatus() : pImpl(new Impl()) {
    pImpl->update();
}

MemoryStatus::~MemoryStatus() = default;
