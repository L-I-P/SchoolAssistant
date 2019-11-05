#pragma once
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include "nametestcontroller.h"
#include "questiontestcontroller.h"
#include "wronganswertestcontroller.h"
class ContextDb
{
public:
    explicit ContextDb();
    ~ContextDb();
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
