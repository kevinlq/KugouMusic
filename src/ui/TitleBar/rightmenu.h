/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-2-29
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---搜索框鼠标右键菜单的实现
**************************************************/
#ifndef RIGHTMENU_H
#define RIGHTMENU_H
#include "Common/menu.h"

class RightMenu : public Menu
{
    Q_OBJECT
public:
    explicit RightMenu(QWidget *parent = 0);
    ~RightMenu();
    void translator();

signals:
    void signalClip();
    void signalCopy();
    void signalPaste();
    void signalDelete();
    void signalSelectAll();
private:
    void initForm();
    void initConnect();
private:
    QAction *m_clip;                //剪贴
    QAction *m_copy;                //复制
    QAction *m_paste;               //粘贴
    QAction *m_delete;              //删除
    QAction *m_selectAll;           //全选
};

#endif // RIGHTMENU_H
