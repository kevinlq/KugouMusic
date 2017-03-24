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
#ifndef MUSICTRAYBUTTON_H
#define MUSICTRAYBUTTON_H

#include <QToolButton>

class MusicTrayButton : public QToolButton
{
    Q_OBJECT
public:
    explicit MusicTrayButton(QWidget *parent,const QString &icon,
                             const QString &text);
    ~MusicTrayButton();
private:
    void initConnect();
private:
    QString m_icon;
    QString m_text;
};

#endif // MUSICTRAYBUTTON_H
