/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-09
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---左边工具按钮的实现
**************************************************/
#include "lefttoolbar.h"
#include "iconhelper.h"

#include "Common/toolbutton.h"
#include <QLabel>
#include <QVBoxLayout>

LeftToolBar::LeftToolBar(QWidget *parent)
    : QWidget(parent)
{
    this->initWidget();
    this->initForm();
    this->initConnect();
}

void LeftToolBar::traanslator()
{
    m_tbnLocalList->setToolTip(tr("local_list"));
    m_tbnNetworkCollect->setToolTip(tr("network_collect"));
    m_tbnMusicRadio->setToolTip(tr("music_radio"));
    m_tbnPhoneManage->setToolTip(tr("phone_manaage"));
    m_tbnLocalMusic->setToolTip(tr("local_music"));
    m_tbnMore->setToolTip(tr("more"));
}

void LeftToolBar::initForm()
{
    this->setMaximumWidth(40);

//    IconHelper::Instance()->SetIcon(m_tbnLocalList,QChar(0xf001),18);
//    IconHelper::Instance()->SetIcon(m_tbnNetworkCollect,QChar(0xf0c2),18);
//    IconHelper::Instance()->SetIcon(m_tbnMusicRadio,QChar(0xf17d),18);
//    IconHelper::Instance()->SetIcon(m_tbnLocalMusic,QChar(0xf161),18);
//    IconHelper::Instance()->SetIcon(m_tbnPhoneManage,QChar(0xf10a),18);
//    IconHelper::Instance()->SetIcon(m_tbnMore,QChar(0xf029),18);

    m_tbnLocalList->setIcon(QIcon(":/image/appTools/music_button_playlist.png"));
    m_tbnNetworkCollect->setIcon(QIcon(":/image/appTools/music_button_cloud.png"));
    m_tbnMusicRadio->setIcon(QIcon(":/image/appTools/music_button_radio.png"));
    m_tbnLocalMusic->setIcon(QIcon(":/image/appTools/music_button_mydownl.png"));
    m_tbnPhoneManage->setIcon(QIcon(":/image/appTools/music_button_mobile.png"));
    m_tbnMore->setIcon(QIcon(":/image/appTools/music_button_tools.png"));

    m_vecTbn.push_back(m_tbnLocalList);
    m_vecTbn.push_back(m_tbnNetworkCollect);
    m_vecTbn.push_back(m_tbnMusicRadio);
    m_vecTbn.push_back(m_tbnLocalMusic);
    m_vecTbn.push_back(m_tbnPhoneManage);
    m_vecTbn.push_back(m_tbnMore);
    for (int i = 0; i != m_vecTbn.size();i++)
    {
        m_vecTbn.at(i)->setCursor(Qt::ArrowCursor);
        m_vecTbn.at(i)->setCheckable(true);
        m_vecTbn.at(i)->setAutoExclusive(true);
    }
}

void LeftToolBar::initWidget()
{
    m_tbnLocalList = new ToolButton(this);
    m_tbnNetworkCollect = new ToolButton(this);
    m_tbnMusicRadio = new ToolButton(this);
    m_tbnPhoneManage = new ToolButton(this);
    m_tbnLocalMusic = new ToolButton(this);
    m_tbnMore = new ToolButton(this);

    this->setButtonStyle(m_tbnLocalList);
    this->setButtonStyle(m_tbnNetworkCollect);
    this->setButtonStyle(m_tbnMusicRadio);
    this->setButtonStyle(m_tbnPhoneManage);
    this->setButtonStyle(m_tbnLocalMusic);
    this->setButtonStyle(m_tbnMore);


    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addSpacing(15);
    m_mainLayout->addWidget(m_tbnLocalList);
    m_mainLayout->addWidget(m_tbnNetworkCollect);
    m_mainLayout->addWidget(m_tbnMusicRadio);
    m_mainLayout->addWidget(m_tbnPhoneManage);
    m_mainLayout->addWidget(m_tbnLocalMusic);
    m_mainLayout->addWidget(m_tbnMore);
    m_mainLayout->addStretch();
    m_mainLayout->setContentsMargins(0,0,10,0);
    this->setLayout(m_mainLayout);
}

void LeftToolBar::initConnect()
{
    connect(m_tbnLocalList,SIGNAL(clicked(bool)),
            this,SIGNAL(signalLocalList()));
    connect(m_tbnNetworkCollect,SIGNAL(clicked(bool)),
            this,SIGNAL(signalNetCollect()));
    connect(m_tbnMusicRadio,SIGNAL(clicked(bool)),
            this,SIGNAL(signalMusicRadio()));
    connect(m_tbnPhoneManage,SIGNAL(clicked(bool)),
            this,SIGNAL(signalPhoneManage()));
    connect(m_tbnLocalMusic,SIGNAL(clicked(bool)),
            this,SIGNAL(signalLocalMusic()));
    connect(m_tbnMore,SIGNAL(clicked(bool)),
            this,SIGNAL(signalMoreTool()));
}

void LeftToolBar::setButtonStyle(ToolButton *tbn)
{
    tbn->setFixedSize(48,50);
    tbn->setObjectName("leftToolBar");
}

