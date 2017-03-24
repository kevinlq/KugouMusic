#include "pushbutton.h"

PushButton::PushButton(QWidget *parent)
    :QPushButton(parent)
{
    this->initForm();
}

PushButton::~PushButton()
{

}

void PushButton::initForm()
{
    this->setFixedSize(30,25);
    this->setFlat(true);
    this->setStyleSheet("QPushButton{border-radius:0px;"
                        "color:#F0F0F0;"
                        "background-color:rgba(0,0,0,0);"
                        "border-style:none;}"
                        "QPushButton:hover{background-color: qlineargradient("
                        "spread:pad,x1:0,y1:1,x2:0,y2:0,stop:0 rgba(194, 255, 243, 0),"
                        "stop:1 #D9E7F3)}");
}
