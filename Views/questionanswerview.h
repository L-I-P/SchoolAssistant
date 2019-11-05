#pragma once
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>

class QuestionAnswerView : public QDialog
{
public:
    explicit QuestionAnswerView();
    ~QuestionAnswerView();
    QVBoxLayout& getGlayout();
    QVBoxLayout& getQalayout();
    QLabel& getLabelTimer();
    QTextEdit& getQuestion();
    QPushButton& getNextQuestion();
    QPushButton& getExitTest();
private:
    QVBoxLayout * glayout;
    QVBoxLayout * qalayout;
    QLabel * labelTimer;
    QTextEdit * question;

    QPushButton * nextQuestion;
    QPushButton * exitTest;
};
