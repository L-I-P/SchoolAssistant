#pragma once
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class PushButton : public QPushButton
{
public:
    PushButton();
    void setText(const QString text);
    QString text();
    void setMinimumSizeHeight();
private:
    QLabel *label;
    QHBoxLayout *layout;

};
