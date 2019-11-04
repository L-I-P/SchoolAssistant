#include "questiontest.h"

QuestionTest::QuestionTest()
{

}

int QuestionTest::getId()
{
    return Id;
}

int QuestionTest::getNumberTest()
{
    return NumberTest;
}

QString QuestionTest::getQuestion()
{
    return Question;
}

QString QuestionTest::getCorrectAnswer()
{
    return CorrectAnswer;
}

void QuestionTest::setId(int _Id)
{
    Id = _Id;
}

void QuestionTest::setNumberTest(int _NumberTest)
{
    NumberTest = _NumberTest;
}

void QuestionTest::setQuestion(QString _Question)
{
    Question = _Question;
}

void QuestionTest::setCorrectAnswer(QString _CorrectAnswer)
{
    CorrectAnswer = _CorrectAnswer;
}

