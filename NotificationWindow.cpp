#include "NotificationWindow.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QCloseEvent>

#ifdef _WIN32

#include <windows.h>

#define SLEEP(seconds) Sleep(seconds*1000)
#else
#include <unistd.h>
#define SLEEP(seconds) sleep(seconds)
#endif


NotificationWindow::NotificationWindow(QWidget *parent)
        : QWidget(parent),
          statusLabel(this),
          okButton("Understood.", this),
          pauseButton("Pause for 20 min.", this),
          terminateButton("Stop for this session.", this),
          layout(this),
          timer(this)
//    uptimeLabel = QLabel("Uptime: ", this); //TODO: Implement uptime
{
    statusLabel.setStyleSheet("padding: 20px; font-size: 20px; font-weight: bold;");

    okButton.setStyleSheet("padding: 5px; font-size: 16px;");
    pauseButton.setStyleSheet("padding: 5px; font-size: 16px;");
    terminateButton.setStyleSheet("padding: 5px; font-size: 16px;");

    layout.addWidget(&statusLabel);
    layout.addWidget(&okButton);
    layout.addWidget(&pauseButton);
    layout.addWidget(&terminateButton);

    connect(&okButton, &QPushButton::clicked, this, &NotificationWindow::okButtonClicked);
    connect(&pauseButton, &QPushButton::clicked, this, &NotificationWindow::pauseButtonClicked);
    connect(&terminateButton, &QPushButton::clicked, this, &NotificationWindow::terminateButtonClicked);

    timer.setInterval(60000);
    connect(&timer, &QTimer::timeout, this, &NotificationWindow::updateWindow);
    timer.start();
    updateWindow();
}

void NotificationWindow::okButtonClicked() {
    timer.stop();
    hide();
    SLEEP(60);
    timer.start();
}

void NotificationWindow::pauseButtonClicked() {
    timer.stop();
    hide();
    SLEEP(20 * 60);
    timer.start();
}

void NotificationWindow::terminateButtonClicked() {
    exit(EXIT_SUCCESS);
}


//void NotificationWindow::updateState() {
//// TODO
//}

void NotificationWindow::updateWindow() {
    if (batteryStatus.isCharging() && batteryStatus.getBatteryLevel() >= 80) {
        statusLabel.setText(QString("Battery level too high: %1%").arg(batteryStatus.getBatteryLevel()));
        toggleVisibility();
    } else if (!batteryStatus.isCharging() && batteryStatus.getBatteryLevel() <= 20) {
        statusLabel.setText(QString("Battery level too low: %1%").arg(batteryStatus.getBatteryLevel()));
        toggleVisibility();
    } else {
        hide();
    }
}

void NotificationWindow::toggleVisibility() {
    isVisible() ? hide() : show();
}

void NotificationWindow::closeEvent(QCloseEvent *event) {
    event->ignore();
    hide();
}