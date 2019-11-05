#include "pushbutton.h"

PushButton::PushButton()
{
    textEdit = new QTextEdit;
    textEdit->setAlignment(Qt::AlignCenter);
    //setMinimumHeight(label->height()*1);
    textEdit->setEnabled(false);
    textEdit->setReadOnly(true);
    textEdit->setStyleSheet("color: black;  border-color: lightgray;");
    layout = new QHBoxLayout;
    layout->setSpacing(0);
    layout->setContentsMargins(4,4,4,4);
    layout->addWidget(textEdit,0,Qt::AlignCenter);
    this->setLayout(layout);
    setStyleSheet("background-color: lightgray; color: black; border-color: lightgray");
}

PushButton::~PushButton()
{
    delete textEdit;
    delete layout;
}

void PushButton::setText(QString text)
{
    textEdit->setPlainText(text);
}
QString PushButton::text()
{
    return textEdit->toPlainText();
}

void PushButton::setMinimumSizeHeight()
{
    //setMinimumHeight(label->height()*1);
}

