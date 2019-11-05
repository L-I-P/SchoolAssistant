#pragma once
#include <QDialog>
#include <QVBoxLayout>

class ConditionTestView : public QDialog
{
public:
    explicit ConditionTestView();
    ~ConditionTestView();
    QVBoxLayout& getVLayout();
private:
    QVBoxLayout* vlayout;
};
