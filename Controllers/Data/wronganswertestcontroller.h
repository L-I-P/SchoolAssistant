#pragma once
#include <QList>
#include <QtSql/QSqlQuery>
#include "Models/wronganswertest.h"

class WrongAnswerTestController
{
public:
    WrongAnswerTestController();
    QList<QString> getWrongAnswer(int Question);
private:
    void setWrongAnswerTest();
private:
    QList<WrongAnswerTest> wrongAnswerTestlist;
};
