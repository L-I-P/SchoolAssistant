#include "nametestcontroller.h"

NameTestController::NameTestController()
{
    setNameTest();
}

int NameTestController::getNumberTest(QString name)
{
    int NumberTest;
    for(auto element : nameTestlist)
    {
        if(name == element.getName())
        {
            NumberTest = element.getNumberTest();
            return NumberTest;
        }
    }
    qDebug() << "Ошибка. Тест не найден.";
    exit(0);
}

void NameTestController::setNameTest()
{
        QSqlQuery query; query.exec("SELECT NumberTest, Name, ConditionTest from NameTest");
        while (query.next())
        {
            NameTest nameTest;
            nameTest.setNumberTest(query.value(0).toInt());
            nameTest.setName(query.value(1).toString());
            nameTest.setConditionTest(query.value(2).toString());
            nameTestlist.append(nameTest);
        }
        /*for(auto element: nameTestlist)
        {
            qDebug() << element.getNumberTest();
            qDebug() << element.getName();
            qDebug() << element.getConditionTest();
        }*/
}

QList<QString> NameTestController::getNameTest()
{
    QList<QString> nameTest;
    for(auto element : nameTestlist)
    {
        nameTest.append(element.getName());
    }
    return nameTest;
}

QString NameTestController::getConditionTest(QString name)
{
    QString conditionTest;
    for(auto element : nameTestlist)
    {
        if(name == element.getName())
        {
            conditionTest = element.getConditionTest();
            return conditionTest;
        }
    }
    if(conditionTest.isEmpty())
    {
       return "<H1><CENTER>Условия не найдены.</CENTER></H1>";
    }
}
