/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-03-10
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:酷狗音乐播放器---遥控器鼠标右键菜单实现
**************************************************/
#ifndef RIGHTREMOTEMENU_H
#define RIGHTREMOTEMENU_H
#include "Common/menu.h"

class QAction;

class RightRwmoteMenu : public Menu
{
    Q_OBJECT
public:
    explicit RightRwmoteMenu(QWidget *parent);
    ~RightRwmoteMenu();
Q_SIGNALS:
    void signalAlwayOnTop();        //总是在前
    void signalShowMainWidget();    //显示主界面
    void signalRectangleRemote();   //条形遥控器
    void signalMagicRemote();       //魔方遥控器
    void signalHideRemote();        //隐藏遥控器

private Q_SLOTS:
public Q_SLOTS:
    void slotChangeShowMainWidgetStatus(int status);

protected:
    //virtual void paintEvent(QPaintEvent *);

private:
    void initForm();
    void initAction();
    void initConnect();

private:
    QAction *m_alwayOnTop;          //总在最前
    QAction *m_showMainWidget;      //显示主界面
    QAction *m_RectangleRemote;     //条形遥控器
    QAction *m_magicCubeRemote;     //魔方遥控器
    QAction *m_hideRemote;          //隐藏遥控器

};

#endif // RIGHTMENU_H
