#include "musiclyricwidget.h"
#include <QPalette>
#include <QLabel>
#include <QVBoxLayout>

MusicLyricWidget::MusicLyricWidget(QWidget *parent) : QWidget(parent)
{
    this->initWidget();
    this->initForm();
}

void MusicLyricWidget::paintEvent(QPainter *)
{
    QPalette bgpal = palette();
    bgpal.setColor(QPalette::Background,QColor(0,0,0,255));
    bgpal.setColor(QPalette::Foreground,QColor(255,255,255,255));
    setPalette(bgpal);
}

void MusicLyricWidget::initForm()
{
}

void MusicLyricWidget::initWidget()
{
    m_label = new QLabel(this);

    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addWidget(m_label);
    m_mainLayout->setContentsMargins(0,0,0,0);
    this->setLayout(m_mainLayout);
}

