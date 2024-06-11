#ifndef NOTIFICATION_WINDOW_H
#define NOTIFICATION_WINDOW_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include "BatteryStatus.h"
#include "MemoryStatus.h"

class QPushButton;

class QLabel;

class QVBoxLayout;

class QTimer;

class NotificationWindow : public QWidget {
Q_OBJECT  // This macro enables the use of Qt's meta-object system for signals and slots

public:
    explicit NotificationWindow(QWidget *parent = nullptr);

private:
    QLabel statusLabel;
    QPushButton okButton;
    QPushButton pauseButton;
    QPushButton terminateButton;
    QVBoxLayout layout;
    QTimer timer;

    BatteryStatus batteryStatus;
//    MemoryStatus memoryStatus;

protected:
    void closeEvent(QCloseEvent *event) override;

    void toggleVisibility();

private slots:

    void updateWindow();

    void okButtonClicked();

    void pauseButtonClicked();

    static void terminateButtonClicked();

};

#endif
