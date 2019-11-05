#pragma once
#include <QList>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include "Models/questiontest.h"

class QuestionTestController
{
public:
    explicit QuestionTestController();
    QList<QString> getQuestionTest(int NumberTest);
    int getId(QString question);
    QString getCorrectAnswer(int Id);
private:
    void setQuestionTest();
private:
    QList<QuestionTest> questionTestlist;
};
