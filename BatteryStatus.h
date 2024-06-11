#ifndef PRAETOR_SYSTEMATIS_BATTERYSTAT_H
#define PRAETOR_SYSTEMATIS_BATTERYSTAT_H

#include <memory>

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>

#endif

class BatteryStatus {
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    BatteryStatus();
    ~BatteryStatus();
    BatteryStatus(const BatteryStatus &) = delete;
    BatteryStatus &operator=(const BatteryStatus &) = delete;

    void update();

    int getBatteryLevel();

    bool isCharging();
};

#endif
