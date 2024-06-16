#include "MemoryStatus.h"


#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>

struct MemoryStatus::Impl {
    SYSTEM_POWER_STATUS powerStatus;

    void update() {
        GetSystemPowerStatus(&powerStatus);
    }
};

int MemoryStatus::getBatteryLevel() {
    pImpl->update();
    return static_cast<int>(pImpl->powerStatus.BatteryLifePercent);
}

bool MemoryStatus::isCharging() {
    pImpl->update();
    return (pImpl->powerStatus.BatteryFlag & 8) != 0;
}


#elif defined(__linux__)

#include <fstream>
#include <sstream>

struct MemoryStatus::Impl {
    float totalMemory;
    float availableMemory;

    void update() {
        std::ifstream meminfoFile("/proc/meminfo");

        if (meminfoFile.is_open()) {
            std::string line;
            std::string description;
            int value;

            for (int i = 0; i < 3; ++i) {

                std::getline(meminfoFile, line);
                std::istringstream iss(line);

                switch (i) {
                    case 0:
                        iss >> description >> value;
                        totalMemory = float(value) / 1e6f;
                        break;
                    case 2:
                        iss >> description >> value;
                        availableMemory = float(value) / 1e6f;
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
