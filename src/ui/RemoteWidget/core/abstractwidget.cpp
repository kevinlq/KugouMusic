#include "abstractwidget.h"
#include <QPainter>

AbstractWidget::AbstractWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(70,70);
}

AbstractWidget::~AbstractWidget()
{
}

void AbstractWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(QColor(127,127,127));
    painter.drawRect(this->rect());
}

