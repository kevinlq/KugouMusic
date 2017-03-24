/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-3-01
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:ÒôÀÖ²¥·ÅÆ÷---ÏµÍ³ÍÐÅÌÖ®ÉùÒô°´Å¥µÄÊµÏÖ,°üÀ¨±³¾°Í¼Æ¬µÄÇÐ»»¡¢°´ÏÂ×´Ì¬µÄÇÐ»»
**************************************************/
#include "voicebutton.h"

VoiceButton::VoiceButton(QWidget *parent)
    :QToolButton(parent)
{
    this->initForm();
    this->initConnect();
}

VoiceButton::~VoiceButton()
{

}

void VoiceButton::setCheck(bool isCheck)
{
    if (this->m_isCheck != isCheck)
    {
        this->m_isCheck = !isCheck;
        slotChangeState();
    }
}

void VoiceButton::initForm()
{
    m_styleOn = "border-image:url(:/image/playControl/voice.png);border:0px;";
    m_styleOff = "border-image:url(:/image/playControl/no_voice.png);border:0px;";
    //setFixedSize(28,28);
    setStyleSheet(m_styleOn);
    m_isCheck = false;
    setCursor(Qt::PointingHandCursor);
}

void VoiceButton::initConnect()
{
    connect(this,SIGNAL(clicked(bool)),
            this,SLOT(slotChangeState()));
}

void VoiceButton::slotChangeState()
{
    if (m_isCheck){
        setStyleSheet(m_styleOff);
        m_isCheck = false;
    }else
    {
        setStyleSheet(m_styleOn);
        m_isCheck = true;
    }
}

