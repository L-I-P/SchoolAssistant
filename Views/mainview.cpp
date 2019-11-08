#include "mainview.h"

MainView::MainView()
{
    setWindowTitle("Школьный помощник");
    setWindowFlags(Qt::Window);
    setMinimumSize(350,400);
    setMaximumSize(400,600);
    vlayout = new QVBoxLayout();
    QWidget* widget = new QWidget;
    widget->setLayout(vlayout);
    this->setCentralWidget(widget);
    createMenu();
}

MainView::~MainView()
{
    delete vlayout;
    delete toolBar;
    delete aboutProgramm;
}

QVBoxLayout& MainView::getVLayout()
{
    return * vlayout;
}

void MainView::createMenu()
{
    QToolBar * toolBar = new QToolBar;
    QAction *aboutProgramm = new QAction(tr("Справка"));
    helper = new Helper;
    toolBar->addAction(aboutProgramm);
    toolBar->setMovable(false);
    addToolBar(toolBar);
    connect(aboutProgramm,SIGNAL(triggered()), helper, SLOT(show()));
}
