/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-11
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--MV显示界面
**************************************************/
#ifndef MVWIDGET_H
#define MVWIDGET_H

#include <QWidget>

class QLabel;
class QVBoxLayout;

class MvWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MvWidget(QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);
private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    QLabel *m_label;
    QVBoxLayout *m_mainLayout;
};

#endif // MVWIDGET_H
