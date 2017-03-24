#include "previousmusicwidget.h"
#include "core/musicabstractremotebutton.h"
#include <QVBoxLayout>

PreviousMusicWidget::PreviousMusicWidget(QWidget *parent)
    :AbstractWidget(parent)
{
    m_tbnPreviousMusic = new MusicAbstractRemoteButton(this,
              ":/image/remote/previous.png",QString::fromLocal8Bit("ÉÏÒ»Ê×"));

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addWidget(m_tbnPreviousMusic,4,Qt::AlignCenter);
    mainLayout->addStretch();
    mainLayout->setContentsMargins(10,0,10,0);
}

PreviousMusicWidget::~PreviousMusicWidget()
{
    delete m_tbnPreviousMusic;
}

