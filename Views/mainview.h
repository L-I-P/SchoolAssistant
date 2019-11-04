#pragma once

#include <QMainWindow>
#include <QObject>
#include <QVBoxLayout>

class MainView : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainView();
    QVBoxLayout& getVLayout();
private:
    QVBoxLayout* vlayout;
};
