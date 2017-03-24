/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-13
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---播放进度条的实现
**************************************************/
#include "sliderwidget.h"
#include <QPainter>
#include <QMouseEvent>

#include <QtDebug>

SliderWidget::SliderWidget(QWidget *parent) : QWidget(parent)
{
    setFixedHeight(8);
    setAttribute(Qt::WA_TranslucentBackground);
    isAvailable = false;
    isPressed = false;
    currentPos = 0.0;
}

void SliderWidget::setAvailable(bool flag)
{
    isAvailable = flag;
}

qreal SliderWidget::getCurrentPostion()
{
    return this->currentPos;
}

void SliderWidget::moveTo(qreal pos)
{
    if (isPressed) return;
    currentPos = pos;
    update();
}

void SliderWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(QColor(122, 139, 152));
    pen.setWidth(0.5);
    painter.setPen(pen);
    painter.setBrush(QColor(139, 141, 145));
    painter.drawRect(0, 0, this->width()-1, this->height()-1);

    pen.setColor(QColor(255, 220, 26));
    painter.setPen(pen);
    painter.setBrush(QColor(255, 255, 255));
    painter.drawRect(1, 1, this->width() * currentPos, this->height()-1);
}

void SliderWidget::enterEvent(QEvent *)
{
    preCursor = cursor();
    setCursor(Qt::PointingHandCursor);
}

void SliderWidget::leaveEvent(QEvent *)
{
    setCursor(preCursor);
}

void SliderWidget::mousePressEvent(QMouseEvent *event)
{
    if (!isAvailable) return;
    if (event->button() != Qt::LeftButton)
        return;
    isPressed = true;
    currentPos = event->pos().x() / (this->width()+0.0);
    update();
}

void SliderWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (!isAvailable) return;
    isPressed = false;
    emit changeTo(currentPos);
}

void SliderWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (!isAvailable) return;
    if (isPressed)
    {
        currentPos = e->pos().x() / (this->width()+0.0);
        update();
    }
}
