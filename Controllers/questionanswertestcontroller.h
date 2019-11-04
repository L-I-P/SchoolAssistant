#pragma once
#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include "Controllers/Data/contextdb.h"
#include "Controllers/countinganswerstestcontroller.h"
#include "Controllers/timercontroller.h"
#include "Views/questionanswerview.h"
#include "Views/pushbutton.h"

class QuestionAnswerTestController : public QObject
{
    Q_OBJECT
public:
    QuestionAnswerTestController(ContextDb& _contextDb, int _NumberTest);
    void exec();
public slots:
    void UpdateDateTime();
    void UpdateQuestion();
    void checkResponse();
private:
    void InitializationWindow();
    int getRandomNumber();
    void InitializationListQuestion();
    void InitializationAnswer();
private:
    ContextDb contextDb;
    QuestionAnswerView * questionAnswerView;
    TimerController * timerController;
    CountingAnswersTestController * countingAnswersTestController;

    int NumberQuestion = 1;
    int NumberTest;

    QList<QString> question;
    QList<QString> answer;

    QList<PushButton*> listPushButtonAnswer;
};
