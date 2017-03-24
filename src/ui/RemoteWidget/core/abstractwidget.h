#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H

#include <QWidget>

class AbstractWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractWidget(QWidget *parent = 0);
    virtual~AbstractWidget();

protected:
    virtual void paintEvent(QPaintEvent*);

signals:

public slots:
};

#endif // ABSTRACTWIDGET_H
