#include "menu.h"
#include <QCursor>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#ifdef Q_OS_WIN32
#include <windows.h>
#endif

Menu::Menu(QWidget *parent)
    :QMenu(parent)
{
    this->setStyleSheet("background-color:rgba(255,255,255,100%);"
                        "selection-background-color:rgba(0,128,180,80%)");
}

Menu::~Menu()
{
}

bool Menu::event(QEvent *event)
{
    static bool class_amended = false;
    if (event->type() == QEvent::WinIdChange)
    {
        HWND hwnd = reinterpret_cast<HWND>(winId());
        if (class_amended == false)
        {
            class_amended = true;
            DWORD class_style = ::GetClassLong(hwnd, GCL_STYLE);
            class_style &= ~CS_DROPSHADOW;
            ::SetClassLong(hwnd, GCL_STYLE, class_style);
        }
    }
    return QWidget::event(event);
}

void Menu::slotMenuVisiable()
{
    QPoint pos = QCursor::pos();
    int width = 0;
    int height = 0;
    int maxWidth = QApplication::desktop()->width();
    int maxHeight = QApplication::desktop()->height();
    this->setVisible(true);

    if (pos.x() + this->width() > maxWidth)
    {
        width = -this->width();
    }
    if (pos.y() + this->height() > maxHeight)
    {
        height = -this->height();
    }

    this->move(pos.x() + width,pos.y() + height);
}

