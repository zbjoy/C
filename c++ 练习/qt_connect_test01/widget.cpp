#include "widget.h"
#include <QPushButton>
#include <QDebug>

//为什么刚开始就打印一个    请老师吃：宫保鸡丁

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(600,400);

    QPushButton * btn = new QPushButton;
    btn->setParent(this);
    //btn->resize(100,50);
    //btn->move(0,0);

    btn->setText("退出");//为什么点击没有作用

    connect(btn,&QPushButton::clicked,this,&Widget::close);

    //创建一个老师的对象
    this->zt=new Teacher(this);

    //创建一个学生对象
    this->st=new Student(this);

    //
//    connect(zt,&Teacher::hungry,st,&Student::treat);

//    //调用下课函数
//    classIsOver();

    //连接带参数的信号和槽
    //指针->地址
    //函数指针->函数地址

    void(Teacher::*teacherSignal)(QString)=&Teacher::hungry;
    void(Student::*studentSignal)(QString)=&Student::treat;

    connect(zt,teacherSignal,st,studentSignal);
    classIsOver();

    //点击下课按钮，实现下课后的情况
    QPushButton * btn1 = new QPushButton;
    btn1->setParent(this);
    btn1->move(100,0);
    btn1->setText("下课");
    connect(btn1,&QPushButton::clicked,this,&Widget::classIsOver);

    //无参信号槽连接
    void (Teacher::*teachervoidSignal)(void)=&Teacher::hungry;
    void (Student::*studentvoidSlot)(void)=&Student::treat;
    connect(zt,teachervoidSignal,st,studentvoidSlot);


    QPushButton * btn2 = new QPushButton("无参下课",this);
    btn2->move(200,0);
    connect(btn2,&QPushButton::clicked,zt,teachervoidSignal);

    //断开信号
    //disconnect

    //1、信号是可以连接信号的
    //2、一个信号可以连接多个槽函数
    //3、多个信号可以连接一个槽函数
    //4、信号和槽函数的参数必修类型一一对应
    //5、信号的参数个数可以多于槽的参数个数，但剩下的类型要一一对应


    //Lambda表达式
    [=]()
    {
        qDebug()<<"Lambda表达式";
    }();

    //mutable 用于修饰值传递的变量
    //int ret = []()->int(return 1000;)();
//    int ret = []()->int{return 1000;}();
//    qDebug()<<ret;


    //利用lambda表达式实现点击按钮关闭窗口
    QPushButton * btn3 = new QPushButton;
    btn3->setText("打开窗口");
    btn3->setParent(this);
    btn3->move(300,0);
//    int count=0;
    QWidget * firstWidget = new QWidget;
    firstWidget->setWindowTitle("作业");
    connect(btn3,&QPushButton::clicked,[=]()
    {
        //this->close();
        emit zt->hungry("宫保鸡丁");
//        btn3->setText("关闭窗口");
        if(btn3->text()=="关闭窗口")
        {
//            connect(btn3,&QPushButton::clicked,[=]()
//            {
                //this->close();
                firstWidget->close();
                btn3->setText("打开窗口");
//            });
        }
        else
        {
//            connect(btn3,&QPushButton::clicked,[=]()
//            {
                firstWidget->show();
                btn3->setText("关闭窗口");
//            });
        }
    });


}

void Widget::classIsOver()
{
    //下课后调用老师饿了的信号
    emit zt->hungry();

    emit zt->hungry("宫保鸡丁");
}


Widget::~Widget()
{
}

