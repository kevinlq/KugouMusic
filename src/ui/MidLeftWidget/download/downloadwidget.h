/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-03-08
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---本地音乐界面的实现
**************************************************/
#ifndef DOWNLOADWIDGET_H
#define DOWNLOADWIDGET_H

#include "Common/abstracttabwidget.h"

class MyDownloadWidget;
class LocalImportWidget;

class DownloadWidget : public AbstractTabWidget
{
    Q_OBJECT
public:
    explicit DownloadWidget(QWidget *parent = 0);
    ~DownloadWidget();

private:
    void initForm();
    void initConnect();

private:
    MyDownloadWidget *m_Mydownload;
    LocalImportWidget *m_localImport;
};

#endif // DOWNLOADWIDGET_H
