/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-2-29
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:ÒôÀÖ²¥·ÅÆ÷---ËÑË÷¿òÊó±êÓÒ¼ü²Ëµ¥µÄÊµÏÖ
**************************************************/
#include "rightmenu.h"

RightMenu::RightMenu(QWidget *parent)
    :Menu(parent)
{
    this->initForm();
    this->initConnect();
    this->translator();
}

RightMenu::~RightMenu()
{

}

void RightMenu::translator()
{
    m_clip->setText(QString::fromLocal8Bit("¼ôÌù"));
    m_copy->setText(QString::fromLocal8Bit("¸´ÖÆ"));
    m_paste->setText(QString::fromLocal8Bit("Õ³Ìù"));
    m_delete->setText(QString::fromLocal8Bit("É¾³ý"));
    m_selectAll->setText(QString::fromLocal8Bit("È«Ñ¡"));
}

void RightMenu::initForm()
{
    m_clip = new QAction(this);
    m_copy = new QAction(this);
    m_paste = new QAction(this);
    m_delete = new QAction(this);
    m_selectAll = new QAction(this);

    addAction(m_clip);
    addAction(m_copy);
    addAction(m_paste);
    addAction(m_delete);
    addAction(m_selectAll);
}

void RightMenu::initConnect()
{
    connect(m_clip,SIGNAL(triggered(bool)),
            this,SIGNAL(signalClip()));
    connect(m_copy,SIGNAL(triggered(bool)),
            this,SIGNAL(signalCopy()));
    connect(m_paste,SIGNAL(triggered(bool)),
            this,SIGNAL(signalPaste()));
    connect(m_delete,SIGNAL(triggered(bool)),
            this,SIGNAL(signalDelete()));
    connect(m_selectAll,SIGNAL(triggered(bool)),
            this,SIGNAL(signalSelectAll()));
}

