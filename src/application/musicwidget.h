/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-09
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器主界面的实现
**************************************************/
#ifndef MUSICWIDGET_H
#define MUSICWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QSystemTrayIcon>

class TitleWidget;
class BottomWidget;
class MidWidget;
class LeftToolBar;

class QVBoxLayout;
class QHBoxLayout;

class MyPlayer;
class SkinWidget;
class KugouSystemTray;

class MusicWidget : public QFrame
{
    Q_OBJECT
public:
    MusicWidget(QWidget *parent = 0);
    ~MusicWidget();
private:
    void initForm();
    void initWidget();
    void initConnect();
    void translator();

Q_SIGNALS:
    void signalMax(int);

private Q_SLOTS:
    void slotHide();
    void slotClose();
    void slotShowMax();
    void slotShowMin();
    void slotShowSkinWidget();

    void slotShowOrHideWidget(int);

    void iconIsActived(QSystemTrayIcon::ActivationReason reason);

public:
    static MusicWidget *Instance();
private:
    static MusicWidget *m_pInstance;

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

private:

    bool m_isMax;
    bool m_isPressed;
    QPoint m_point;
    QRect m_location;

    TitleWidget *m_title;                //标题栏
    BottomWidget *m_bottom;              //底部控制栏
    MidWidget *m_midWidget;              //中间显示部分
    LeftToolBar *m_leftToolBar;          //左边工具栏
    QHBoxLayout *m_midLayout;            //中间水平布局
    QVBoxLayout *m_maintLayout;          //总布局

    MyPlayer *m_player;                  //播放音乐类操作指针

    SkinWidget *m_skinWidget;            //皮肤界面

    KugouSystemTray *m_tray;             //系统托盘

};

#endif // MUSICWIDGET_H
