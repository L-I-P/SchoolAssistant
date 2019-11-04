#include "wronganswertest.h"

WrongAnswerTest::WrongAnswerTest()
{

}

int WrongAnswerTest::getId()
{
    return Id;
}

int WrongAnswerTest::getQuestion()
{
    return Question;
}

QString WrongAnswerTest::getWrongAnswer()
{
    return WrongAnswer;
}

void WrongAnswerTest::setId(int _Id)
{
    Id = _Id;
}

void WrongAnswerTest::setQuestion(int _Question)
{
    Question = _Question;
}

void WrongAnswerTest::setWrongAnswer(QString _WrongAnswer)
{
    WrongAnswer = _WrongAnswer;
}

