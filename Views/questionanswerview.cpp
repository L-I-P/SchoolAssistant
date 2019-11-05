#include "questionanswerview.h"

QuestionAnswerView::QuestionAnswerView()
{
    setMinimumSize(400,400);
    setMaximumSize(500,700);
    setWindowFlags(Qt::Window | Qt::WindowTitleHint);

    glayout = new QVBoxLayout;
    qalayout = new QVBoxLayout;
    glayout->addLayout(qalayout);
    setLayout(glayout);

    labelTimer = new QLabel("Таймер");
    qalayout->addWidget(labelTimer);

    QLabel* nameQuestion = new QLabel("<H4><CENTER>Вопрос</CENTER></H4>");
    qalayout->addWidget(nameQuestion);

    question = new QTextEdit("Здесь должен быть вопрос");
    question->setEnabled(false);
    question->setStyleSheet("background-color: white; color: black");
    qalayout->addWidget(question);

    QLabel* nameAnswer = new QLabel("<H4><CENTER>Ответы</CENTER></H4>");
    qalayout->addWidget(nameAnswer);

    nextQuestion = new QPushButton("Следующий вопрос");
    glayout->addWidget(nextQuestion);

    exitTest = new QPushButton("Закончить тестирование");
    glayout->addWidget(exitTest);

    qalayout->setSpacing(15);
    qalayout->setMargin(20);
}

QuestionAnswerView::~QuestionAnswerView()
{
    delete glayout;
    delete qalayout;
    delete labelTimer;
    delete question;

    delete nextQuestion;
    delete exitTest;
}

QVBoxLayout& QuestionAnswerView::getGlayout()
{
    return * glayout;
}

QVBoxLayout& QuestionAnswerView::getQalayout()
{
    return * qalayout;
}

QLabel& QuestionAnswerView::getLabelTimer()
{
    return * labelTimer;
}

QTextEdit& QuestionAnswerView::getQuestion()
{
    return * question;
}

QPushButton& QuestionAnswerView::getNextQuestion()
{
    return * nextQuestion;
}

QPushButton& QuestionAnswerView::getExitTest()
{
    return * exitTest;
}
