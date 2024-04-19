#include <iostream>
#include <Windows.h>
#include "batterystat.h"

int main(int argc, char *argv[]) {

    BatteryStatus batteryStatus;

    bool isCharging;
    int batteryLevel;

    isCharging = batteryStatus.isCharging();
    batteryLevel = batteryStatus.getBatteryLevel();

    if (isCharging && batteryLevel >= 80) {
        std::cout << "Accumulātōris vis satis magna: " << batteryLevel << '%' << std::endl;


    } else if (!isCharging && batteryLevel <= 20) {
        std::cout << "Accumulātōris vis satis parva: " << batteryLevel << '%' << std::endl;
    } else {
        std::cout << "Normal Battery State: " << batteryLevel << '%' << std::endl;;
    }

    Sleep(3000);

    return EXIT_SUCCESS;
}