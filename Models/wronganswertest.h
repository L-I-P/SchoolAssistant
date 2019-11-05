#pragma once
#include <QString>
class WrongAnswerTest
{
public:
    explicit WrongAnswerTest();
    void setId(int _Id);
    void setQuestion(int _Question);
    void setWrongAnswer(QString _WrongAnswer);
    int getId();
    int getQuestion();
    QString getWrongAnswer();
private:
    int Id;
    int Question;
    QString WrongAnswer;
};
