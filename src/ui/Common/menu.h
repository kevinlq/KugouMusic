#ifndef MENU_H
#define MENU_H

#include <QMenu>

class Menu : public QMenu
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = 0);
    virtual ~Menu();
protected:
    virtual bool event(QEvent *);
public slots:
    void slotMenuVisiable();
};

#endif // MENU_H
