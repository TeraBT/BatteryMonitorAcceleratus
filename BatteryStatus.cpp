#include "BatteryStatus.h"


#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>

struct BatteryStatus::Impl {
    SYSTEM_POWER_STATUS powerStatus;

    void update() {
        GetSystemPowerStatus(&powerStatus);
    }
};

BatteryStatus::BatteryStatus() : pImpl(new Impl()) {
    pImpl->update();
}

BatteryStatus::~BatteryStatus() = default;

int BatteryStatus::getBatteryLevel() {
    pImpl->update();
    return static_cast<int>(pImpl->powerStatus.BatteryLifePercent);
}

bool BatteryStatus::isCharging() {
    pImpl->update();
    return (pImpl->powerStatus.BatteryFlag & 8) != 0;
}


#elif defined(__linux__)

#include <fstream>
#include <string>

struct BatteryStatus::Impl {
    int batteryLevel;
    bool isCharging;

    void update() {
        std::ifstream capacityFile("/sys/class/power_supply/BAT0/capacity");
        std::ifstream statusFile("/sys/class/power_supply/BAT0/status");

        if (capacityFile.is_open()) {
            capacityFile >> batteryLevel;
        }

        if (statusFile.is_open()) {
            std::string status;
            statusFile >> status;
            isCharging = (status == "Charging");
        }
    }
};

BatteryStatus::BatteryStatus() : pImpl(new Impl()) {
    pImpl->update();
}

BatteryStatus::~BatteryStatus() = default;

int BatteryStatus::getBatteryLevel() {
    pImpl->update();
    return pImpl->batteryLevel;
}

bool BatteryStatus::isCharging() {
    pImpl->update();
    return pImpl->isCharging;
}


#else
// todo
#endif
