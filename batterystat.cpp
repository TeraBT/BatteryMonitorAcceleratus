#include "batterystat.h"


#if defined(_WIN32) || defined(_WIN64)

BatteryStatus::BatteryStatus() : powerStatus() {
    update();
}

void BatteryStatus::update() {
    GetSystemPowerStatus(&powerStatus);
}

int BatteryStatus::getBatteryLevel() {
    update();
    return static_cast<int>(powerStatus.BatteryLifePercent);
}

bool BatteryStatus::isCharging() {
    update();
    return (powerStatus.BatteryFlag == 8);
}
#elif defined(__linux__)
// todo

#else
// todo
#endif

