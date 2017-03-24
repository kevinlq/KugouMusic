/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-3-01
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---系统托盘之声音按钮的实现,包括背景图片的切换、按下状态的切换
**************************************************/
#ifndef VOICEBUTTON_H
#define VOICEBUTTON_H

#include <QToolButton>

class VoiceButton : public QToolButton
{
    Q_OBJECT
public:
    VoiceButton(QWidget *parent = 0);
    ~VoiceButton();
    bool getCheck()const {return m_isCheck;}
    void setCheck(bool isCheck);
private:
    void initForm();
    void initConnect();

private Q_SLOTS:
    void slotChangeState();

private:
    bool m_isCheck;
    QString m_styleOn;
    QString m_styleOff;

};

#endif // VOICEBUTTON_H
