/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-03-8
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---音乐电台界面的实现
**************************************************/
#ifndef MUSICRADIOWIDGET_H
#define MUSICRADIOWIDGET_H

#include "Common/abstracttabwidget.h"
class MvRadioWidget;

class MusicRadioWidget : public AbstractTabWidget
{
    Q_OBJECT
public:
    explicit MusicRadioWidget(QWidget *parent = 0);
    ~MusicRadioWidget();
Q_SIGNALS:
private Q_SLOTS:

private:
    QWidget*m_musicRadio;
    MvRadioWidget *m_mvRaido;

};

#endif // MUSICRADIOWIDGET_H
