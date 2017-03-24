#ifndef MUSICLYRICWIDGET_H
#define MUSICLYRICWIDGET_H

#include <QWidget>
class QLabel;
class QVBoxLayout;

class MusicLyricWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MusicLyricWidget(QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPainter *);

private:
    void initForm();
    void initWidget();

private:
    QLabel *m_label;

    QVBoxLayout *m_mainLayout;
};

#endif // MUSICLYRICWIDGET_H
