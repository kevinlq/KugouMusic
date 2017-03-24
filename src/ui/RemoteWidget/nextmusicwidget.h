#ifndef NEXTMUSICWIDGET_H
#define NEXTMUSICWIDGET_H

#include "core/abstractwidget.h"
class MusicAbstractRemoteButton;

class NextMusicWidget : public AbstractWidget
{
    Q_OBJECT
public:
    explicit NextMusicWidget(QWidget*parent = 0);
    ~NextMusicWidget();

private:
    MusicAbstractRemoteButton *m_tbnNextMusic;
};

#endif // NEXTMUSICWIDGET_H
