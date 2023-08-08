#include "widget.h"
#include "ui_widget.h"

//Teacher 类 老师
//Student 类 学生
//下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt = new Teacher(this);

    //创建一个学生对象
    this->st = new Student(this);

//    //老师饿了，学生请客的连接
//    connect(zt,&Teacher::hungry,st,&Student::treat);

//    //调用下课函数
//    classIsOver();

    //连接带参数的 信号和槽
    //用指针指向函数地址

    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSlot)(QString) = &Student::treat;
    connect(zt,teacherSignal,st,studentSlot);
    //classIsOver();



    //点击下课按钮来触发下课
    //QPushButton * btn = new QPushButton("下课",this);

    QPushButton * btn = new QPushButton;
    btn->setParent(this);
    btn->setText("下课了，我亲爱的同学们");

    this->resize(600,400);

    //点击按钮触发下课
//    connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);


    //无参信号和槽连接
    void (Teacher::*teacherSignal2)(void) = &Teacher::hungry;
    void (Student::*studentSlot2)(void) = &Student::treat;
    connect(zt,teacherSignal2,st,studentSlot2);


    //信号连接信号
    connect(btn,&QPushButton::clicked,zt,teacherSignal2);

    //信号断开
//    disconnect(zt,teacherSignal2,st,studentSlot2);

    //信号可以连接信号
    //一个信号可以连接多个槽
    //多个信号可以连接同一个槽函数
    //信号和槽函数参数类型要一一对应
    //信号的参数个数可以多于槽函数的参数个数，但还是类型是一一对应  n号位对n号位


    //Qt4版本以前的信号和槽的连接方式
    //利用Qt4信号槽 连接无参版本
    connect(zt,SIGNAL(hungry()),st,SLOT(treat()));
    //优点 ：参数直观
    //缺点 ：不会做类型检测

}


void Widget::classIsOver()
{
    //下课函数，调用后，触发老师饿了的信号
    //emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}

Widget::~Widget()
{
    delete ui;
}

