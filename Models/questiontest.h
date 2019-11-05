#pragma once
#include <QString>

class QuestionTest
{
public:
    explicit QuestionTest();
    void setId(int _Id);
    void setNumberTest(int _NumberTest);
    void setQuestion(QString _Question);
    void setCorrectAnswer(QString _CorrectAnswer);
    int getId();
    int getNumberTest();
    QString getQuestion();
    QString getCorrectAnswer();
private:
    int Id;
    int NumberTest;
    QString Question;
    QString CorrectAnswer;
};
