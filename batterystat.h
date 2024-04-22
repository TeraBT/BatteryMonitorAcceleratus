#ifndef PRAETOR_SYSTEMATIS_BATTERYSTAT_H
#define PRAETOR_SYSTEMATIS_BATTERYSTAT_H

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>

class BatteryStatus {
    SYSTEM_POWER_STATUS powerStatus{};

    virtual void update();

public:
    BatteryStatus();

    int getBatteryLevel();

    bool isCharging();
};

#elif defined(__linux__)

#else
//todo
#endif

#endif
