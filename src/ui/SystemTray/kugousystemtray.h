/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-3-01
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---系统托盘的实现
**************************************************/
#ifndef KUGOUSYSTEMTRAY_H
#define KUGOUSYSTEMTRAY_H

#include <QSystemTrayIcon>
class QWidgetAction;
class QToolButton;
class QLabel;
class QSlider;
class QAction;
class VoiceButton;
class MusicTrayButton;

class KugouSystemTray : public QSystemTrayIcon
{
    Q_OBJECT
public:
    KugouSystemTray(QWidget *parent = 0);
    ~KugouSystemTray();


Q_SIGNALS:
    void signalNoVoice();
    void signalVoiceNormal();
    void signalLogOut();
    void signalClose();
private Q_SLOTS:
    void slotVoiceStateChange();
    void slotMusicSliderValueChange(int value);

private:
    void initMusiControlInfo();
    void initMidInfo();
    void initBottomInfo();
    void initAction();
    void initConnect();
    void initForm();

private:
    QMenu *m_trayMenu;

    QWidget *m_topWidget;
    QWidgetAction *m_topWidgetAction;
    MusicTrayButton *m_play;                    //播放
    QToolButton *m_next;                        //下一首
    QToolButton *m_previous;                    //上一首
    QLabel *m_songName;                         //歌曲名称

    QWidget *m_playWidget;
    QWidgetAction *m_playVoiceWidgetAction;     //播放声音控制
    VoiceButton *m_noVoice;                     //静音
    QSlider *m_musicSlider;

    QAction *m_showDesktopLrc;                  //显示桌面歌词
    QAction *m_unlockLrc;                       //解锁歌词
    QAction *m_optionSetting;                   //选项设置
    QAction *m_logout;                          //注销
    QAction *m_exit;                            //退出
};

#endif // KUGOUSYSTEMTRAY_H
