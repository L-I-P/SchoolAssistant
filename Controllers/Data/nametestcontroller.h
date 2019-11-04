#pragma once
#include <QList>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include "Models/nametest.h"

class NameTestController
{
public:
    NameTestController();
    int getNumberTest(QString name);
    QList<QString> getNameTest();
    QString getConditionTest(QString name);
private:
    void setNameTest();
private:
    QList<NameTest> nameTestlist;

};
