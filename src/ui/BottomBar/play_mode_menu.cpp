/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-15
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--播放模式菜单的实现
**************************************************/
#include "play_mode_menu.h"

Play_Mode_Menu::Play_Mode_Menu(QWidget *parent)
    :Menu(parent)
{
    this->initMenu();
    this->initForm();
    this->initConnect();
}

Play_Mode_Menu::~Play_Mode_Menu()
{

}

void Play_Mode_Menu::translator()
{
    m_actionSinglePlay->setText(tr("action_single_play"));
    m_actionSingleCirculate->setText(tr("action_single_circule"));
    m_actionOrderPlay->setText(tr("action_order_play"));
    m_actionListCirculate->setText(tr("action_list_circule"));
    m_actionRandomPlay->setText(tr("action_random_play"));
    m_actionAutoSwitchList->setText(tr("action_auto_switch_list"));
}

void Play_Mode_Menu::initForm()
{
}

void Play_Mode_Menu::initMenu()
{
    m_actionSinglePlay = new QAction(this);
    m_actionSingleCirculate = new QAction(this);
    m_actionOrderPlay = new QAction(this);
    m_actionListCirculate = new QAction(this);
    m_actionRandomPlay = new QAction(this);
    m_actionAutoSwitchList = new QAction(this);

    this->addAction(m_actionSinglePlay);
    this->addAction(m_actionSingleCirculate);
    this->addAction(m_actionOrderPlay);
    this->addAction(m_actionListCirculate);
    this->addAction(m_actionListCirculate);
    this->addAction(m_actionAutoSwitchList);

}

void Play_Mode_Menu::initConnect()
{
}

