/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-3-06
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---遥控器功能的实现
**************************************************/
#ifndef REMOTEWIDGET_H
#define REMOTEWIDGET_H

#include "core/musicabstractremotewidget.h"
//class MusicAbstractRemoteWidget;

#include <QMap>
class QGridLayout;
class QSlider;
class MusicAbstractRemoteButton;
class PlayMusicWidget;
class NextMusicWidget;
class PreviousMusicWidget;
class OpenKugouWidget;
class DesktopPhotoWidget;
class RightRwmoteMenu;

class RemoteWidget : public MusicAbstractRemoteWidget
{
    Q_OBJECT
public:
    explicit RemoteWidget(QWidget *parent = 0);
    ~RemoteWidget();

Q_SIGNALS:
    void signalShowOrHidMainWidget(int);
    void signalHideRemote();

private Q_SLOTS:
    void slotShowMenu(const QPoint&);
    void slotAlwayOnTop();              //总在最前
    void slotShowOrHidMainWidget();     //显示或隐藏主界面
    void slotShowRectangleRemote();     //显示条形遥控器
    void slotShowMagicRemote();         //显示魔方遥控器
private:
    void initForm();                    //样式初始化
    void initLayout();                  //初始化布局
    void initStyle();
    void initConnect();                 //初始化信号与槽的连接

private:
    //QMap<QString,QString> m_iconMap;            //图片路径
    PlayMusicWidget *m_midWidget;               //中央窗体
    NextMusicWidget *m_nextWidget;
    PreviousMusicWidget *m_previousWidget;
    OpenKugouWidget *m_kugouWidget;
    DesktopPhotoWidget *m_desktopWidget;

    MusicAbstractRemoteButton *m_tbnPlayOrPause;
    MusicAbstractRemoteButton *m_tbnNext;
    MusicAbstractRemoteButton *m_noVoice;
    QSlider *m_musicSlitter;
    MusicAbstractRemoteButton *m_tbnPrevious;
    MusicAbstractRemoteButton *m_tbnOpenOrHideKugou;
    MusicAbstractRemoteButton *m_tbnOpenOrCloseDesktop;

    QGridLayout *m_gridLayout;

    RightRwmoteMenu *m_rightRemoteMenu;
    bool m_isShowMainWidget;
};

#endif // REMOTEWIDGET_H
