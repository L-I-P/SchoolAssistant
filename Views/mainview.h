#pragma once

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include "Views/helper.h"

class MainView : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainView();
    ~MainView();
    QVBoxLayout& getVLayout();
private:
    void createMenu();
private:
    QVBoxLayout* vlayout;
    QToolBar * toolBar;
    QAction *aboutProgramm;
    Helper * helper;
};
