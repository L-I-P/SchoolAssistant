#include <QApplication>
#include <Controllers/applicationcontroller.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ApplicationController *app = new ApplicationController;
    return a.exec();
}
