/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-3-04
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--系统托盘菜单自定义按钮实现:
            实现了文字提示，图标设置，按钮突起，鼠标样式
**************************************************/
#include "musictraybutton.h"

MusicTrayButton::MusicTrayButton(QWidget *parent, const QString &icon,
                                 const QString &text)
    :QToolButton(parent),m_icon(icon),m_text(text)
{
    setToolTip(m_text);
    setIcon(QIcon(m_icon));
    setIconSize(QSize(30,30));
    setAutoRaise(true);
    setCursor(Qt::PointingHandCursor);

    initConnect();
}

MusicTrayButton::~MusicTrayButton()
{
}

void MusicTrayButton::initConnect()
{
}

