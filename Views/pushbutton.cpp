#include "pushbutton.h"

PushButton::PushButton()
{
    label = new QLabel;
    label->setAlignment(Qt::AlignCenter);
    //setMinimumHeight(label->height()*1);
    label->setEnabled(false);
    label->setStyleSheet("color: black");
    layout = new QHBoxLayout;
    layout->setSpacing(0);
    layout->setContentsMargins(4,4,4,4);
    layout->addWidget(label,0,Qt::AlignCenter);
    this->setLayout(layout);
    setStyleSheet("background-color: white; color: black");
}

void PushButton::setText(QString text)
{
    label->setText(text);
}
QString PushButton::text()
{
    return label->text();
}

void PushButton::setMinimumSizeHeight()
{
    //setMinimumHeight(label->height()*1);
}

