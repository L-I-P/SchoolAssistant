#pragma once
#include <QObject>

class CountingAnswersTestController : public QObject
{
    Q_OBJECT
public:
    explicit CountingAnswersTestController();
    int getCorrectAnswer();
    int getWrongAnswer();
public slots:
    void increaseCorrectAnswer();
    void increaseWrongAnswer();
private:
    int CorrectAnswer;
    int WrongAnswer;
};
