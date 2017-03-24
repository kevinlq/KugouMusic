#ifndef OPENKUGOUWIDGET_H
#define OPENKUGOUWIDGET_H

#include "core/abstractwidget.h"
class MusicAbstractRemoteButton;

class OpenKugouWidget : public AbstractWidget
{
    Q_OBJECT
public:
   explicit OpenKugouWidget(QWidget *parent);
    ~OpenKugouWidget();
Q_SIGNALS:
private Q_SLOTS:

private:
    MusicAbstractRemoteButton *m_tbOpenKugou;
};

#endif // OPENKUGOUWIDGET_H
