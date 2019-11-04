#include "wronganswertestcontroller.h"

WrongAnswerTestController::WrongAnswerTestController()
{
    setWrongAnswerTest();
}

void WrongAnswerTestController::setWrongAnswerTest()
{
        QSqlQuery query; query.exec("SELECT Id, Question, WrongAnswer from WrongAnswerTest");
        while (query.next())
        {
            WrongAnswerTest wrongAnswerTest;
            wrongAnswerTest.setId(query.value(0).toInt());
            wrongAnswerTest.setQuestion(query.value(1).toInt());
            wrongAnswerTest.setWrongAnswer(query.value(2).toString());
            wrongAnswerTestlist.append(wrongAnswerTest);
        }
        /*for(auto element: wrongAnswerTestlist)
        {
            qDebug() << element.getId();
            qDebug() << element.getQuestion();
            qDebug() << element.getWrongAnswer();
        }*/
}

QList<QString> WrongAnswerTestController::getWrongAnswer(int Question)
{
    QList<QString> wrongAnswer;
    for(auto element : wrongAnswerTestlist)
    {
        if(Question == element.getQuestion())
        {
            wrongAnswer.append(element.getWrongAnswer());
        }
    }
    return wrongAnswer;
}
