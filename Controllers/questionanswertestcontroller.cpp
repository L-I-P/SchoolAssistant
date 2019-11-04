#include "questionanswertestcontroller.h"

QuestionAnswerTestController::QuestionAnswerTestController(ContextDb& _contextDb, int _NumberTest) : contextDb(_contextDb), NumberTest(_NumberTest)
{
    questionAnswerView = new QuestionAnswerView;
    countingAnswersTestController = new CountingAnswersTestController;
    InitializationWindow();
    questionAnswerView->show();
}

void QuestionAnswerTestController::exec()
{
    questionAnswerView->exec();
    int correctAnswer = countingAnswersTestController->getCorrectAnswer();
    int wrongAnswer = countingAnswersTestController->getWrongAnswer();
    QMessageBox::information(nullptr, "Результат",
    "Количество правильных ответов " + QString::number(correctAnswer) + " из " +
                             QString::number(wrongAnswer + correctAnswer)
                             + ".\nПроцент верных ответов: " + QString::number(100*(correctAnswer) / (wrongAnswer + correctAnswer)) + "%");
}

void QuestionAnswerTestController::InitializationWindow()
{
    timerController = new TimerController;
    connect(timerController, SIGNAL(timeout()), SLOT(UpdateDateTime()));
    UpdateDateTime();


    connect(&questionAnswerView->getNextQuestion(), SIGNAL(clicked()), SLOT(UpdateQuestion()));

    connect(&questionAnswerView->getExitTest(), SIGNAL(clicked()), questionAnswerView, SLOT(close()));
    UpdateQuestion();
}

void QuestionAnswerTestController::UpdateDateTime()
{
    questionAnswerView->getLabelTimer().setText("<H3><CENTER>Осталось до конца:  " + timerController->getTimer().toString("mm:ss") + "</CENTER></H3>");
    if(timerController->getTimer() == QTime(0,0,0))
    {
        questionAnswerView->close();
    }
}

void QuestionAnswerTestController::UpdateQuestion()
{
    questionAnswerView->setWindowTitle("Вопрос №" + QString::number(NumberQuestion++));
    if(question.isEmpty())
    {
        InitializationListQuestion();
    }
    InitializationAnswer();
    questionAnswerView->getQuestion().setText(question.first());

    if(contextDb.getQuestionTestController().getCorrectAnswer(contextDb.getQuestionTestController().getId(question.first())) != "")
    {
        while(answer.size() > listPushButtonAnswer.size())
        {
            PushButton * qpb = new PushButton;
            connect(qpb, SIGNAL(clicked()), this, SLOT(checkResponse()));
            //qpb->setMinimumSizeHeight();
            questionAnswerView->getQalayout().addWidget(qpb);
            listPushButtonAnswer.append(qpb);
            qpb->setToolTip("Выберите ответ,\nкоторый считаете правильным.");
        }
        while(answer.size() < listPushButtonAnswer.size())
        {
            delete listPushButtonAnswer.takeLast();
        }
        if(answer.size() == listPushButtonAnswer.size())
        {
            for(int i = 0; i < listPushButtonAnswer.size(); i++)
            {
                listPushButtonAnswer[i]->setText(answer.takeFirst());
                listPushButtonAnswer[i]->setMinimumSizeHeight();
                listPushButtonAnswer[i]->setEnabled(true);
                listPushButtonAnswer[i]->setStyleSheet("background-color: lightgray;");
            }
        }
        questionAnswerView->getNextQuestion().setEnabled(false);
        questionAnswerView->getExitTest().setEnabled(false);
    }
}

void QuestionAnswerTestController::checkResponse()
{
    if(contextDb.getQuestionTestController().getCorrectAnswer(contextDb.getQuestionTestController().getId(question.first())) == ((PushButton*)sender())->text())
    {
        countingAnswersTestController->increaseCorrectAnswer();
        ((PushButton*)sender())->setStyleSheet("background-color: lightgreen");
    }
    else
    {
        countingAnswersTestController->increaseWrongAnswer();
        ((PushButton*)sender())->setStyleSheet("background-color: red");
        for(int i = 0; i < listPushButtonAnswer.size(); i++)
        {
            if(listPushButtonAnswer[i]->text() == contextDb.getQuestionTestController().getCorrectAnswer(contextDb.getQuestionTestController().getId(question.first())))
            {
                listPushButtonAnswer[i]->setStyleSheet("background-color: lightgreen");
            }
        }
    }
    for(int i = 0; i < listPushButtonAnswer.size(); i++)
    {
        listPushButtonAnswer[i]->setEnabled(false);
    }
    questionAnswerView->getNextQuestion().setEnabled(true);
    questionAnswerView->getExitTest().setEnabled(true);
    question.removeFirst();
}

void QuestionAnswerTestController::InitializationListQuestion()
{
    srand((unsigned int)time(nullptr));
    for(auto element : contextDb.getQuestionTestController().getQuestionTest(NumberTest))
    {
        if(rand()%2 == 0)
        {
            question.push_front(element);
        }
        else
        {
            question.push_back(element);
        }
    }
}

void QuestionAnswerTestController::InitializationAnswer()
{
    srand((unsigned int)time(nullptr));
    for(auto element : contextDb.getWrongAnswerTestController().getWrongAnswer(contextDb.getQuestionTestController().getId(question.first())))
    {
        if(rand()%2 == 0)
        {
            answer.push_front(element);
        }
        else
        {
            answer.push_back(element);
        }
    }
    answer.insert(rand()%answer.size()+rand()%2, contextDb.getQuestionTestController().getCorrectAnswer(contextDb.getQuestionTestController().getId(question.first())));
}
