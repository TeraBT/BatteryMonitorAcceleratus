#ifndef PRAETOR_SYSTEMATIS_BATTERYSTAT_H
#define PRAETOR_SYSTEMATIS_BATTERYSTAT_H

#include <windows.h>


class BatteryStatus {
    SYSTEM_POWER_STATUS powerStatus{};

    void update();

public:
    BatteryStatus();
    int getBatteryLevel();
    bool isCharging();
};


#endif