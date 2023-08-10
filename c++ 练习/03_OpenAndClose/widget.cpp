#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QWidget * firstWidget = new QWidget;
    QPushButton * btn = new QPushButton;
    //QPushButton * btn2 = new QPushButton;
    btn->setParent(this);
    resize(500,500);
    btn->move(400,0);
    firstWidget->setWindowTitle("作业");


         btn->setText("open");
         connect(btn,&QPushButton::clicked,[=](){
             if(btn->text()=="open")
             {

                firstWidget->show();
                btn->setText("close");
//                connect(btn,&QPushButton::clicked,[=](){
//                        firstWidget->close();});
//                       btn->setText("close");
             }
              else
             {
                 firstWidget->close();
                 btn->setText("open");
             }
         });



}

Widget::~Widget()
{
}

