#include "mypushbutton.h"


MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() <<"我的按钮类构造函数的调用";
}

MyPushButton::~MyPushButton()
{
    qDebug() << "我的按钮类析构";
}
