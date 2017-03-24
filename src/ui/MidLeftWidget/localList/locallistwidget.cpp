/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-14
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---本地列表界面
**************************************************/
#include "locallistwidget.h"
#include "treemodel.h"

LocalListWidget::LocalListWidget(QWidget *parent)
    :QTreeView(parent)
{
    this->initWidget();
    this->initForm();
    this->initConnect();
}

LocalListWidget::~LocalListWidget()
{
}

void LocalListWidget::initForm()
{
    this->setFont(QFont("Times", 12, QFont::Bold));
}

void LocalListWidget::initWidget()
{
    m_model = new TreeModel(this,QString::fromLocal8Bit("默认列表[0]"));
    setModel(m_model);

//    this->setColumnCount(2);
//    this->setHeaderHidden(true);
//    this->setContentsMargins(0,10,0,10);
//    this->setHeaderLabel(QStringLiteral("default list"));
//    this->setColumnWidth(0,200);

//    QTreeWidgetItem *item = new QTreeWidgetItem(this);
//    item->setText(0,"default list[0]");
//    item->setText(1,"=");

//    QTreeWidgetItem *recently = new QTreeWidgetItem(this);
//    recently->setIcon(0,QIcon(":/image/mainMenu/home.png"));
//    recently->setText(0,"recent play[0]");
//    recently->setText(1,"=");
}

void LocalListWidget::initConnect()
{
}

