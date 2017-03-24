/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-15
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--皮肤与窗口调整界面
**************************************************/
#include "skinwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QWidgetAction>
#include <QCheckBox>
#include <QComboBox>
#include <QStackedWidget>

#include "controlvalues.h"
#include "Common/pushbutton.h"

SkinWidget::SkinWidget(QWidget *parent)
    :DropShadowWidget(parent)
{
    this->initWidget();
    this->initLayout();
    this->initForm();
    this->initConnect();
    this->translator();
}

SkinWidget::~SkinWidget()
{

}

void SkinWidget::translator()
{
    m_labelTitle->setText(tr("skin_and_widget_adjust"));
    m_pbnClose->setToolTip(tr("pbn_close"));

    m_labelListTransparent->setText(tr("list_transparent"));

    m_ckxSkinTr->setText(tr("check_skin_transparent"));
    m_PbnPalette->setText(tr("plette"));
    m_pbnCustom->setText(tr("custom_skin"));
}

void SkinWidget::slotClose()
{
    this->hide();
}

void SkinWidget::initForm()
{
    this->resize(600,380);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet(QString("QWidget#titleWidget{background-image:url(:/image/skin/%1);"
                          "border:1px solid black;}").arg(DEFAULT_SKIN));

    m_pbnRecoSkin->setText(tr("RecoSkin"));
    m_pbnMySkin->setText(tr("MySkin"));
    m_pbnRecover->setText(tr("recocerStatus"));
    m_titleWidget->setFixedHeight(40);
    m_cbxTrValue->addItem("10");
    m_cbxSkValue->addItem("0%");
}

void SkinWidget::initWidget()
{
    m_titleWidget = new QWidget(this);
    m_titleWidget->setObjectName("titleWidget");
    m_titleWidget->setContentsMargins(0,0,0,0);
    m_labelTitle = new QLabel(this);
    m_labelTitle->setObjectName("whitelabel");
    m_pbnClose = new PushButton(this);
    m_pbnClose->setObjectName("pbnClose");

    m_pbnRecoSkin = new QPushButton(this);
    m_pbnMySkin = new QPushButton(this);
    m_pbnRecover = new QPushButton(this);

    m_stackenWidget = new QStackedWidget(this);
    m_center_layout = new QGridLayout();
    m_listSkin <<":/image/skin/0.png"<<":/image/skin/1.png";

    m_labelListTransparent = new QLabel(this);
    m_cbxTrValue = new QComboBox(this);
    m_ckxSkinTr = new QCheckBox(this);
    m_cbxSkValue = new QComboBox(this);
    m_PbnPalette = new QPushButton(this);
    m_pbnCustom = new QPushButton(this);

}

void SkinWidget::initLayout()
{
    m_titleLayout = new QHBoxLayout(m_titleWidget);
    m_titleLayout->addSpacing(3);
    m_titleLayout->addWidget(m_labelTitle,0,Qt::AlignCenter);
    m_titleLayout->addStretch();
    m_titleLayout->addWidget(m_pbnClose);
    m_titleLayout->setContentsMargins(6,0,6,0);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addSpacing(15);
    layout->addWidget(m_pbnRecoSkin);
    layout->addWidget(m_pbnMySkin);
    layout->addStretch();
    layout->addWidget(m_pbnRecover);
    layout->addSpacing(20);
    layout->setContentsMargins(0,0,0,0);

    m_bottomLayout = new QHBoxLayout;
    m_bottomLayout->addSpacing(10);
    m_bottomLayout->addWidget(m_labelListTransparent);
    m_bottomLayout->addWidget(m_cbxTrValue);
    m_bottomLayout->addStretch();
    m_bottomLayout->addWidget(m_ckxSkinTr);
    m_bottomLayout->addWidget(m_cbxSkValue);
    m_bottomLayout->addStretch();
    m_bottomLayout->addWidget(m_PbnPalette);
    m_bottomLayout->addWidget(m_pbnCustom);
    m_bottomLayout->addSpacing(14);
    m_bottomLayout->setContentsMargins(0,0,0,0);

    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addWidget(m_titleWidget);
    m_mainLayout->addLayout(layout);
    m_mainLayout->addWidget(m_stackenWidget);
    m_mainLayout->addLayout(m_bottomLayout);
    m_mainLayout->setContentsMargins(6,6,6,20);
    setLayout(m_mainLayout);
}

//信号与槽初始化
void SkinWidget::initConnect()
{
    connect(m_pbnClose,SIGNAL(clicked(bool))
            ,this,SLOT(slotClose()));
}

