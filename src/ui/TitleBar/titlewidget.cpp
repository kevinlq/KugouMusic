/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-09
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---标题栏的实现
**************************************************/
#include "titlewidget.h"
#include "searchlineedit.h"
#include "mymenu.h"
#include "iconhelper.h"
#include "Common/pushbutton.h"
#include "RemoteWidget/remotewidget.h"  //遥控器

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

TitleWidget::TitleWidget(QWidget *parent) : QWidget(parent)
{
    this->initWidget();
    this->initForm();
    this->initConnect();
}

TitleWidget::~TitleWidget()
{
}

//翻译标题栏
void TitleWidget::Translator()
{
    m_menu->translator();

    m_TbnLogin->setText(tr("tbn_login"));
    m_TbnRegister->setText(tr("tbn_register"));

    m_TbnLogin->setToolTip(tr("login"));
    m_TbnRegister->setToolTip(tr("register"));

    m_TbnGame->setToolTip(tr("tbn_game"));
    m_TbnNews->setToolTip(tr("tbn_news"));
    m_TbnSkin->setToolTip(tr("tbn_skin"));

    m_TbnMenu->setToolTip(tr("tbn_menu"));
    m_TbnRemote->setToolTip(tr("tbn_start_remote"));
    m_TbnMenu_close->setToolTip(tr("tbn_close"));
    m_TbnMenu_max->setToolTip(tr("tbn_max"));
    m_TbnMenu_min->setToolTip(tr("tbn_min"));
}

void TitleWidget::slotChangeBtnStatus(int status)
{
    switch (status)
    {
    case BtnMax:
        m_TbnMenu_max->setToolTip(tr("tbn_show_max"));
        IconHelper::Instance()->SetIcon(m_TbnMenu_max, QChar(0xf0b2), 10);
        break;
    case BtnMin:
        m_TbnMenu_max->setToolTip(tr("tbn_restore"));
        IconHelper::Instance()->SetIcon(m_TbnMenu_max, QChar(0xf079), 10);
        break;
    default:
        break;
    }
}

//显示或者隐藏遥控器
void TitleWidget::slotOpenOrHideRemote()
{
    if (m_isOpenRemote)
    {
        m_remoteWidget->show();
    }else
    {
        m_remoteWidget->hide();
    }
    m_isOpenRemote = !m_isOpenRemote;
}

//隐藏遥控器
void TitleWidget::slotHideRemote()
{
    m_remoteWidget->hide();
    m_isOpenRemote = true;
}

void TitleWidget::initForm()
{
    this->setMaximumHeight(50);
    this->setFocusPolicy(Qt::ClickFocus);       //设置鼠标点击切换焦点

    IconHelper::Instance()->SetIcon(m_labelIcon,QChar(0xf169), 14);

    IconHelper::Instance()->SetIcon(m_TbnGame,QChar(0xf0e4),12);
    IconHelper::Instance()->SetIcon(m_TbnNews,QChar(0xf003),12);
    IconHelper::Instance()->SetIcon(m_TbnRemote,QChar(0xf10b),12);

    IconHelper::Instance()->SetIcon(m_TbnMenu,QChar(0xf013), 12);
    IconHelper::Instance()->SetIcon(m_TbnMenu_max,QChar(0xf0b2), 12);

    m_TbnLogin->setStyleSheet("color:#FDF7F7");
    m_TbnLogin->setCursor(Qt::PointingHandCursor);
    m_TbnRegister->setStyleSheet("color:#FDF7F7");
    m_TbnRegister->setCursor(Qt::PointingHandCursor);
    m_TbnSkin->setObjectName("pbnSkin");
    m_TbnMenu->setObjectName("pbnMenu");
    m_TbnMenu_min->setObjectName("pbnMin");
    m_TbnMenu_max->setObjectName("pbnMax");
    m_TbnMenu_close->setObjectName("pbnClose");

    m_isOpenRemote = true;
}

void TitleWidget::initWidget()
{
    m_labelIcon = new QLabel(this);

    //登录和注册
    m_TbnLogin = new PushButton(this);
    m_label_div = new QLabel(this);
    m_label_div->setFixedSize(1,16);
    m_label_div->setStyleSheet("background-color:#FDF7F7");
    m_TbnRegister = new PushButton(this);

    //搜索框
    m_search = new SearchLineEdit(this);

    m_TbnGame = new PushButton(this);          //游戏
    m_TbnNews = new PushButton(this);          //消息通知
    m_TbnSkin = new PushButton(this);          //皮肤

    //创建菜单按钮
    m_TbnMenu = new PushButton(this);
    m_TbnRemote = new PushButton(this);        //遥控器
    m_TbnMenu_min = new PushButton(this);
    m_TbnMenu_max = new PushButton(this);
    m_TbnMenu_close = new PushButton(this);

    //标题栏布局
    m_mainLayout = new QHBoxLayout(this);
    m_mainLayout->addSpacing(20);
    m_mainLayout->addWidget(m_labelIcon);
    m_mainLayout->addSpacing(10);
    m_mainLayout->addWidget(m_TbnLogin);
    m_mainLayout->addWidget(m_label_div);
    m_mainLayout->addWidget(m_TbnRegister);
    m_mainLayout->addSpacing(220);
    m_mainLayout->addWidget(m_search);
    m_mainLayout->addStretch();

    m_mainLayout->addWidget(m_TbnGame);
    m_mainLayout->addWidget(m_TbnNews);
    m_mainLayout->addWidget(m_TbnSkin);
    m_mainLayout->addSpacing(10);
    m_mainLayout->addWidget(m_TbnMenu);
    m_mainLayout->addWidget(m_TbnRemote);
    m_mainLayout->addWidget(m_TbnMenu_min);
    m_mainLayout->addWidget(m_TbnMenu_max);
    m_mainLayout->addWidget(m_TbnMenu_close);
    m_mainLayout->addSpacing(6);
    m_mainLayout->setContentsMargins(0,20,0,0);

    this->setLayout(m_mainLayout);

    m_menu = new MyMenu(this);
    m_TbnMenu->setMenu(m_menu);

    m_remoteWidget = new RemoteWidget();
}

//初始化信号和槽的连接
void TitleWidget::initConnect()
{
    connect(m_TbnMenu,SIGNAL(clicked(bool)),
            m_menu,SLOT(slotMenuVisiable()));

    connect(m_TbnMenu_max,SIGNAL(clicked(bool)),
            this,SIGNAL(signalMax()));
    connect(m_TbnMenu_min,SIGNAL(clicked(bool)),
            this,SIGNAL(signalMix()));
    connect(m_TbnMenu_close,SIGNAL(clicked(bool)),
            this,SIGNAL(signalHideWidget()));

    //关联主菜单Action信号
    connect(m_menu,SIGNAL(signal_quit()),
            this,SIGNAL(signalClose()));

    connect(m_TbnSkin,SIGNAL(clicked(bool)),
            this,SIGNAL(signalShowSkin()));
    //关联遥控器信号
    connect(m_TbnRemote,SIGNAL(clicked(bool)),
            this,SLOT(slotOpenOrHideRemote()));
    connect(m_remoteWidget,SIGNAL(signalShowOrHidMainWidget(int)),
            this,SIGNAL(signalShowOrHideWidget(int)));
    connect(m_remoteWidget,SIGNAL(signalHideRemote()),
            this,SLOT(slotHideRemote()));
}

