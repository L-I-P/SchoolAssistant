#include "applicationcontroller.h"

ApplicationController::ApplicationController()
{
    context = new ContextDb;
    /*for(auto element : context->getQuestionTestController().getQuestionTest(1))
    {
        qDebug() << element;
        qDebug() << context->getQuestionTestController().getCorrectAnswer(context->getQuestionTestController().getId(element));
        for(auto element : context->getWrongAnswerTestController().getWrongAnswer(context->getQuestionTestController().getId(element)))
        {
            qDebug() << element;
        }
        qDebug() << "\n";
    }*/
    mainview = new MainView();
    InitializationWindow();
    mainview->show();
}
ApplicationController::~ApplicationController()
{
    delete mainview;
    delete context;
}

void ApplicationController::InitializationWindow()
{
    for(auto element : context->getNameTestController().getNameTest())
    {
        QPushButton* button = new QPushButton(element);
        connect(button, SIGNAL(clicked()), this, SLOT(InitializationConditionTest()));
        button->setMinimumHeight(50);
        button->setToolTip("Пожалуйста выберите тест, по которому\nхотите пройти тестирование.");
        mainview->getVLayout().addWidget(button);
    }
    if(mainview->getVLayout().isEmpty())
    {
        QLabel* label = new QLabel("Тесты не найдены");
        mainview->getVLayout().addWidget(label);
    }
}

void ApplicationController::InitializationConditionTest()
{
    if(!(context->getQuestionTestController().getQuestionTest(context->getNameTestController().getNumberTest(((QPushButton*)sender())->text()))).isEmpty())
    {
        ConditionTestController * conditionTestController = new ConditionTestController(
        context->getNameTestController().getConditionTest(((QPushButton*)sender())->text()));
        StartPlay();
    }
    else
    {
        QMessageBox::information(nullptr,"Информация","По выбранному тесту вопросов не найдено.\nПожалуйста выберите другой тест.");
    }
}

void ApplicationController::StartPlay()
{
    QuestionAnswerTestController *questionanswerTest = new QuestionAnswerTestController(*context,
                                                                                        context->getNameTestController().getNumberTest(((QPushButton*)sender())->text()));
    mainview->close(); questionanswerTest->exec(); mainview->show();
}
