#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QString>
#include "BatteryStatus.h"

class QPushButton;

class QLabel;

class QVBoxLayout;

class QTimer;

class NotificationWindow : public QWidget {
Q_OBJECT  // This macro enables the use of Qt's meta-object system for signals and slots

public:
    explicit NotificationWindow(const QString &statusMessage);

private:
    QLabel *statusLabel;
    QPushButton *okButton;
    QPushButton *pauseButton;
    QPushButton *terminateButton;
    QVBoxLayout *layout;
    QTimer *timer;

    BatteryStatus *batteryStatus;

//    void updateState();


    void toggleVisibility();

private slots:
    void updateWindow();
    static void onButtonClicked();

};

#endif
