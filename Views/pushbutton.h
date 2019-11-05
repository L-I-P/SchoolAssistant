#pragma once
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>

class PushButton : public QPushButton
{
public:
    explicit PushButton();
    ~PushButton();
    void setText(const QString text);
    void setMinimumSizeHeight();
    QString text();
private:
    QTextEdit *textEdit;
    QHBoxLayout *layout;

};
