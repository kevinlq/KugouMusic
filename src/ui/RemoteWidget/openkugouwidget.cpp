#include "openkugouwidget.h"
#include "core/musicabstractremotebutton.h"
#include <QVBoxLayout>

OpenKugouWidget::OpenKugouWidget(QWidget *parent)
    :AbstractWidget(parent)
{
    m_tbOpenKugou = new MusicAbstractRemoteButton(this,
              ":/image/remote/kugou.png",QString::fromLocal8Bit("´ò¿ª¿á¹·ÒôÀÖ"));

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(m_tbOpenKugou,4,Qt::AlignCenter);
    mainLayout->setContentsMargins(10,10,10,10);
}

OpenKugouWidget::~OpenKugouWidget()
{
    delete m_tbOpenKugou;
}
