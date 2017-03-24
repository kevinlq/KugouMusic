/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-12
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--主菜单的实现
**************************************************/
#include "mymenu.h"
#include "iconhelper.h"
#include <QApplication>
#include <QDesktopWidget>
#include "Common/menu.h"
#include "BottomBar/play_mode_menu.h"

#include "aboutkugoudialog.h"

MyMenu::MyMenu(QWidget *parent)
    :Menu(parent)
{
    this->initForm();
    this->initWidget();
    this->initConnect();
}

MyMenu::~MyMenu()
{
}

void MyMenu::translator()
{
    m_playMode->translator();
    m_aboutKugou->translator();

    m_actionLogin->setText(tr("action_login"));
    m_menuAddMusic->setTitle(tr("menu_add_music"));
    m_actionAddLocalMusic->setText(tr("action_add_local_music.."));
    m_actionAddLocalFolderMusic->setText(tr("action_add_music_local_folder_music"));

    m_actionMagicRemote->setText(tr("action_magic_remote"));
    m_actionStripRemote->setText(tr("action_strip_remote"));
    m_actionHideRemote->setText(tr("action_hide_remote"));

    m_actionAverageBalance->setText(tr("average_balance"));
    m_actionMusicPlug->setText(tr("action_music_plug"));
    m_actiontimingSetting->setText(tr("action_timingSetting"));
    m_actionAlwaysFront->setText(tr("action_alwaysFront"));
    m_actionRecoveryStatus->setText(tr("action_recovery"));

    m_actionAllSpeedDownload->setText(tr("action_all_speed_download"));
    m_actionCustomDownload->setText(tr("action_custom_download"));
    m_actionBroadband->setText(tr("action_broadband"));

    m_actionOnLineUpdate->setText(tr("action_online_update"));
    m_actionShowTodayRecommend->setText(tr("action_show_today_recommend"));

    m_actionHelp->setText(tr("action_help"));
    m_actionSuggest->setText(tr("action_suggest"));
    m_actionAboutKugou->setText(tr("action_about_kugou"));

    m_actionSetting->setText(tr("action_setting"));
    m_actionQuit->setText(tr("action_quit"));
}

void MyMenu::slotShowAboutKugou()
{
    m_aboutKugou->exec();
}

void MyMenu::initForm()
{
}

void MyMenu::initWidget()
{
    m_actionLogin = new QAction(this);

    //添加音乐二级菜单
    m_menuAddMusic = new Menu(this);
    m_actionAddLocalMusic = new QAction(m_menuAddMusic);
    m_actionAddLocalFolderMusic = new QAction(m_menuAddMusic);
    m_menuAddMusic->addAction(m_actionAddLocalMusic);
    m_menuAddMusic->addAction(m_actionAddLocalFolderMusic);

    m_playMode = new Play_Mode_Menu(this);
    m_playMode->setTitle(tr("play_mode"));

    //遥控器二级菜单
    m_menuRemote = new Menu(this);
    m_menuRemote->setTitle(tr("menu_remote"));
    m_actionMagicRemote = new QAction(this);
    m_actionStripRemote = new QAction(this);
    m_actionHideRemote = new QAction(this);
    m_menuRemote->addAction(m_actionMagicRemote);
    m_menuRemote->addAction(m_actionStripRemote);
    m_menuRemote->addAction(m_actionHideRemote);

    m_actionAverageBalance = new QAction(this);
    m_actionMusicPlug  = new QAction(this);
    m_actiontimingSetting  = new QAction(this);
    m_actionAlwaysFront  = new QAction(this);
    m_actionRecoveryStatus  = new QAction(this);

    //下载设置二级菜单
    m_menuDownloadSetting = new Menu(this);
    m_menuDownloadSetting->setTitle(tr("menu_downloadSetting"));
    m_actionAllSpeedDownload = new QAction(this);
    m_actionCustomDownload = new QAction(this);
    m_actionBroadband = new QAction(this);
    m_menuDownloadSetting->addAction(m_actionAllSpeedDownload);
    m_menuDownloadSetting->addAction(m_actionCustomDownload);
    m_menuDownloadSetting->addAction(m_actionBroadband);

    //在线更新
    m_actionOnLineUpdate = new QAction(this);

    //显示今日推荐
    m_actionShowTodayRecommend = new QAction(this);

    //帮助与意见反馈二级菜单
    m_menuHelp = new Menu(this);
    m_menuHelp->setTitle(tr("menu_help"));
    m_actionHelp = new QAction(this);
    m_actionSuggest = new QAction(this);
    m_actionAboutKugou = new QAction(this);
    m_menuHelp->addAction(m_actionHelp);
    m_menuHelp->addAction(m_actionSuggest);
    m_menuHelp->addAction(m_actionAboutKugou);

    m_actionSetting  = new QAction(this);
    m_actionQuit  = new QAction(this);

    m_actionLogin->setIcon(QIcon(":/image/mainMenu/help.png"));
    m_actionAverageBalance->setIcon(QIcon(":/image/mainMenu/open.png"));
    m_actionSetting->setIcon(QIcon(":/image/mainMenu/setting.png"));
    m_actionQuit->setIcon(QIcon(":/image/mainMenu/quit.png"));

    this->addAction(m_actionLogin);
    this->addSeparator();
    this->addMenu(m_menuAddMusic);
    this->addMenu(m_playMode);
    this->addSeparator();
    this->addMenu(m_menuRemote);
    this->addAction(m_actionAverageBalance);
    this->addAction(m_actionMusicPlug);
    this->addAction(m_actiontimingSetting);
    this->addSeparator();
    this->addAction(m_actionAlwaysFront);
    this->addAction(m_actionRecoveryStatus);
    this->addMenu(m_menuDownloadSetting);
    this->addAction(m_actionOnLineUpdate);
    this->addAction(m_actionShowTodayRecommend);
    this->addMenu(m_menuHelp);
    this->addAction(m_actionSetting);
    this->addSeparator();
    this->addAction(m_actionQuit);

    //菜单子功能
    m_aboutKugou = new AboutKugouDialog;          //关于酷狗

}

void MyMenu::initConnect()
{
    connect(m_actionAboutKugou,SIGNAL(triggered(bool)),
            this,SLOT(slotShowAboutKugou()));
    connect(m_actionQuit,SIGNAL(triggered(bool)),
            this,SIGNAL(signal_quit()));
}

