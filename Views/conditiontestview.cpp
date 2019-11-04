#include "conditiontestview.h"

ConditionTestView::ConditionTestView()
{
    setWindowTitle("О тесте");
    setWindowFlags(Qt::Window | Qt::WindowTitleHint);
    setMinimumSize(250,300);
    setMaximumSize(400,600);
    vlayout = new QVBoxLayout;
    setLayout(vlayout);
}

QVBoxLayout& ConditionTestView::getVLayout()
{
    return * vlayout;
}

ConditionTestView::~ConditionTestView()
{
    delete vlayout;
}
