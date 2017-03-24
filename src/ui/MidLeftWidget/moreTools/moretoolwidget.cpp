/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-15
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--更多功能
**************************************************/
#include "moretoolwidget.h"
#include <QGridLayout>
#include <QSignalMapper>
#include <QDebug>

MoreToolButton::MoreToolButton(QWidget *parent)
    :QToolButton(parent)
{
    this->initForm();
}
MoreToolButton::~MoreToolButton()
{

}

void MoreToolButton::initForm()
{
    this->setFixedSize(70,90);
    this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    this->setAutoRaise(true);
    this->setStyleSheet("QToolButton:hover{background-color:rgba(255,255,255,60%);"
                        "border-radius:8px;"
                        "padding:5px 5px 5px 5px;}");
}



MoreToolWidget::MoreToolWidget(QWidget *parent) : QWidget(parent)
{
    this->initForm();
}


MoreToolWidget::~MoreToolWidget()
{

}

void MoreToolWidget::slotClicked(QString value)
{
    qDebug()<<value;
}

void MoreToolWidget::initForm()
{
    textList <<QString::fromLocal8Bit("传歌到手机")<<QString::fromLocal8Bit("DLNA投放")
             <<QString::fromLocal8Bit("本地管理") <<QString::fromLocal8Bit("铃声制作")
             <<QString::fromLocal8Bit("繁星直播") <<QString::fromLocal8Bit("在线KTV")
             <<QString::fromLocal8Bit("格式转换") <<QString::fromLocal8Bit("定时设置")
             <<QString::fromLocal8Bit("网络测试") <<QString::fromLocal8Bit("酷狗收音机")
             <<QString::fromLocal8Bit("游戏中心") <<QString::fromLocal8Bit("VIP中心");

    iconList <<":/image/moreTool/0.png"<<":/image/moreTool/1.png"
             <<":/image/moreTool/2.png"<<":/image/moreTool/3.png"
             <<":/image/moreTool/4.png"<<":/image/moreTool/5.png"
             <<":/image/moreTool/6.png"<<":/image/moreTool/7.png"
             <<":/image/moreTool/8.png"<<":/image/moreTool/9.png"
             <<":/image/moreTool/10.png"<<":/image/moreTool/11.png";

    m_signalMapper = new QSignalMapper(this);
    m_gridLayout = new QGridLayout(this);
    for (int i = 0; i < textList.size() ;++i)
    {
        MoreToolButton *tbn = new MoreToolButton();
        connect(tbn,SIGNAL(clicked(bool)),m_signalMapper,SLOT(map()));
        m_signalMapper->setMapping(tbn,textList[i]);
        list_button.append(tbn);
        m_gridLayout->addWidget(tbn,i/3,i%3);
        list_button.at(i)->setText(textList.at(i));
        list_button.at(i)->setIcon(QIcon(iconList.at(i)));
        list_button.at(i)->setIconSize(QPixmap(iconList.at(i)).size());
    }

    connect(m_signalMapper,SIGNAL(mapped(QString)),
            this,SLOT(slotClicked(QString)));
    setLayout(m_gridLayout);

    //this->setStyleSheet("background-color:rgba(255,255,255,50%);");

}

void MoreToolWidget::initConnect()
{
}
