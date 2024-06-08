#include <iostream>
#include <vector>
#include <string>

#include "BatteryStatus.h"

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>

#elif defined(__linux__)

#include <unistd.h>

#endif

#include <QApplication>
#include "NotificationWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    NotificationWindow notificationWindow;
    notificationWindow.resize(200, 100);

//    struct BatteryStatusRecord { // TODO: Implement this?
//        int batteryLevel = -1;
//        bool isCharging = false;
//    } batteryStatusRecord;
//    std::vector<BatteryStatusRecord> recordVector;

    return QApplication::exec();

}