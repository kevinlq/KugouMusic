#include "playmusicwidget.h"
#include "core/musicabstractremotebutton.h"
#include <QSlider>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "controlvalues.h"

PlayMusicWidget::PlayMusicWidget(QWidget *parent)
    :AbstractWidget(parent)
{
    initForm();
    initLayout();
}

PlayMusicWidget::~PlayMusicWidget()
{
    delete m_tbnPlay;
}

void PlayMusicWidget::initForm()
{
    m_tbnPlay = new MusicAbstractRemoteButton(this,
                ":/image/remote/play.png",QString::fromLocal8Bit("²¥·Å"));
    m_noVoice = new MusicAbstractRemoteButton(this,
                ":/image/remote/voice.png",QString::fromLocal8Bit("¾²Òô"));
    m_noVoice->setFixedSize(24,24);
    m_musicSlitter = new QSlider(Qt::Horizontal,this);
    m_musicSlitter->setObjectName("musicVoice");
    m_musicSlitter->setValue(VOICE_DEFAULT_VALUE);
}

void PlayMusicWidget::initLayout()
{
    QHBoxLayout *m_voiceHbLayout = new QHBoxLayout();
    m_voiceHbLayout->addWidget(m_noVoice);
    m_voiceHbLayout->addWidget(m_musicSlitter);
    m_voiceHbLayout->setContentsMargins(0,0,0,0);

    QVBoxLayout *m_voiceVbLayout = new QVBoxLayout(this);
    m_voiceVbLayout->addWidget(m_tbnPlay,4,Qt::AlignCenter);
    m_voiceVbLayout->addLayout(m_voiceHbLayout);
    m_voiceVbLayout->setContentsMargins(1,12,1,1);
    setLayout(m_voiceVbLayout);
}

void PlayMusicWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(QColor(61,61,61));
    painter.drawRect(this->rect());
}

