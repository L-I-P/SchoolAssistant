#pragma once
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class Helper : public QDialog
{
public:
    Helper();
    ~Helper();
private:
    QLabel* description;
    QPushButton * button;
    QVBoxLayout* vlayout;
};
