#include "timercontroller.h"

TimerController::TimerController()
{
    QTimer* ptimer = new QTimer;
    ptimer->start(1000);
    connect(ptimer, SIGNAL(timeout()), SLOT(UpdateDateTime()));
    initializationTime();
    timeout();
}

void TimerController::initializationTime()
{
    timeMinSec = QTime(0,10,0);
}

void TimerController::UpdateDateTime()
{
    timeMinSec = timeMinSec.addSecs(-1);
    timeout();
}

QTime TimerController::getTimer()
{
    return timeMinSec;
}

