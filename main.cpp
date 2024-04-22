#include <iostream>
#include <Windows.h>
#include <format>

#include "batterystat.h"

int main(int argc, char *argv[]) {

    BatteryStatus batteryStatus;

    bool isCharging;
    int batteryLevel;

    while(true) {
        isCharging = batteryStatus.isCharging();
        batteryLevel = batteryStatus.getBatteryLevel();

        if (isCharging && batteryLevel >= 80) {
            std::cout << std::format("Accumulātōris vis satis magna: {}%\n", batteryLevel);

        } else if (!isCharging && batteryLevel <= 20) {
            std::cout << std::format("Accumulātōris vis satis parva: {}%\n", batteryLevel);
        } else {
            std::cout << std::format("Normal battery state: {}%\n", batteryLevel);
        }

        Sleep(1000);
    }


    return EXIT_SUCCESS;
}