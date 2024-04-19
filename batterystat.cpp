#include "batterystat.h"

BatteryStatus::BatteryStatus() {
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