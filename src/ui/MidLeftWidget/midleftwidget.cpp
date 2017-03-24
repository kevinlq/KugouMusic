/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-10
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--中间窗体部分--左边歌曲列表界面
**************************************************/
#include "midleftwidget.h"
#include "localList/locallistwidget.h"              //本地列表
#include "networkCollect/networkcollectwidget.h"    //网络收藏
#include "musicRadio/musicradiowidget.h"            //音乐电台
#include "phoneManage/phonemanagewidget.h"          //手机管理
#include "download/downloadwidget.h"                //本地音乐
#include "moreTools/moretoolwidget.h"               //更多功能界面

#include <QPainter>
#include <QPen>
#include <QVBoxLayout>
#include <QStackedWidget>

MidLeftWidget::MidLeftWidget(QWidget *parent) : QWidget(parent)
{
    this->initWidget();
    this->initForm();
    this->initConnect();
}

void MidLeftWidget::slotShowLocalList()
{
    m_stackedWidget->setCurrentIndex(LOCAL_LIST);
}

void MidLeftWidget::slotShowNetCollect()
{
    m_stackedWidget->setCurrentIndex(NETWORK_COLLECT);
}

void MidLeftWidget::slotShowMusicRadio()
{
    m_stackedWidget->setCurrentIndex(MUSIC_RADIO);
}

void MidLeftWidget::slotShowPhoneManage()
{
    m_stackedWidget->setCurrentIndex(PHONE_MANAGE);
}

void MidLeftWidget::slotShowLocalMusic()
{
    m_stackedWidget->setCurrentIndex(LOCAL_MUSIC);
}

void MidLeftWidget::slotShowMoreTool()
{
    m_stackedWidget->setCurrentIndex(MORE_TOOL);
}

void MidLeftWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen objPen(Qt::transparent);
    painter.setPen(objPen);
    QBrush objBrush(QColor(255,255,255,180));
    painter.setBrush(objBrush);
    painter.drawRect(this->rect());
}

void MidLeftWidget::initForm()
{
    this->setFixedWidth(310);
}

void MidLeftWidget::initWidget()
{
    m_stackedWidget = new QStackedWidget(this);

    m_localListWidget = new LocalListWidget();
    m_netWorkWidget = new NetWorkCollectWidget();
    m_musicRadioWidget = new MusicRadioWidget();
    m_localListWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    m_phonoeManage = new PhoneManageWidget();
    m_download = new DownloadWidget();
    m_moreTool = new MoreToolWidget();

    m_stackedWidget->addWidget(m_localListWidget);  //本地列表
    m_stackedWidget->addWidget(m_netWorkWidget);    //网络收藏
    m_stackedWidget->addWidget(m_musicRadioWidget); //音乐电台
    m_stackedWidget->addWidget(m_phonoeManage);     //手机管理
    m_stackedWidget->addWidget(m_download);         //本地音乐
    m_stackedWidget->addWidget(m_moreTool);         //更多

    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addWidget(m_stackedWidget);
    m_mainLayout->setContentsMargins(0,0,0,0);
    this->setLayout(m_mainLayout);
}

void MidLeftWidget::initConnect()
{
}

