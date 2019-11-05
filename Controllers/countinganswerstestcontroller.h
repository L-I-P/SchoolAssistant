#pragma once

class CountingAnswersTestController
{
public:
    explicit CountingAnswersTestController();
    int getCorrectAnswer();
    int getWrongAnswer();
    void increaseCorrectAnswer();
    void increaseWrongAnswer();
private:
    int CorrectAnswer;
    int WrongAnswer;
};
