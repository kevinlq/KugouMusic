#ifndef MORETOOLWIDGET_H
#define MORETOOLWIDGET_H

#include <QWidget>
#include <QToolButton>

class QSignalMapper;
class QGridLayout;

class MoreToolButton:public QToolButton
{
    Q_OBJECT
public:
    explicit MoreToolButton(QWidget *parent = 0);
    ~MoreToolButton();
private:
    void initForm();
};

class MoreToolWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MoreToolWidget(QWidget *parent = 0);
    ~MoreToolWidget();

signals:

public slots:
    void slotClicked(QString);

private:
    void initForm();
    void initWidget();
    void initLayout();
    void initConnect();

private:
    QGridLayout *m_gridLayout;
    QList<MoreToolButton *>list_button;
    QStringList textList;                   //按钮文本
    QStringList iconList;                   //按钮图标
    QSignalMapper *m_signalMapper;
};

#endif // MORETOOLWIDGET_H
