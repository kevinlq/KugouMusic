#include "radiowidget.h"
#include <QLabel>
#include <QVBoxLayout>

RadioWidget::RadioWidget(QWidget *parent)
    : QWidget(parent)
{
    m_label = new QLabel(this);
    m_label->setStyleSheet("border-image:url(:/image/radio_widget.png)");

    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addWidget(m_label);
    setLayout(m_mainLayout);
}

RadioWidget::~RadioWidget()
{
}

