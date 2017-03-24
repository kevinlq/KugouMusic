#include "musicabstractremotewidget.h"
#include <QMouseEvent>

MusicAbstractRemoteWidget::MusicAbstractRemoteWidget(QWidget *parent)
    :QWidget(parent)
{
    initForm();
}

MusicAbstractRemoteWidget::~MusicAbstractRemoteWidget()
{
}

void MusicAbstractRemoteWidget::initForm()
{
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setObjectName("abstractWidget");

    m_location = geometry();
    m_isPressed = false;        //默认鼠标没有按下
    //setStyleSheet("background-color:#3D3D3D;");
    //setStyleSheet("QWidget#abstractWidget{border:2px groove gray;border-radius:10px;padding:2px 4px;}");
}

void MusicAbstractRemoteWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (m_isPressed && e->buttons() && Qt::LeftButton)
    {
        move(e->globalPos() - m_point);
        e->accept();
    }
}

void MusicAbstractRemoteWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_point = e->globalPos() - pos();
        m_isPressed = true;
        e->accept();
    }
}

void MusicAbstractRemoteWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_isPressed = false;
    }
}

