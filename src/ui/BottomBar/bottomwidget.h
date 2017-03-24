/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-09
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---底部控制界面
**************************************************/
#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H
#include <QWidget>

class ToolButton;
class QLabel;
class QHBoxLayout;
class SliderWidget;
class Play_Mode_Menu;

class BottomWidget : public QWidget
{
   Q_OBJECT
public:
    explicit BottomWidget(QWidget *parent = 0);
    ~BottomWidget();

    void translator();

private:
    void initForm();
    void initWidget();
    void initConnect();

signals:
    void signalPreious();
    void signalPlay();
    void signalNext();

private:
    ToolButton *m_tbnNext;             //下一首
    ToolButton *m_tbnPlay;             //播放/暂停
    ToolButton *m_tbnPerious;          //上一首

    QLabel *m_labelMusicName;          //音乐名称
    QLabel *m_labelMusicTotalTime;     //音乐总时间
    QLabel *m_labelMusicCurTime;       //当前播放的音乐时间

    SliderWidget *m_sliderWidget;       //播放进度条

    ToolButton *m_tbnLove;             //收藏
    ToolButton *m_tbnDownload;         //下载
    ToolButton *m_tbnSimilarMusic;     //相似歌曲

    ToolButton *m_tbnCircleMode;       //播放模式
    Play_Mode_Menu *m_playMode;        //播放模式菜单

    ToolButton *m_tbnVoice;            //声音
    ToolButton *m_tbnSoundEffect;      //音效
    ToolButton *m_tbnMusicWords;       //歌词
    ToolButton *m_tbnMusicPlayQueue;   //播放队列(待播放的歌曲队列)
    QLabel *m_label_misic_num;          //待播放的歌曲数量

    QHBoxLayout *m_MusicInfoLayout;     //歌曲信息布局
    QHBoxLayout *m_mainLayout;          //总布局
};

#endif // BOTTOMWIDGET_H
