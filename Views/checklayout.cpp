#include "checklayout.h"

CheckLayout::CheckLayout()
{
    checkBox = new QCheckBox;
    textEdit = new QTextEdit;
    textEdit->setAlignment(Qt::AlignCenter);
    //setMinimumHeight(label->height()*1);
    textEdit->setReadOnly(true);
    textEdit->setStyleSheet("color: black;  border-color: white;");
    setSpacing(0);
    setContentsMargins(4,4,4,4);
    addWidget(checkBox), Qt::AlignVCenter;
    addWidget(textEdit,0,Qt::AlignCenter);
}

CheckLayout::~CheckLayout()
{
    delete textEdit;
    delete checkBox;
}

void CheckLayout::setText(QString text)
{
    textEdit->setPlainText(text);
}
QString CheckLayout::text()
{
    return textEdit->toPlainText();
}

void CheckLayout::setMinimumSizeHeight()
{
    //setMinimumHeight(label->height()*1);
}

QCheckBox& CheckLayout::getCheckBox()
{
    return * checkBox;
}

QTextEdit& CheckLayout::getTextEdit()
{
    return * textEdit;
}
