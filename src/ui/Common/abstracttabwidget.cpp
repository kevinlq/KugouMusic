#include "abstracttabwidget.h"
#include <QTabBar>

AbstractTabWidget::AbstractTabWidget(QWidget *parent)
    :QTabWidget(parent)
{
    this->initForm();
}

AbstractTabWidget::~AbstractTabWidget()
{
}

void AbstractTabWidget::initForm()
{
    tabBar()->setCursor(Qt::PointingHandCursor);
    tabBar()->setFont(QFont("Times", 12, QFont::Bold));

    QString tabBarStyle = "QTabBar::tab{min-width:140px;min-height:22px;\
    color:white;border: 0px solid;border-top-left-radius:4px; \
    border-top-right-radius: 10px;padding:5px;}\
    QTabBar::tab:!selected {margin-top: 5px;color:#999999;} \
    QTabBar::tab:selected {color: #0172BF;border:0px;} \
    QTabBar::tab:hover{background:rgb(255,255,255,60);}";
    setStyleSheet(tabBarStyle);
}

