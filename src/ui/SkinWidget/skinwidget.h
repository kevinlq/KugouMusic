/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-15
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:音乐播放器--皮肤与窗口调整界面
**************************************************/
#ifndef SKINWIDGET_H
#define SKINWIDGET_H

#include <QDialog>
#include "drop_shadow_widget.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class PushButton;
class QLabel;
class QWidgetAction;
class QCheckBox;
class QComboBox;
class QStackedWidget;

class SkinWidget : public DropShadowWidget
{
    Q_OBJECT
public:
    explicit SkinWidget(QWidget *parent = 0);
    ~SkinWidget();
    void translator();

private slots:
    void slotClose();
private:
    void initForm();
    void initWidget();
    void initLayout();
    void initConnect();

private:
    QWidget *m_titleWidget;
    QLabel *m_labelTitle;
    PushButton *m_pbnClose;
    QHBoxLayout *m_titleLayout;

    QPushButton *m_pbnRecoSkin;     //推荐皮肤
    QPushButton *m_pbnMySkin;       //我的皮肤
    QPushButton *m_pbnRecover;      //恢复窗口默认状态
    QStackedWidget *m_stackenWidget;

    QStringList m_listSkin;
    QList<QWidget *> list_action;
    QGridLayout *m_center_layout;

    QLabel *m_labelListTransparent; //列表透明
    QComboBox *m_cbxTrValue;        //透明值
    QCheckBox *m_ckxSkinTr;         //皮肤透明
    QComboBox *m_cbxSkValue;        //透明值
    QPushButton *m_PbnPalette;
    QPushButton *m_pbnCustom;       //自定义

    QHBoxLayout *m_bottomLayout;    //底部布局

    QVBoxLayout *m_mainLayout;

};

#endif // SKINWIDGET_H
