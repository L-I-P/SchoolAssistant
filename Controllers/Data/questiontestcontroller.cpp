#include "questiontestcontroller.h"

QuestionTestController::QuestionTestController()
{
    setQuestionTest();
}

void QuestionTestController::setQuestionTest()
{
        QSqlQuery query; query.exec("SELECT Id, NumberTest, Question, CorrectAnswer from QuestionTest");
        while (query.next())
        {
            QuestionTest questionTest;
            questionTest.setId(query.value(0).toInt());
            questionTest.setNumberTest(query.value(1).toInt());
            questionTest.setQuestion(query.value(2).toString());
            questionTest.setCorrectAnswer(query.value(3).toString());
            questionTestlist.append(questionTest);
        }
        /*for(auto element: questionTestlist)
        {
            qDebug() << element.getId();
            qDebug() << element.getNumberTest();
            qDebug() << element.getQuestion();
            qDebug() << element.getCorrectAnswer();
        }*/
}

QList<QString> QuestionTestController::getQuestionTest(int NumberTest)
{
    QList<QString> questionTest;
    for(auto element : questionTestlist)
    {
        if(NumberTest == element.getNumberTest())
        {
            questionTest.append(element.getQuestion());
        }
    }
    return questionTest;
}

QString QuestionTestController::getCorrectAnswer(int Id)
{
    QString correctAnswer;
    for(auto element : questionTestlist)
    {
        if(Id == element.getId())
        {
            correctAnswer = element.getCorrectAnswer();
            break;
        }
    }
    return correctAnswer;
}

int QuestionTestController::getId(QString question)
{
    int Id = -1;
    for(auto element : questionTestlist)
    {
        if(question == element.getQuestion())
        {
            Id = element.getId();
            return Id;
        }
    }
    if(Id == -1)
    {
        qDebug() << "Вопрос не найден.";
        exit(0);
    }
}
