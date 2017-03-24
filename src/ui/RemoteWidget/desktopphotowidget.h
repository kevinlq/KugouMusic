#ifndef DESKTOPPHOTOWIDGET_H
#define DESKTOPPHOTOWIDGET_H

#include "core/abstractwidget.h"
class MusicAbstractRemoteButton;

class DesktopPhotoWidget : public AbstractWidget
{
    Q_OBJECT
public:
    explicit DesktopPhotoWidget(QWidget *parent);
    ~DesktopPhotoWidget();
Q_SIGNALS:

private Q_SLOTS:

private:
    MusicAbstractRemoteButton *m_tbnDesktop;
};

#endif // DESKTOPPHOTOWIDGET_H
