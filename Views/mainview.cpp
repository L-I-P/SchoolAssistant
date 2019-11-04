#include "mainview.h"

MainView::MainView()
{
    setWindowTitle("Школьный помощник");
    setWindowFlags(Qt::Window);
    setMinimumSize(300,250);
    setMaximumSize(400,600);
    vlayout = new QVBoxLayout();
    QWidget* widget = new QWidget;
    widget->setLayout(vlayout);
    this->setCentralWidget(widget);
}

QVBoxLayout& MainView::getVLayout()
{
    return * vlayout;
}
