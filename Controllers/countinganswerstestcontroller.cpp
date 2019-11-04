#include "countinganswerstestcontroller.h"

CountingAnswersTestController::CountingAnswersTestController()
{
    CorrectAnswer = 0;
    WrongAnswer = 0;
}

int CountingAnswersTestController::getCorrectAnswer()
{
    return CorrectAnswer;
}
int CountingAnswersTestController::getWrongAnswer()
{
    return WrongAnswer;
}

void CountingAnswersTestController::increaseCorrectAnswer()
{
    CorrectAnswer++;
}
void CountingAnswersTestController::increaseWrongAnswer()
{
    WrongAnswer++;
}
