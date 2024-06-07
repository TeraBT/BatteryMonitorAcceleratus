#include "NotificationWindow.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>

NotificationWindow::NotificationWindow() {
    statusLabel = new QLabel("", this);
//    uptimeLabel = new QLabel("Uptime: ", this); //TODO: Implement uptime
    statusLabel->setAlignment(Qt::AlignCenter);
    statusLabel->setStyleSheet("padding: 20px; font-size: 20px; font-weight: bold;");

    okButton = new QPushButton("Understood.", this);
    pauseButton = new QPushButton("Pause for 20 min.", this);
    terminateButton = new QPushButton("Stop for this session.", this);

    okButton->setStyleSheet("padding: 5px; font-size: 16px;");
    pauseButton->setStyleSheet("padding: 5px; font-size: 16px;");
    terminateButton->setStyleSheet("padding: 5px; font-size: 16px;");


    layout = new QVBoxLayout(this);
    layout->addWidget(statusLabel);
    layout->addWidget(okButton);
    layout->addWidget(pauseButton);
    layout->addWidget(terminateButton);

    connect(okButton, &QPushButton::clicked, this, &NotificationWindow::okButtonClicked);
    connect(pauseButton, &QPushButton::clicked, this, &NotificationWindow::pauseButtonClicked);
    connect(terminateButton, &QPushButton::clicked, this, &NotificationWindow::terminateButtonClicked);

    timer = new QTimer(this);
    timer->setInterval(60000);
    connect(timer, &QTimer::timeout, this, &NotificationWindow::updateWindow);
    timer->start();
    updateWindow();
}

void NotificationWindow::okButtonClicked() {
    timer->stop();
    hide();
    sleep(60);
    timer->start();
}

void NotificationWindow::pauseButtonClicked() {
    timer->stop();
    hide();
    sleep(20*60);
    timer->start();
}

void NotificationWindow::terminateButtonClicked() {
    exit(EXIT_SUCCESS);
}


//void NotificationWindow::updateState() {
//// TODO
//}

void NotificationWindow::updateWindow() {
    if (batteryStatus->isCharging() && batteryStatus->getBatteryLevel() >= 80) {
            statusLabel->setText(QString("Battery level too high: %1%").arg(batteryStatus->getBatteryLevel()));
            toggleVisibility();
    } else if (!batteryStatus->isCharging() && batteryStatus->getBatteryLevel() <= 20) {
            statusLabel->setText(QString("Battery level too low: %1%").arg(batteryStatus->getBatteryLevel()));
            toggleVisibility();
    } else {
        hide();
    }
}

void NotificationWindow::toggleVisibility() {
    isVisible() ? hide() : show();
}
