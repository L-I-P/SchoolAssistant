#pragma once
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include "nametestcontroller.h"
#include "questiontestcontroller.h"
#include "wronganswertestcontroller.h"
class ContextDb
{
public:
    ContextDb();
    NameTestController& getNameTestController();
    QuestionTestController& getQuestionTestController();
    WrongAnswerTestController& getWrongAnswerTestController();
private:
    void connectToDataBase();
    void initialization();
    void closeDataBase();
private:
    QSqlDatabase db;
    NameTestController* nameTestController;
    QuestionTestController* questionTestController;
    WrongAnswerTestController* wrongAnswerTestController;
};
