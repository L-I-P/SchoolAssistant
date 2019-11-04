#pragma once
#include <QObject>

class CountingAnswersTestController
{
public:
    CountingAnswersTestController();
    int getCorrectAnswer();
    int getWrongAnswer();
    void increaseCorrectAnswer();
    void increaseWrongAnswer();
private:
    int CorrectAnswer;
    int WrongAnswer;
};
