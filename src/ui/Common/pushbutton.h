#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>

class PushButton : public QPushButton
{
public:
    explicit PushButton(QWidget *parent = 0);
    ~PushButton();

private:
    void initForm();
};

#endif // PUSHBUTTON_H
