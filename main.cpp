#include <iostream>
#include "batterystat.h"

#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#define SLEEP(ms) Sleep(ms * 1000)

#elif defined(__linux__)

#include <unistd.h>

#define SLEEP(ms) sleep(ms)
#else

#endif


int main(int argc, char *argv[]) {


    int batteryLevel;
    bool isCharging;
    BatteryStatus batteryStatus;

    while (true) {
        isCharging = batteryStatus.isCharging();
        batteryLevel = batteryStatus.getBatteryLevel();

        if (isCharging && batteryLevel >= 80) {
            std::cout << "Battery level too high: " << batteryLevel << "%\n";

        } else if (!isCharging && batteryLevel <= 20) {
            std::cout << "Battery level too low: " << batteryLevel << "%\n";
        } else {
            std::cout << "Battery level optimal: " << batteryLevel << "%. Charging: "
                      << (isCharging == 1 ? "Yes" : "No") << ".\n";
        }

        SLEEP(2);
    }


    return EXIT_SUCCESS;
}