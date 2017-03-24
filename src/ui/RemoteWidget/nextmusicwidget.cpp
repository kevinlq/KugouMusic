#include "nextmusicwidget.h"
#include "core/musicabstractremotebutton.h"
#include <QVBoxLayout>

NextMusicWidget::NextMusicWidget(QWidget *parent)
    :AbstractWidget(parent)
{
    m_tbnNextMusic = new MusicAbstractRemoteButton(this,
              ":/image/remote/next.png",QString::fromLocal8Bit("ÏÂÒ»Ê×"));

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(m_tbnNextMusic,4,Qt::AlignCenter);
    mainLayout->setContentsMargins(10,10,10,10);
}

NextMusicWidget::~NextMusicWidget()
{
    delete m_tbnNextMusic;
}

