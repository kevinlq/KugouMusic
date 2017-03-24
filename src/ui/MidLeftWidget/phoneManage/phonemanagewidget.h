#ifndef PHONEMANAGEWIDGET_H
#define PHONEMANAGEWIDGET_H

#include <QWidget>
class QPushButton;
class QStackedWidget;
class QVBoxLayout;
class QLabel;
class PushButton;

class PhoneManageWidget : public QWidget
{
    enum Widget{
        HomeWidget,
        WiredWidget,
        WirelessWidget
    };
    Q_OBJECT
public:
    explicit PhoneManageWidget(QWidget *parent = 0);

signals:

private slots:
    void slotShowHomeWidget();
    void slotShowWiredWidget();            //显示有线连接界面
    void slotShowWirelessWidget();         //显示无线连接界面
private:
    void initForm();
    void initWidget();
    void initWiredWidget();
    void initWirelessWidget();
    void initConnect();
private:
    QPushButton *m_pbnReturn;              //返回按钮
    QLabel *m_labelConnectWay;             //链接方式

    QWidget *m_homeWidget;

    QPushButton *m_pbnWiredConnect;        //有线连接
    QWidget *m_wireWidget;

    QPushButton *m_pbnWirelessConnect;     //无线连接
    QWidget *m_wirelessWidget;

    QStackedWidget *m_stackedWidget;
    QVBoxLayout *m_mainLayout;
};

#endif // PHONEMANAGEWIDGET_H
