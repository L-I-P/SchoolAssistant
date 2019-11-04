#pragma once
#include <QString>
class NameTest
{
public:
    NameTest();
    void setNumberTest(int _NumberTest);
    void setName(QString _Name);
    void setConditionTest(QString _ConditionTest);
    int getNumberTest();
    QString getName();
    QString getConditionTest();
private:
    int NumberTest;
    QString Name;
    QString ConditionTest;
};
