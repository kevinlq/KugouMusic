#ifndef MYPLAYER_H
#define MYPLAYER_H

#include <QObject>
class QMediaPlayer;

class MyPlayer : public QObject
{
    Q_OBJECT
public:
    explicit MyPlayer(QObject *parent = 0);

    enum PlayerState{
        NOMUSIC,
        PAUSE,
        PLAYING
    };
public:
    void setMusicPlay();                       //设置播放
    void setMusicPause();                       //设置暂停

signals:
    void signalPlayStateChanged(int state);     //播放状态改变

public slots:
    void slotSetMusicVoice(int voice);          //设置播放声音大小
    void slotPlayMusic();                       //播放音乐
    void slotPauseMusic();                      //暂停播放
    void slotPlayPre();                         //播放上一首
    void slotPlayNext();                        //播放下一首
private:
    void initForm();
    void initWidget();
    void initConnect();
private:
    QMediaPlayer *m_player;
};

#endif // MYPLAYER_H
