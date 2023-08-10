#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //栈控件的使用

    //设置默认界面
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget->resize(500,500);
    ui->stackedWidget->move(100,100);

    //scrollArea按钮
    connect(ui->btn_scrollArea,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    //toolBox
    connect(ui->btn_ToolBox,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //TabWidget
    connect(ui->btn_TabWidget,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //下拉框
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("拖拉机");

    ui->btn_select->setText("宝马");

    //点击 按钮，选中拖拉机
    connect(ui->btn_select,&QPushButton::clicked,[=](){
        //ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("宝马");
    });

    //利用QLabel显示图片
    ui->lbl_Image->setPixmap(QPixmap(":/image/7.jpg"));

    //利用QLabel显示动态的图片
    QMovie * movie = new QMovie(":/image/th.gif");
    ui->lbl_movie->setMovie(movie);
    ui->lbl_movie->resize(500,500);
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}

