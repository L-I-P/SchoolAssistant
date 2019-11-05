#pragma once
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDesktopServices>
#include <QUrl>

class Helper : public QDialog
{
    Q_OBJECT
public:
    explicit Helper();
    ~Helper();
public slots:
    void feedBack();
private:
    QLabel* description;
    QPushButton * button;
    QPushButton * feedBackButton;
    QVBoxLayout* vlayout;
};
