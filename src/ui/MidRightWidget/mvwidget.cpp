/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-11
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--MV显示界面
**************************************************/
#include "mvwidget.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPainter>
#include "QPen"

MvWidget::MvWidget(QWidget *parent)
    : QWidget(parent)
{
    this->initWidget();
    this->initForm();
    this->initConnect();
}

void MvWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen objPen(Qt::transparent);
    painter.setPen(objPen);
    QBrush objBrush(QColor(255,255,255,255));
    painter.setBrush(objBrush);
    painter.drawRect(this->rect());
}

void MvWidget::initForm()
{
}

void MvWidget::initWidget()
{
    m_label = new QLabel("MV",this);
    m_label->setFont(QFont("Times", 40, QFont::Bold));

    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addWidget(m_label);
    m_mainLayout->setContentsMargins(260,0,0,0);
    setLayout(m_mainLayout);
}

void MvWidget::initConnect()
{
}

