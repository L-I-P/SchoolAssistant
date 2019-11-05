#include "helper.h"

Helper::Helper()
{
    setWindowTitle("Справка");
    setStyleSheet("background-color: white");
    description = new QLabel("<H4>О приложении</H4><br>"
                               "Школьный помощник представляет возможность тестирования <br>по основным темам предмета Информатика и икт.<br><br>"
                               "Целью работы помощника заключается в изучении нового <br>и закреплении имеющихся знаний.<br><br>"
                               "Во время прохождения теста вы можете проверить свой ответ<br> до начала следующего вопроса.<br><br>"
                               "Единственное ограничение -  время на выполнение.<br><br>"
                               "Приложение находится в активной разработке.<br>"
                               "Обо всех найденных проблемах, пожеланиях пишите на адрес<br> nikita-Bereznix@yandex.com.");
    description->setFixedSize(350,350);
    button = new QPushButton("Понятно");
    button->setStyleSheet("background-color: lightgray;");
    connect(button, SIGNAL(clicked()), SLOT(close()));
    vlayout = new QVBoxLayout;
    vlayout->addWidget(description);
    vlayout->addWidget(button);
    setLayout(vlayout);
}

Helper::~Helper()
{
    delete description;
    delete button;
    delete vlayout;
}
