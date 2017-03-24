/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-03-08
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---本地音乐界面的实现
**************************************************/
#include "downloadwidget.h"
#include "mydownloadwidget.h"
#include "localimportwidget.h"
#include <QTabBar>

DownloadWidget::DownloadWidget(QWidget *parent)
    :AbstractTabWidget(parent)
{
    initForm();
    initConnect();
}

DownloadWidget::~DownloadWidget()
{
    delete m_Mydownload;
    delete m_localImport;
}

void DownloadWidget::initForm()
{
    setObjectName("download_tabwidget");

    m_Mydownload = new MyDownloadWidget();
    m_localImport = new LocalImportWidget();

    addTab(m_Mydownload,QString::fromLocal8Bit("我的下载"));
    addTab(m_localImport,QString::fromLocal8Bit("本地导入"));
}

void DownloadWidget::initConnect()
{
}

