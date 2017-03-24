#include "desktopphotowidget.h"
#include "core/musicabstractremotebutton.h"
#include <QVBoxLayout>

DesktopPhotoWidget::DesktopPhotoWidget(QWidget *parent)
    :AbstractWidget(parent)
{
    m_tbnDesktop = new MusicAbstractRemoteButton(this,
              ":/image/remote/desktop.png",QString::fromLocal8Bit("¿ªÆô×ÀÃæÐ´Õæ"));

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(m_tbnDesktop,4,Qt::AlignCenter);
    mainLayout->setContentsMargins(10,10,10,10);
}

DesktopPhotoWidget::~DesktopPhotoWidget()
{
    delete m_tbnDesktop;
}

