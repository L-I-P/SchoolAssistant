#pragma once
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include "Views/conditiontestview.h"

class ConditionTestController : public QObject
{
public:
    explicit ConditionTestController(QString condition);
    ~ConditionTestController();
private:
    ConditionTestView *conditionTestView;
};
