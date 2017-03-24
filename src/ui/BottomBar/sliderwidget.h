/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-13
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器---播放进度条的实现
**************************************************/
#ifndef SLIDERWIDGET_H
#define SLIDERWIDGET_H

#include <QWidget>

class SliderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SliderWidget(QWidget *parent = 0);
    qreal getCurrentPostion();
    void setAvailable(bool flag);

public slots:
    void moveTo(qreal pos);

signals:
    void changeTo(qreal pos);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *e);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);

private:
    bool isAvailable;
    bool isPressed;
    qreal currentPos;
    QCursor preCursor;
};

#endif // SLIDERWIDGET_H
