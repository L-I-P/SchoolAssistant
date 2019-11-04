#pragma once
#include <QObject>
#include <QTime>
#include <QTimer>

class TimerController : public QObject
{
    Q_OBJECT
public:
    explicit TimerController();
    QTime getTimer();
private:
    QTime timeMinSec;
    void initializationTime();
private slots:
    void UpdateDateTime();
signals:
    void timeout();
};
