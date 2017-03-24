#ifndef PREVIOUSMUSICWIDGET_H
#define PREVIOUSMUSICWIDGET_H

#include "core/abstractwidget.h"

class MusicAbstractRemoteButton;

class PreviousMusicWidget : public AbstractWidget
{
    Q_OBJECT
public:
    explicit PreviousMusicWidget(QWidget *parent);
    ~PreviousMusicWidget();
Q_SIGNALS:
private Q_SLOTS:

private:
    MusicAbstractRemoteButton *m_tbnPreviousMusic;
};

#endif // PREVIOUSMUSICWIDGET_H
