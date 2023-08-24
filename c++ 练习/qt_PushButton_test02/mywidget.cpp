#include "mywidget.h"
#include <QPushButton>

mywidget::mywidget(QWidget *parent)
    : QWidget(parent)
{
    //创建按钮
    QPushButton * btn = new QPushButton;
    btn->setParent(this);
    //btn->show();

    //显示文本
    btn->setText("第一个按钮");

    //创建第二个按钮
    QPushButton * btn2 = new QPushButton("第二个按钮",this);

    btn2->move(200,0);

    btn2->resize(100,100);

    //重置窗口大小
    resize(600,400);

    //设置窗口标题
    setWindowTitle("第一个窗口");

    //设置固定窗口大小
    setFixedSize(QSize(600,400));

}

mywidget::~mywidget()
{
}

