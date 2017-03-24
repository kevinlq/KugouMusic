#include "phonemanagewidget.h"
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include "Common/pushbutton.h"

PhoneManageWidget::PhoneManageWidget(QWidget *parent)
    : QWidget(parent)
{
    this->initWidget();
    this->initForm();
    this->initConnect();
}

void PhoneManageWidget::slotShowHomeWidget()
{
    m_pbnReturn->setVisible(false);
    m_stackedWidget->setCurrentIndex(HomeWidget);
}

void PhoneManageWidget::slotShowWiredWidget()
{
    m_pbnReturn->setVisible(true);
    m_stackedWidget->setCurrentIndex(WiredWidget);
}

void PhoneManageWidget::slotShowWirelessWidget()
{
    m_pbnReturn->setVisible(true);
    m_stackedWidget->setCurrentIndex(WirelessWidget);
}

void PhoneManageWidget::initForm()
{
    m_pbnReturn->setObjectName("pbnReturn");
    m_pbnReturn->setText(QString::fromLocal8Bit("返回"));
    m_pbnReturn->setFixedSize(40,20);
    m_pbnReturn->setFlat(true);
    m_pbnReturn->setCursor(Qt::PointingHandCursor);
    m_pbnReturn->setVisible(false);
    this->setStyleSheet("QPushButton#pbnReturn:hover{background-color(10,120,0)}");

    m_labelConnectWay->setText(QString::fromLocal8Bit("请选择连接手机的方式"));
    m_labelConnectWay->setFont(QFont("Times", 12, QFont::Bold));
    m_pbnWiredConnect->setText(QString::fromLocal8Bit("有线连接"));
    m_pbnWiredConnect->setFixedSize(190,100);
    m_pbnWiredConnect->setObjectName("pbnWhite");
    m_pbnWirelessConnect->setText(QString::fromLocal8Bit("无线连接"));
    m_pbnWirelessConnect->setFixedSize(190,100);
    m_pbnWirelessConnect->setObjectName("pbnWhite");

    m_pbnWiredConnect->setFont(QFont("Times", 12, QFont::Bold));
    m_pbnWirelessConnect->setFont(QFont("Times", 12, QFont::Bold));
}

void PhoneManageWidget::initWidget()
{
    m_stackedWidget = new QStackedWidget(this);
    m_pbnReturn = new QPushButton(this);
    m_labelConnectWay = new QLabel(m_stackedWidget);

    m_homeWidget = new QWidget(this);

    m_pbnWiredConnect = new QPushButton(m_homeWidget);
    m_pbnWirelessConnect = new QPushButton(m_homeWidget);

    m_wireWidget = new QWidget;
    m_wirelessWidget = new QWidget;

    this->initWiredWidget();
    this->initWirelessWidget();

    QGridLayout *homeLayout = new QGridLayout(m_homeWidget);
    homeLayout->addWidget(m_labelConnectWay,0,1,1,1,Qt::AlignCenter);
    homeLayout->addWidget(m_pbnWiredConnect,1,1);
    homeLayout->addWidget(m_pbnWirelessConnect,2,1);
    homeLayout->setSpacing(40);
    homeLayout->setContentsMargins(0,0,0,0);

    m_stackedWidget->addWidget(m_homeWidget);
    m_stackedWidget->addWidget(m_wireWidget);
    m_stackedWidget->addWidget(m_wirelessWidget);

    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addWidget(m_pbnReturn);
    m_mainLayout->addStretch();
    m_mainLayout->addWidget(m_stackedWidget);
    m_mainLayout->addStretch();
    setLayout(m_mainLayout);
}

void PhoneManageWidget::initWiredWidget()
{
    QLabel *labelIcon = new QLabel(m_wireWidget);
    QLabel *labelWay = new QLabel(QString::fromLocal8Bit("使用数据线连接"),m_wireWidget);
    QLabel *androidPhone = new QLabel(QString::fromLocal8Bit("安卓手机请打开USB调试助手"),m_wireWidget);
    QLabel *iosPhone = new QLabel(QString::fromLocal8Bit("苹果手机请在手机上信任该电脑"),m_wireWidget);


    labelWay->setFont(QFont("Times", 14, QFont::Bold));
    labelIcon->setMinimumSize(290,150);
    labelIcon->setStyleSheet("border-image:url(:/image/moreTool/wire/wire.png)");

    QVBoxLayout *layout = new QVBoxLayout(m_wireWidget);
    layout->addWidget(labelIcon,0,Qt::AlignCenter);
    layout->addWidget(labelWay,0,Qt::AlignCenter);
    layout->addWidget(androidPhone,0,Qt::AlignCenter);
    layout->addWidget(iosPhone,0,Qt::AlignCenter);
}

void PhoneManageWidget::initWirelessWidget()
{
    QLabel *labelScan = new QLabel(QString::fromLocal8Bit("手机酷狗扫码连接"),m_wirelessWidget);
    QLabel *labelIcon = new QLabel(m_wirelessWidget);
    QLabel *labelInfo1 = new QLabel(QString::fromLocal8Bit("手机和电脑在同意wifi网络下"),m_wirelessWidget);
    QLabel *labelInfo2 = new QLabel(QString::fromLocal8Bit("使用手机酷狗扫描二维码，如何扫描?"),m_wirelessWidget);

    labelScan->setFont(QFont("Times", 14, QFont::Bold));
    labelIcon->setMinimumSize(117,116);
    labelIcon->setStyleSheet("border-image:url(:/image/moreTool/wireless/wireless.png)");

    QVBoxLayout *vbLayout = new QVBoxLayout(m_wirelessWidget);
    vbLayout->addWidget(labelScan,0,Qt::AlignCenter);
    vbLayout->addWidget(labelIcon,0,Qt::AlignCenter);
    vbLayout->addWidget(labelInfo1,0,Qt::AlignCenter);
    vbLayout->addWidget(labelInfo2,0,Qt::AlignCenter);
    vbLayout->setContentsMargins(0,0,0,0);
}

void PhoneManageWidget::initConnect()
{
    connect(m_pbnWiredConnect,SIGNAL(clicked(bool)),
            this,SLOT(slotShowWiredWidget()));
    connect(m_pbnReturn,SIGNAL(clicked(bool)),
            this,SLOT(slotShowHomeWidget()));
    connect(m_pbnWirelessConnect,SIGNAL(clicked(bool)),
            this,SLOT(slotShowWirelessWidget()));
}

