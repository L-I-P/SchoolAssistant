#pragma once
#include <QList>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include "Models/nametest.h"

class NameTestController
{
public:
    explicit NameTestController();
    int getNumberTest(QString name);
    QList<QString> getNameTest();
    QString getConditionTest(QString name);
private:
    void setNameTest();
private:
    QList<NameTest> nameTestlist;

};
