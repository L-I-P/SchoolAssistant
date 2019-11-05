#pragma once
#include <QCheckBox>
#include <QTextEdit>
#include <QHBoxLayout>

class CheckLayout : public QHBoxLayout
{
public:
    explicit CheckLayout();
    ~CheckLayout();
    void setText(const QString text);
    void setMinimumSizeHeight();
    QCheckBox& getCheckBox();
    QTextEdit& getTextEdit();
    QString text();
private:
    QCheckBox * checkBox;
    QTextEdit *textEdit;
};
