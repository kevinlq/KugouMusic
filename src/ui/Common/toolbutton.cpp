#include "toolbutton.h"
#include <QPainter>

ToolButton::ToolButton(QWidget *parent)
    :QToolButton(parent)
{
    this->initForm();
    this->initConnect();
}

ToolButton::~ToolButton()
{
    //
}

void ToolButton::initForm()
{
    this->setAutoRaise(true);
    this->setCursor(Qt::PointingHandCursor);
    //this->setStyleSheet("color:white;");
    setIconSize(QSize(30,30));
}

void ToolButton::initConnect()
{
}
