#pragma once
#include "Controllers/conditiontestcontroller.h"
#include "Controllers/questionanswertestcontroller.h"
#include "Views/mainview.h"
#include "Data/contextdb.h"

class ApplicationController : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationController();
    ~ApplicationController();
public slots:
    void InitializationConditionTest();
private:
    void InitializationWindow();
    void StartPlay();
private:
    MainView *mainview;
    ContextDb * context;
};
