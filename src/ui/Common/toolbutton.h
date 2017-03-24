#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H
#include <QToolButton>

class ToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit ToolButton(QWidget *parent = 0);
    ~ToolButton();
private:
    void initForm();
    void initConnect();
};

#endif // TOOLBUTTON_H
