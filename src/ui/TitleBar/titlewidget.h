/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-09
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---标题栏的实现
**************************************************/
#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>

class PushButton;
class QLabel;
class QHBoxLayout;
class SearchLineEdit;
class MyMenu;
class RemoteWidget;

typedef enum TbnStatus{
    BtnMax = 0,
    BtnMin
}TBNSTATUS;

class TitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TitleWidget(QWidget *parent = 0);
    ~TitleWidget();

    void Translator();

Q_SIGNALS:
    void signalClose();
    void signalHideWidget();
    void signalMax();
    void signalMix();
    void signalShowSkin();

    //转发遥控器信号
    void signalShowOrHideWidget(int);

private Q_SLOTS:
    void slotChangeBtnStatus(int status);
    void slotOpenOrHideRemote();
    void slotHideRemote();

private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    QLabel *m_labelIcon;

    PushButton *m_TbnLogin;            //登录
    QLabel *m_label_div;
    PushButton *m_TbnRegister;         //注册

    SearchLineEdit *m_search;           //索索框

    PushButton *m_TbnGame;             //游戏
    PushButton *m_TbnNews;             //消息通知
    PushButton *m_TbnSkin;             //皮肤

    PushButton *m_TbnMenu;             //主菜单
    PushButton *m_TbnRemote;           //遥控器
    PushButton *m_TbnMenu_max;         //最大化
    PushButton *m_TbnMenu_min;         //最小化
    PushButton *m_TbnMenu_close;       //关闭

    QHBoxLayout *m_mainLayout;

    MyMenu *m_menu;
    RemoteWidget *m_remoteWidget;
    bool m_isOpenRemote;                  //是否打开遥控器
};

#endif // TITLEWIDGET_H
