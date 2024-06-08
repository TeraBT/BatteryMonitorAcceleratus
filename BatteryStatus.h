#ifndef PRAETOR_SYSTEMATIS_BATTERYSTAT_H
#define PRAETOR_SYSTEMATIS_BATTERYSTAT_H

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <memory>

class BatteryStatus {
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    BatteryStatus();

    ~BatteryStatus();
    BatteryStatus(const BatteryStatus &) = delete; // Prevent copying
    BatteryStatus &operator=(const BatteryStatus &) = delete; // Prevent assignment

    int getBatteryLevel();
    bool isCharging();
};

#elif defined(__linux__)

#include <memory>

class BatteryStatus {
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    BatteryStatus();

    ~BatteryStatus();  // Needed to define a custom destructor
    BatteryStatus(const BatteryStatus &) = delete; // Prevent copying
    BatteryStatus &operator=(const BatteryStatus &) = delete; // Prevent assignment

    int getBatteryLevel();

    bool isCharging();
};

#else

#endif

#endif
