/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-14
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:酷狗音乐播放器---本地列表界面
**************************************************/
#ifndef LOCALLISTWIDGET_H
#define LOCALLISTWIDGET_H

#include <QTreeView>

class TreeModel;

class LocalListWidget : public QTreeView
{
    Q_OBJECT
public:
    explicit LocalListWidget(QWidget *parent = 0);
    ~LocalListWidget();

private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    TreeModel *m_model;
};

#endif // LOCALLISTWIDGET_H
