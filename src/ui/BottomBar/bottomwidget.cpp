/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-09
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---底部控制界面
**************************************************/
#include "bottomwidget.h"
#include "iconhelper.h"
#include "Common/toolbutton.h"
#include "sliderwidget.h"
#include "play_mode_menu.h"         //播放模式菜单

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>


BottomWidget::BottomWidget(QWidget *parent)
    :QWidget(parent)
{   
    this->initWidget();
    this->initForm();
    this->initConnect();
}

BottomWidget::~BottomWidget()
{
}

void BottomWidget::translator()
{
    m_playMode->translator();

    m_tbnPerious->setToolTip(tr("perious_music"));
    m_tbnNext->setToolTip(tr("nect_music"));
    m_tbnPlay->setToolTip(tr("play_music"));

    m_tbnLove->setToolTip(tr("i_love_it"));
    m_tbnDownload->setToolTip(tr("download_music"));
    m_tbnSimilarMusic->setToolTip(tr("similar_music"));
    m_tbnCircleMode->setToolTip(tr("list_circle_model"));
    m_tbnVoice->setToolTip(tr("no_voice"));
    m_tbnSoundEffect->setToolTip(tr("snake_effect"));                   //蝰蛇音效
    m_tbnMusicWords->setToolTip(tr("open_desktop_music_words"));        //打开桌面歌词

    m_label_misic_num->setText("10");

    m_labelMusicName->setText(tr("label_music_name"));
    m_labelMusicTotalTime->setText("00:00");
    m_labelMusicCurTime->setText("00:00");
}

void BottomWidget::initForm()
{
    this->setMaximumHeight(60);

    IconHelper::Instance()->SetIcon(m_tbnPerious,QChar(0xf04a),18);
    IconHelper::Instance()->SetIcon(m_tbnPlay,QChar(0xf04b),18);
    IconHelper::Instance()->SetIcon(m_tbnNext,QChar(0xf04e),18);

    IconHelper::Instance()->SetIcon(m_tbnLove,QChar(0xf004),14);
    IconHelper::Instance()->SetIcon(m_tbnDownload,QChar(0xf161),14);
    IconHelper::Instance()->SetIcon(m_tbnSimilarMusic,QChar(0xf1d7),14);
    IconHelper::Instance()->SetIcon(m_tbnCircleMode,QChar(0xf0ec),14);
    IconHelper::Instance()->SetIcon(m_tbnVoice,QChar(0xf028),14);
    IconHelper::Instance()->SetIcon(m_tbnSoundEffect,QChar(0xf007),14);
    IconHelper::Instance()->SetIcon(m_tbnMusicWords,QChar(0xf008),14);
    IconHelper::Instance()->SetIcon(m_tbnMusicPlayQueue,QChar(0xf0ca),14);
}

void BottomWidget::initWidget()
{
    m_tbnPerious = new ToolButton();
    m_tbnPlay = new ToolButton();
    m_tbnNext = new ToolButton();

    m_tbnLove = new ToolButton();
    m_tbnDownload = new ToolButton();
    m_tbnSimilarMusic = new ToolButton();

    m_tbnCircleMode = new ToolButton(this);
    m_tbnCircleMode->setObjectName("tbnMenu");
    m_playMode = new Play_Mode_Menu(this);
    m_playMode->setObjectName("MenuplayMode");
    m_tbnCircleMode->setMenu(m_playMode);

    m_tbnVoice = new ToolButton();
    m_tbnSoundEffect = new ToolButton();
    m_tbnMusicWords = new ToolButton();
    m_tbnMusicPlayQueue = new ToolButton();
    m_label_misic_num = new QLabel(this);
    m_label_misic_num->setObjectName("whitelabel");
    m_label_misic_num->setStyleSheet("color:rgb(255,255,255)");

    //歌曲信息标签
    m_labelMusicName = new QLabel(this);
    m_labelMusicName->setObjectName("whitelabel");
    m_labelMusicTotalTime = new QLabel(this);
    m_labelMusicTotalTime->setObjectName("whitelabel");

    QLabel *label_music_time_div = new QLabel(this);
    label_music_time_div->setText("/");
    label_music_time_div->setObjectName("whitelabel");

    m_labelMusicCurTime = new QLabel(this);
    m_labelMusicCurTime->setObjectName("whitelabel");

    m_sliderWidget = new SliderWidget();            //播放进度条


    m_MusicInfoLayout = new QHBoxLayout;
    m_MusicInfoLayout->addWidget(m_labelMusicName);
    m_MusicInfoLayout->addStretch();
    m_MusicInfoLayout->addWidget(m_labelMusicCurTime);
    m_MusicInfoLayout->addWidget(label_music_time_div);
    m_MusicInfoLayout->addWidget(m_labelMusicTotalTime);
    m_MusicInfoLayout->setContentsMargins(0,0,0,0);


    QVBoxLayout *MusicLayout = new QVBoxLayout();
    MusicLayout->addLayout(m_MusicInfoLayout);
    MusicLayout->addWidget(m_sliderWidget);
    MusicLayout->setContentsMargins(0,0,0,0);

    m_mainLayout = new QHBoxLayout(this);
    m_mainLayout->addSpacing(25);
    m_mainLayout->addWidget(m_tbnPerious);
    m_mainLayout->addSpacing(5);
    m_mainLayout->addWidget(m_tbnPlay);
    m_mainLayout->addSpacing(5);
    m_mainLayout->addWidget(m_tbnNext);
    //m_mainLayout->addStretch();
    m_mainLayout->addLayout(MusicLayout);

    m_mainLayout->addWidget(m_tbnLove);
    m_mainLayout->addWidget(m_tbnDownload);
    m_mainLayout->addWidget(m_tbnSimilarMusic);
    m_mainLayout->addWidget(m_tbnCircleMode);
    m_mainLayout->addWidget(m_tbnVoice);
    m_mainLayout->addWidget(m_tbnSoundEffect);
    m_mainLayout->addWidget(m_tbnMusicWords);
    m_mainLayout->addWidget(m_tbnMusicPlayQueue);
    m_mainLayout->addWidget(m_label_misic_num);
    m_mainLayout->addSpacing(20);

    m_mainLayout->setContentsMargins(0,10,0,20);
    setLayout(m_mainLayout);
}

//信号和槽的关联
void BottomWidget::initConnect()
{
    connect(m_tbnPerious,SIGNAL(clicked(bool)),
            this,SIGNAL(signalPreious()));
    connect(m_tbnPlay,SIGNAL(clicked(bool)),
            this,SIGNAL(signalPlay()));
    connect(m_tbnNext,SIGNAL(clicked(bool)),
            this,SIGNAL(signalNext()));

    //循环模式信号和槽连接
    connect(m_tbnCircleMode,SIGNAL(clicked(bool)),
            m_playMode,SLOT(slotMenuVisiable()));
}

