/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-10
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--中间窗体部分--左边歌曲列表界面
**************************************************/
#ifndef MIDLEFTWIDGET_H
#define MIDLEFTWIDGET_H

#include <QWidget>
class QVBoxLayout;
class LocalListWidget;
class NetWorkCollectWidget;
class MusicRadioWidget;
class MoreToolWidget;
class QStackedWidget;
class PhoneManageWidget;
class DownloadWidget;

//枚举当前窗口索引值
enum CurrentWidget{
    LOCAL_LIST,
    NETWORK_COLLECT,
    MUSIC_RADIO,
    PHONE_MANAGE,
    LOCAL_MUSIC,
    MORE_TOOL
};
class MidLeftWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MidLeftWidget(QWidget *parent = 0);

signals:

public slots:
    void slotShowLocalList();               //本地列表
    void slotShowNetCollect();              //网络收藏
    void slotShowMusicRadio();              //音乐电台
    void slotShowPhoneManage();             //手机管理
    void slotShowLocalMusic();              //本地音乐
    void slotShowMoreTool();                //更多
protected:
    void paintEvent(QPaintEvent *);
private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    QVBoxLayout *m_mainLayout;

    QStackedWidget *m_stackedWidget;
    LocalListWidget *m_localListWidget;         //本地列表
    NetWorkCollectWidget *m_netWorkWidget;      //网络收藏
    MusicRadioWidget *m_musicRadioWidget;       //音乐电台
    PhoneManageWidget *m_phonoeManage;          //手机管理
    DownloadWidget *m_download;                 //本地音乐
    MoreToolWidget *m_moreTool;                 //更多
};

#endif // MIDLEFTWIDGET_H
