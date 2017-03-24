/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-03-8
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---音乐电台界面的实现
**************************************************/
#include "musicradiowidget.h"
#include "mvradiowidget.h"

MusicRadioWidget::MusicRadioWidget(QWidget *parent)
    :AbstractTabWidget(parent)
{
    m_musicRadio = new QWidget;
    m_mvRaido = new MvRadioWidget;

    addTab(m_musicRadio,QString::fromLocal8Bit("音乐电台"));
    addTab(m_mvRaido,QString::fromLocal8Bit("MV电台"));
}

MusicRadioWidget::~MusicRadioWidget()
{

}

