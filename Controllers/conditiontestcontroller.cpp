#include "conditiontestcontroller.h"

ConditionTestController::ConditionTestController(QString condition)
{
    conditionTestView = new ConditionTestView;
    QLabel* label = new QLabel(condition);
    conditionTestView->getVLayout().addWidget(label);
    QPushButton* button = new QPushButton("Принято к сведению");
    connect(button, SIGNAL(clicked()), conditionTestView, SLOT(close()));
    button->setToolTip("Необходимо согласиться с условиями\nтеста, чтобы продолжить.");
    conditionTestView->getVLayout().addWidget(button);
    conditionTestView->exec();
}

ConditionTestController::~ConditionTestController()
{
    delete conditionTestView;
}
