/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-10
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--中间窗体部分--右边部分
**************************************************/
#ifndef MIDRIGHTWIDGET_H
#define MIDRIGHTWIDGET_H

#include <QWidget>

class QHBoxLayout;
class QVBoxLayout;
class QToolButton;
class QStackedWidget;

class RadioWidget;
class MusicLyricWidget;
class MvWidget;

class MidRightWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MidRightWidget(QWidget *parent = 0);

    void translator();

protected:
    void paintEvent(QPaintEvent *);
    virtual bool event(QEvent *);
private:
    void initForm();
    void initWidget();
    void initConnect();

signals:
    void signalShowSplitter(bool);
private Q_SLOTS:
    void slotShowRadioWidget();         //显示电台界面
    void slotShowLyric();               //显示歌词
    void slotShowMV();                  //显示MV界面

private:

    QWidget *m_toolWidget;
    QToolButton *m_tbnReturn;           //返回
    QToolButton *m_tbnRefresh;          //刷新

    QToolButton *m_tbnMusicLibrary;     //乐库
    QToolButton *m_tbnRadio;            //电台
    QToolButton *m_tbnMusicList;        //歌单
    QToolButton *m_tbnMV;               //MV
    QToolButton *m_tbnTelecase;         //直播
    QToolButton *m_tbnMusicWord;        //歌词

    QVector<QToolButton *>m_vecTbn;

    RadioWidget *m_radioWidget;         //电台界面
    MvWidget *m_mvWidget;               //MV界面
    MusicLyricWidget *m_lyricWidget;    //歌词界面

    QHBoxLayout *m_tabLayout;           //工具栏布局
    QVBoxLayout *m_mainLayout;          //主布局

    QStackedWidget *m_stackedWidget;
};

#endif // MIDRIGHTWIDGET_H
