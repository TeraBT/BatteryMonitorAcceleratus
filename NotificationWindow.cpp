#include "NotificationWindow.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>

NotificationWindow::NotificationWindow(const QString &statusMessage) {
    statusLabel = new QLabel(statusMessage, this);
    statusLabel->setAlignment(Qt::AlignCenter);

    okButton = new QPushButton("Understood.", this);
    pauseButton = new QPushButton("Pause for 20 min.", this);
    terminateButton = new QPushButton("Stop for this session.", this);

    connect(okButton, &QPushButton::clicked, this, &NotificationWindow::onButtonClicked);

    layout = new QVBoxLayout(this);
    layout->addWidget(statusLabel);
    layout->addWidget(okButton);
    layout->addWidget(pauseButton);
    layout->addWidget(terminateButton);

    timer = new QTimer(this);
    timer->setInterval(3000);
    connect(timer, &QTimer::timeout, this, &NotificationWindow::toggleVisibility);
    timer->start();
}

void NotificationWindow::onButtonClicked() {
    auto *clickedLabel = new QLabel("Button Clicked!");
    clickedLabel->show();
}


void NotificationWindow::updateState() {
//TODO
}

void NotificationWindow::updateWindow() {
    //TODO
    statusLabel->setText("Lorem ipsum");
}

void NotificationWindow::toggleVisibility() {
    isVisible() ? hide() : show();
}
