#ifndef MUSICABSTRACTREMOTEBUTTON_H
#define MUSICABSTRACTREMOTEBUTTON_H

#include <QToolButton>

class MusicAbstractRemoteButton : public QToolButton
{
    Q_OBJECT
public:
    explicit MusicAbstractRemoteButton(QWidget *parent,
                                       const QString &icon_name,
                                       const QString &tooltip);
    virtual ~MusicAbstractRemoteButton();
};

#endif // MUSICABSTRACTREMOTEBUTTON_H
