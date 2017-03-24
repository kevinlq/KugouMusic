#ifndef MUSICABSTRACTREMOTEWIDGET_H
#define MUSICABSTRACTREMOTEWIDGET_H

#include <QWidget>

class MusicAbstractRemoteWidget: public QWidget
{
    Q_OBJECT
public:
    explicit MusicAbstractRemoteWidget(QWidget *parent = 0);
    virtual ~MusicAbstractRemoteWidget();
Q_SIGNALS:
private Q_SLOTS:
private:
    void initForm();
protected:
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
private:
    bool m_isPressed;
    QPoint m_point;
    QRect m_location;
};

#endif // MUSICABSTRACTREMOTEWIDGET_H
