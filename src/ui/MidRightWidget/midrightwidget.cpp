/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-10
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--中间窗体部分--右边部分
**************************************************/
#include "midrightwidget.h"
#include <QPainter>
#include <QPen>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QToolButton>
#include <QStackedWidget>
#include <QtDebug>

#include "radioWidget/radiowidget.h"    //电台界面
#include "mvwidget.h"                   //MV界面
#include "musiclyricwidget.h"           //歌词界面
#include "iconhelper.h"
#include "Common/toolbutton.h"

MidRightWidget::MidRightWidget(QWidget *parent) : QWidget(parent)
{
    this->initWidget();
    this->initForm();
    this->initConnect();
}

void MidRightWidget::translator()
{
    m_tbnReturn->setToolTip(tr("return"));
    m_tbnRefresh->setToolTip(tr("refresh"));
    m_tbnMusicLibrary->setText(tr("tbn_music_library"));
    m_tbnMusicLibrary->setToolTip(tr("new_music_new_in"));
    m_tbnRadio->setText(tr("tbn_radio"));
    m_tbnRadio->setToolTip(tr("enjoyment_brilliant"));
    m_tbnMusicList->setText(tr("tbn_music_list"));
    m_tbnMusicList->setToolTip(tr("more_music_list"));
    m_tbnMV->setText(tr("tbn_mv"));
    m_tbnMV->setToolTip(tr("more_mv"));
    m_tbnTelecase->setText(tr("tbn_telecase"));
    m_tbnTelecase->setToolTip(tr("online_telecase"));
    m_tbnMusicWord->setText(tr("tbn_music_word"));
    m_tbnMusicWord->setToolTip(tr("accurate_music"));
}

void MidRightWidget::paintEvent(QPaintEvent *)
{
//    QPainter painter(this);
//    QPen objPen(Qt::transparent);
//    painter.setPen(objPen);
//    QBrush objBrush(QColor(255,255,255,120));
//    painter.setBrush(objBrush);
    //    painter.drawRect(this->rect());
}

bool MidRightWidget::event(QEvent *event)
{
    if (event->type() == QEvent::ToolTip)
    {
        qDebug()<<"tool";
    }
    return QWidget::event(event);
}

void MidRightWidget::initForm()
{
    m_vecTbn.push_back(m_tbnMusicLibrary);
    m_vecTbn.push_back(m_tbnRadio);
    m_vecTbn.push_back(m_tbnMusicList);
    m_vecTbn.push_back(m_tbnMV);
    m_vecTbn.push_back(m_tbnTelecase);
    m_vecTbn.push_back(m_tbnMusicWord);

    //设置按钮只有一个被选中
    for (int i = 0; i != m_vecTbn.size();i++)
    {
        m_vecTbn.at(i)->setFixedSize(60,30);
        m_vecTbn.at(i)->setFont(QFont("Times", 12, QFont::Bold));
        m_vecTbn.at(i)->setCursor(Qt::PointingHandCursor);
        m_vecTbn.at(i)->setAutoRaise(true);
        m_vecTbn.at(i)->setCheckable(true);
        m_vecTbn.at(i)->setAutoExclusive(true);
    }

    //设置【返回】和【刷新】按钮样式
    m_tbnReturn->setAutoRaise(true);
    m_tbnReturn->setCursor(Qt::PointingHandCursor);
    m_tbnRefresh->setAutoRaise(true);
    m_tbnRefresh->setCursor(Qt::PointingHandCursor);

    m_tbnReturn->setFixedSize(40,30);
    m_tbnRefresh->setFixedSize(40,30);
    //设置【返回】和【刷新】按钮图标
    m_tbnReturn->setIcon(QIcon(":/image/return/return.png"));
    m_tbnRefresh->setIcon(QIcon(":/image/update/update.png"));

    //顶部按钮背景色
    //m_toolWidget->setStyleSheet("background-color:#373B43;");
}

void MidRightWidget::initWidget()
{
    m_toolWidget = new QWidget(this);

    m_tbnReturn = new ToolButton(m_toolWidget);        //返回
    m_tbnRefresh = new ToolButton(m_toolWidget);       //刷新
    m_tbnMusicLibrary = new ToolButton(m_toolWidget);  //乐库
    m_tbnRadio = new ToolButton(m_toolWidget);         //电台
    m_tbnMusicList = new ToolButton(m_toolWidget);     //歌单
    m_tbnMV = new ToolButton(m_toolWidget);            //MV
    m_tbnTelecase = new ToolButton(m_toolWidget);      //直播
    m_tbnMusicWord = new ToolButton(m_toolWidget);     //歌词

    m_radioWidget = new RadioWidget;
    m_mvWidget = new MvWidget;
    m_lyricWidget = new MusicLyricWidget;         //歌词界面

    m_stackedWidget = new QStackedWidget(this);
    m_stackedWidget->addWidget(m_radioWidget);
    m_stackedWidget->addWidget(m_lyricWidget);
    m_stackedWidget->addWidget(m_mvWidget);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(m_tbnReturn);
    layout->addWidget(m_tbnRefresh);
    layout->setContentsMargins(8,0,0,0);

    m_tabLayout = new QHBoxLayout(m_toolWidget);
    m_tabLayout->addLayout(layout);
    m_tabLayout->addStretch();
    m_tabLayout->addWidget(m_tbnMusicLibrary);
    m_tabLayout->addSpacing(3);
    m_tabLayout->addWidget(m_tbnRadio);
    m_tabLayout->addSpacing(3);
    m_tabLayout->addWidget(m_tbnMusicList);
    m_tabLayout->addSpacing(3);
    m_tabLayout->addWidget(m_tbnMV);
    m_tabLayout->addSpacing(3);
    m_tabLayout->addWidget(m_tbnTelecase);
    m_tabLayout->addSpacing(3);
    m_tabLayout->addWidget(m_tbnMusicWord);
    m_tabLayout->addStretch();
    m_tabLayout->setContentsMargins(0,10,0,0);

    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addWidget(m_toolWidget);
    m_mainLayout->addWidget(m_stackedWidget);
    m_mainLayout->setContentsMargins(0,0,0,0);
    this->setLayout(m_mainLayout);
}

void MidRightWidget::initConnect()
{
    connect(m_tbnRadio,SIGNAL(clicked(bool)),
            this,SLOT(slotShowRadioWidget()));
    connect(m_tbnMusicWord,SIGNAL(clicked(bool)),
            this,SLOT(slotShowLyric()));
    connect(m_tbnMV,SIGNAL(clicked(bool)),
            this,SLOT(slotShowMV()));
}

void MidRightWidget::slotShowRadioWidget()
{
    m_stackedWidget->setCurrentIndex(0);
}

void MidRightWidget::slotShowLyric()
{
    emit signalShowSplitter(true);
    m_stackedWidget->setCurrentIndex(1);
}

void MidRightWidget::slotShowMV()
{
    emit signalShowSplitter(false);
    m_stackedWidget->setCurrentIndex(2);
}

