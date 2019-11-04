#include "nametest.h"

NameTest::NameTest()
{

}
int NameTest::getNumberTest()
{
    return NumberTest;
}

QString NameTest::getName()
{
    return Name;
}

QString NameTest::getConditionTest()
{
    return ConditionTest;
}

void NameTest::setNumberTest(int _NumberTest)
{
    NumberTest = _NumberTest;
}

void NameTest::setName(QString _Name)
{
    Name = _Name;
}

void NameTest::setConditionTest(QString _ConditionTest)
{
    ConditionTest = _ConditionTest;
}
