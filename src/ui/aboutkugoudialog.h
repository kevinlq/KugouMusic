/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-15
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--关于酷狗
**************************************************/
#ifndef ABOUTKUGOUDIALOG_H
#define ABOUTKUGOUDIALOG_H

#include "drop_shadow_widget.h"
#include <QDialog>
class PushButton;
class ToolButton;
class QLabel;
class QTextEdit;
class QVBoxLayout;
class QHBoxLayout;

class AboutKugouDialog : public DropShadowWidget
{
    Q_OBJECT
public:
    explicit AboutKugouDialog(QDialog *parent = 0);
    ~AboutKugouDialog();

    void translator();

private slots:
    void slotClose();
private:
    void initForm();
    void initWidget();
    void initLayout();
    void initConnect();

private:
    QWidget *m_titleWidget;
    QLabel *m_labelTitle;               //标题
    PushButton *m_tbnClose;             //关闭

    QLabel *m_labelMidIcon;             //中间关于酷狗图标
    QLabel *m_labelMidContent;          //中间内容
    QLabel *m_labelWebsite;             //官网
    QTextEdit *m_textIntruction;        //简介

    ToolButton *m_tbnOk;
    QHBoxLayout *m_titleLayout;         //标题栏布局
    QVBoxLayout *m_midLayout;           //中间内容布局
    QVBoxLayout *m_mainLayout;          //主布局
};

#endif // ABOUTKUGOUDIALOG_H
