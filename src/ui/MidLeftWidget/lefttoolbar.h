/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-09
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---左边工具按钮的实现
**************************************************/
#ifndef LEFTTOOLBAR_H
#define LEFTTOOLBAR_H

#include <QWidget>

class QVBoxLayout;
class ToolButton;

class LeftToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit LeftToolBar(QWidget *parent = 0);

    void traanslator();
Q_SIGNALS:
    void signalNetCollect();
    void signalPhoneManage();
    void signalMusicRadio();
    void signalLocalMusic();
    void signalLocalList();
    void signalMoreTool();

public Q_SLOTS:
private:
    void initForm();
    void initWidget();
    void initConnect();
    void setButtonStyle(ToolButton *);

private:
    ToolButton *m_tbnLocalList;        //本地列表
    ToolButton *m_tbnNetworkCollect;   //网络收藏
    ToolButton *m_tbnMusicRadio;       //音乐电台
    ToolButton *m_tbnPhoneManage;      //手机管理
    ToolButton *m_tbnLocalMusic;       //本地音乐
    ToolButton *m_tbnMore;             //更多

    QVBoxLayout *m_mainLayout;

    QVector<ToolButton *>m_vecTbn;
};

#endif // LEFTTOOLBAR_H
