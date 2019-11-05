#include "questionanswertestcontroller.h"

QuestionAnswerTestController::QuestionAnswerTestController(ContextDb& _contextDb, int _NumberTest) : contextDb(_contextDb), NumberTest(_NumberTest)
{
    questionAnswerView = new QuestionAnswerView;
    countingAnswersTestController = new CountingAnswersTestController;
    InitializationWindow();
    questionAnswerView->show();
}

QuestionAnswerTestController::~QuestionAnswerTestController()
{
    delete questionAnswerView;
    delete timerController;
    delete countingAnswersTestController;

    listCheckLayoutAnswer.clear();
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
        while(answer.size() > listCheckLayoutAnswer.size())
        {
            CheckLayout * qpb = new CheckLayout;
            connect(&qpb->getCheckBox(), SIGNAL(clicked()), this, SLOT(checkResponse()));
            questionAnswerView->getQalayout().addLayout(qpb);
            listCheckLayoutAnswer.append(qpb);
            qpb->getCheckBox().setToolTip("Выберите ответ,\nкоторый считаете правильным.");
        }
        while(answer.size() < listCheckLayoutAnswer.size())
        {
            delete listCheckLayoutAnswer.takeLast();
        }
        if(!listCheckLayoutAnswer.isEmpty())
        {
        if(answer.size() == listCheckLayoutAnswer.size())
        {
            for(int i = 0; i < listCheckLayoutAnswer.size(); i++)
            {
                listCheckLayoutAnswer[i]->setText(answer.takeFirst());
                listCheckLayoutAnswer[i]->setMinimumSizeHeight();
                listCheckLayoutAnswer[i]->getCheckBox().setChecked(false);
                listCheckLayoutAnswer[i]->getCheckBox().setEnabled(true);
                listCheckLayoutAnswer[i]->getTextEdit().setStyleSheet("background-color: white;");
            }
        }
        questionAnswerView->getNextQuestion().setEnabled(false);
        questionAnswerView->getExitTest().setEnabled(false);
        }
        else
        {
            questionAnswerView->getNextQuestion().setEnabled(true);
            questionAnswerView->getExitTest().setEnabled(true);
        }
    }
}

void QuestionAnswerTestController::checkResponse()
{
    for(int i = 0; i < listCheckLayoutAnswer.size(); i++)
    {
        if(listCheckLayoutAnswer[i]->getCheckBox().isChecked())
        {
        if(contextDb.getQuestionTestController().getCorrectAnswer(contextDb.getQuestionTestController().getId(question.first())) == listCheckLayoutAnswer[i]->text())
        {
            countingAnswersTestController->increaseCorrectAnswer();
            listCheckLayoutAnswer[i]->getTextEdit().setStyleSheet("background-color: lightgreen");
        }
        else
        {
            countingAnswersTestController->increaseWrongAnswer();
            listCheckLayoutAnswer[i]->getTextEdit().setStyleSheet("background-color: red;  border-color: red");
            for(int i = 0; i < listCheckLayoutAnswer.size(); i++)
            {
                if(listCheckLayoutAnswer[i]->text() == contextDb.getQuestionTestController().getCorrectAnswer(contextDb.getQuestionTestController().getId(question.first())))
                {
                    listCheckLayoutAnswer[i]->getTextEdit().setStyleSheet("background-color: lightgreen");
                }
            }
        }
        for(int i = 0; i < listCheckLayoutAnswer.size(); i++)
        {
            listCheckLayoutAnswer[i]->setEnabled(false);
            listCheckLayoutAnswer[i]->getCheckBox().setEnabled(false);
        }
        break;
        }
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
