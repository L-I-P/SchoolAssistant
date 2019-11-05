#include "contextdb.h"

ContextDb::ContextDb()
{
    connectToDataBase();
}

ContextDb::~ContextDb()
{
    delete nameTestController;
    delete questionTestController;
    delete wrongAnswerTestController;
}

void ContextDb::connectToDataBase()
{
    db = QSqlDatabase::addDatabase("QMYSQL3");
    db.setHostName("remotemysql.com");
    db.setDatabaseName("RvuBmf8IE1");
    db.setUserName("RvuBmf8IE1");
    db.setPassword("UGADAI");
    db.setConnectOptions();
    try
    {
        if (db.open())
        {
            initialization();
        }
        else {
            throw "Ошибка подключения к базе данных";
        }
    }
    catch(QString error)
    {
        QMessageBox::critical(nullptr, "Ошибка", error);
    }
}

void ContextDb::initialization()
{
    nameTestController = new NameTestController;
    if(nameTestController == nullptr)
    {
        throw "Ошибка при загрузке списка Наименований тестов";
    }
    questionTestController = new QuestionTestController();
    if(questionTestController == nullptr)
    {
        throw "Ошибка при загрузке списка Вопросов тестов";
    }
    wrongAnswerTestController = new WrongAnswerTestController;
    if(wrongAnswerTestController == nullptr)
    {
        throw "Ошибка при загрузке списка Ответов на тестов";
    }
}

void ContextDb::closeDataBase()
{
    db.close();
}

NameTestController& ContextDb::getNameTestController()
{
    return *nameTestController;
}

QuestionTestController& ContextDb::getQuestionTestController()
{
    return *questionTestController;
}

WrongAnswerTestController& ContextDb::getWrongAnswerTestController()
{
    return *wrongAnswerTestController;
}
