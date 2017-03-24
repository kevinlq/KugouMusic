#include "myplayer.h"

#include <QMediaPlayer>

MyPlayer::MyPlayer(QObject *parent) : QObject(parent)
{
    this->initWidget();
    this->initWidget();
    this->initConnect();
}

//设置播放音乐
void MyPlayer::setMusicPlay()
{
    m_player->play();
    emit signalPlayStateChanged(PLAYING);
}

//暂停播放
void MyPlayer::setMusicPause()
{
    m_player->pause();
    emit signalPlayStateChanged(PAUSE);
}

//设置音乐声音
void MyPlayer::slotSetMusicVoice(int voice)
{
    m_player->setVolume(voice);
    emit signalPlayStateChanged(PLAYING);
}

//槽函数---播放音乐
void MyPlayer::slotPlayMusic()
{
    m_player->play();
    emit signalPlayStateChanged(PLAYING);
}

//槽函数--暂停播放
void MyPlayer::slotPauseMusic()
{
    m_player->pause();
    emit signalPlayStateChanged(PAUSE);
}

//槽函数--播放上一首音乐
void MyPlayer::slotPlayPre()
{
}

//槽函数--播放下一首音乐
void MyPlayer::slotPlayNext()
{
}

void MyPlayer::initForm()
{
}

void MyPlayer::initWidget()
{
    m_player = new QMediaPlayer;
}

void MyPlayer::initConnect()
{
}

