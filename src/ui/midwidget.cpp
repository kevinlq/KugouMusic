#include "midwidget.h"
#include <QPainter>
#include <QPen>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "iconhelper.h"
#include "MidLeftWidget/midleftwidget.h"
#include "MidRightWidget/midrightwidget.h"


MidWidget::MidWidget(QWidget *parent) : QWidget(parent)
{
    this->initWidget();
    this->initForm();
    this->initConnect();
    this->translator();
}

void MidWidget::translator()
{
    m_rightWidget->translator();
}

void MidWidget::slotOnZoomBtnClicked()
{
    if(flag_status)
    {
        flag_status = false;
        m_leftWidget->setVisible(true);
        m_zoomBtn->setIcon(QIcon(":/image/lrc/lrc_displayNor"));
    }else
    {
        flag_status = true;
        m_leftWidget->setVisible(false);
        m_zoomBtn->setIcon(QIcon(":/image/lrc/lrc_displayAll"));
    }
}

//设置分割条是否显示
void MidWidget::slotSetSplitterVisible(bool value)
{
    m_zoomBtn->setVisible(value);
}


void MidWidget::initForm()
{
    flag_status = false;

    m_zoomBtn->setIcon(QIcon(":/image/lrc/lrc_displayAll"));
    m_zoomBtn->setIconSize(QPixmap(":/image/lrc/lrc_displayAll").size());
    m_zoomBtn->setCursor(Qt::PointingHandCursor);

}

void MidWidget::initWidget()
{
    m_leftWidget = new MidLeftWidget(this);
    m_rightWidget = new MidRightWidget(this);

    //界面切换按钮初始化设置
    m_zoomBtn = new QPushButton(this);
    m_zoomBtn->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    m_zoomBtn->setFixedWidth(15);
    m_zoomBtn->setFixedHeight(60);
    m_zoomBtn->setFocusPolicy(Qt::NoFocus);
    m_zoomBtn->setObjectName("pbn_zoom");

    QVBoxLayout *vbLayout = new QVBoxLayout;
    vbLayout->addStretch();
    vbLayout->addWidget(m_zoomBtn);
    vbLayout->addStretch();
    vbLayout->setContentsMargins(0,0,0,0);

    m_mainLayout = new QHBoxLayout(this);
    m_mainLayout->addWidget(m_leftWidget);
    m_mainLayout->addLayout(vbLayout);
    m_mainLayout->addWidget(m_rightWidget);
    m_mainLayout->setContentsMargins(0,0,0,0);
    this->setLayout(m_mainLayout);
}

//信号和槽的关联
void MidWidget::initConnect()
{
    connect(m_zoomBtn,SIGNAL(clicked(bool)),
            this,SLOT(slotOnZoomBtnClicked()));
    connect(m_rightWidget,SIGNAL(signalShowSplitter(bool)),
            this,SLOT(slotSetSplitterVisible(bool)));

    connect(this,SIGNAL(signalLocalList()),
            m_leftWidget,SLOT(slotShowLocalList()));
    connect(this,SIGNAL(signalNetCollect()),
            m_leftWidget,SLOT(slotShowNetCollect()));
    connect(this,SIGNAL(signalMusicRadio()),
            m_leftWidget,SLOT(slotShowMusicRadio()));
    connect(this,SIGNAL(signalPhoneManage()),
            m_leftWidget,SLOT(slotShowPhoneManage()));
    connect(this,SIGNAL(signalLocalMusic()),
            m_leftWidget,SLOT(slotShowLocalMusic()));
    connect(this,SIGNAL(signalMoreTool()),
            m_leftWidget,SLOT(slotShowMoreTool()));
}

