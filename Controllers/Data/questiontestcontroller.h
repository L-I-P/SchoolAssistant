#pragma once
#include <QList>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include "Models/questiontest.h"

class QuestionTestController
{
public:
    QuestionTestController();
    QList<QString> getQuestionTest(int NumberTest);
    int getId(QString question);
    QString getCorrectAnswer(int Id);
private:
    void setQuestionTest();
private:
    QList<QuestionTest> questionTestlist;
};
