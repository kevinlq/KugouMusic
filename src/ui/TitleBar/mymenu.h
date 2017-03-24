#ifndef MYMENU_H
#define MYMENU_H
#include <QAction>
#include "Common/menu.h"

class Play_Mode_Menu;
class AboutKugouDialog;

class MyMenu : public Menu
{
    Q_OBJECT
public:
   explicit MyMenu(QWidget *parent = 0);
    ~MyMenu();

    void translator();

Q_SIGNALS:
    void signal_quit();
private Q_SLOTS:
    void slotShowAboutKugou();                  //显示关于酷狗界面

private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    QAction *m_actionLogin;                     //登录

    Menu *m_menuAddMusic;
    QAction *m_actionAddLocalMusic;             //添加本地音乐
    QAction *m_actionAddLocalFolderMusic;       //本地歌曲文件夹

    Play_Mode_Menu *m_playMode;                 //播放模式

    //遥控器二级菜单
    Menu *m_menuRemote;                         //遥控器
    QAction *m_actionMagicRemote;               //魔方遥控器
    QAction *m_actionStripRemote;               //条形遥控器
    QAction *m_actionHideRemote;                //隐藏遥控器

    QAction *m_actionAverageBalance;            //均衡器
    QAction *m_actionMusicPlug;                 //音乐插件
    QAction *m_actiontimingSetting;             //定时设置

    QAction *m_actionAlwaysFront;               //界面总在最前
    QAction *m_actionRecoveryStatus;            //恢复窗口默认状态

    //下载设置二级菜单
    Menu *m_menuDownloadSetting;                //下载设置
    QAction *m_actionAllSpeedDownload;          //全速下载
    QAction *m_actionCustomDownload;            //自定义
    QAction *m_actionBroadband;                 //节省宽带

    QAction *m_actionOnLineUpdate;              //在线升级
    QAction *m_actionShowTodayRecommend;        //显示今日推荐

    //帮助与意见反馈二级菜单
    Menu *m_menuHelp;
    QAction *m_actionHelp;                      //帮助
    QAction *m_actionSuggest;                   //反馈
    QAction *m_actionAboutKugou;                //关于酷狗

    QAction *m_actionSetting;                   //设置
    QAction *m_actionQuit;                      //退出

    //菜单子功能
    AboutKugouDialog *m_aboutKugou;             //关于酷狗
};

#endif // MYMENU_H
