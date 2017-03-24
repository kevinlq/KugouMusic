#ifndef PLAYMUSICWIDGET_H
#define PLAYMUSICWIDGET_H
#include "core/abstractwidget.h"

class MusicAbstractRemoteButton;
class QSlider;

class PlayMusicWidget : public AbstractWidget
{
    Q_OBJECT
public:
    explicit PlayMusicWidget(QWidget *parent);
    ~PlayMusicWidget();
Q_SIGNALS:

private Q_SLOTS:

private:
    void initForm();
    void initLayout();

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    MusicAbstractRemoteButton *m_tbnPlay;
    MusicAbstractRemoteButton *m_noVoice;
    QSlider *m_musicSlitter;
};

#endif // PLAYMUSICWIDGET_H
