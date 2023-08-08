#include "mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton * btn = new QPushButton;   btn->show();//show以顶层方式弹出窗口控件
    btn->setParent(this);

    btn->setText("第一个按钮");
    btn->move(0,0);

    btn->resize(100,50);

   QPushButton * btn2 = new QPushButton("第二个按钮",this);

       btn2->move(100,100);

    resize(600,400);

    setWindowTitle("第一个窗口");

    setFixedSize(600,400);





    MyPushButton * myBtn = new MyPushButton;
    myBtn->setText("我自己的按钮");

    myBtn->move(200,0);

    myBtn->setParent(this);




    //参数1、信号的发送者   参数2、发送的信号    参数3、信号的接收者    参数4、处理的槽函数

    connect(myBtn,&QPushButton::clicked,this,&myWidget::close);

}

myWidget::~myWidget()
{
    qDebug()<<"myWidget的析构调用";
}

