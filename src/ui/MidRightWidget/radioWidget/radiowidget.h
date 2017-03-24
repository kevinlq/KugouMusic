#ifndef RADIOWIDGET_H
#define RADIOWIDGET_H

#include <QWidget>
class QLabel;
class QVBoxLayout;

class RadioWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RadioWidget(QWidget *parent = 0);
    ~RadioWidget();

Q_SIGNALS:

public Q_SLOTS:

private:
    QLabel *m_label;
    QVBoxLayout *m_mainLayout;
};

#endif // RADIOWIDGET_H
