#include <iostream>
#include <vector>
#include <string>

#include "BatteryStatus.h"

#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#define SLEEP(ms) Sleep(ms * 1000)

#elif defined(__linux__)

#include <unistd.h>


#define SLEEP(ms) sleep(ms)
#else

#endif

//
//int main(int argc, char *argv[]) {
//
//    struct BatteryStatusRecord {
//        int batteryLevel = -1;
//        bool isCharging = false;
//    } batteryStatusRecord;
//    std::vector<BatteryStatusRecord> recordVector;
//
//    BatteryStatus batteryStatus;
//    int batteryLevel;
//    bool isCharging;
//
//    while (true) {
//        isCharging = batteryStatus.isCharging();
//        batteryLevel = batteryStatus.getBatteryLevel();
//
//        if (isCharging && batteryLevel >= 80) {
//            std::cout << "Battery level too high: " << batteryLevel << "%\n";
//
//        } else if (!isCharging && batteryLevel <= 20) {
//            std::cout << "Battery level too low: " << batteryLevel << "%\n";
//        } else {
//            std::cout << "Battery level optimal: " << batteryLevel << "%. Charging: "
//                      << (isCharging == 1 ? "Yes" : "No") << ".\n";
//        }
//
//        recordVector.push_back(BatteryStatusRecord(batteryLevel, isCharging));
////        std::cout << str(recordVector.begin(), recordVector.end());
//
//        SLEEP(2);
//    }
//
//
//    return EXIT_SUCCESS;
//}



#include <QApplication>
#include "NotificationWindow.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    const QString &msg = "Test";
    NotificationWindow window(msg);
    window.resize(200, 100);

    struct BatteryStatusRecord {
        int batteryLevel = -1;
        bool isCharging = false;
    } batteryStatusRecord;
    std::vector<BatteryStatusRecord> recordVector;

    BatteryStatus batteryStatus;
    int batteryLevel;
    bool isCharging;

//    while (true) {
//        isCharging = batteryStatus.isCharging();
//        batteryLevel = batteryStatus.getBatteryLevel();
//
//        if (isCharging && batteryLevel >= 80) {
//            std::cout << "Battery level too high: " << batteryLevel << "%\n";
//
//        } else if (!isCharging && batteryLevel <= 20) {
//            std::cout << "Battery level too low: " << batteryLevel << "%\n";
//        } else {
//            std::cout << "Battery level optimal: " << batteryLevel << "%. Charging: "
//                      << (isCharging == 1 ? "Yes" : "No") << ".\n";
//        }

//        recordVector.push_back(BatteryStatusRecord(batteryLevel, isCharging));
//        std::cout << str(recordVector.begin(), recordVector.end());
//}
//        while (true) {
//            window.show();
//            SLEEP(1);
//            window.close();
//        }
    window.show();

    return app.exec();


}