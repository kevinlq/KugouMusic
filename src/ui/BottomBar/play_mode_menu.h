/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-15
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--播放模式菜单的实现
**************************************************/
#ifndef PLAY_MODE_MENU_H
#define PLAY_MODE_MENU_H
#include "Common/menu.h"

class Play_Mode_Menu : public Menu
{
    Q_OBJECT
public:
    explicit Play_Mode_Menu(QWidget *parent = 0);
    ~Play_Mode_Menu();
    void translator();
private:
    void initForm();
    void initMenu();
    void initConnect();

private:
    QAction *m_actionSinglePlay;            //单曲播放
    QAction *m_actionSingleCirculate;       //单曲循环
    QAction *m_actionOrderPlay;             //顺序播放
    QAction *m_actionListCirculate;         //列表循环
    QAction *m_actionRandomPlay;            //随机播放
    QAction *m_actionAutoSwitchList;        //自动切换列表
};

#endif // PLAY_MODE_MENU_H
