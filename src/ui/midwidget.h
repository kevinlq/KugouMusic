#ifndef MIDWIDGET_H
#define MIDWIDGET_H

#include <QWidget>

class MidLeftWidget;
class MidRightWidget;
class QHBoxLayout;
class QPushButton;

class MidWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MidWidget(QWidget *parent = 0);

    void translator();
Q_SIGNALS:
    void signalLocalList();
    void signalNetCollect();
    void signalMusicRadio();
    void signalPhoneManage();
    void signalLocalMusic();
    void signalMoreTool();
public Q_SLOTS:
    void slotOnZoomBtnClicked();
private slots:
    void slotSetSplitterVisible(bool);

private:
    void initForm();
    void initWidget();
    void initConnect();
private:
    MidLeftWidget  *m_leftWidget;
    MidRightWidget *m_rightWidget;
    QPushButton *m_zoomBtn;
    QHBoxLayout *m_mainLayout;

    bool flag_status;
};

#endif // MIDWIDGET_H
