#pragma once
#include <QDialog>
#include <QVBoxLayout>

class ConditionTestView : public QDialog
{
public:
    ConditionTestView();
    ~ConditionTestView();
    QVBoxLayout& getVLayout();
private:
    QVBoxLayout* vlayout;
};
