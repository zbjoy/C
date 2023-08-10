#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置单选按钮 男默认选中
    ui->rBtnMan->setChecked(true);

    //选中女后 打印信息
    connect(ui->rBtnWoman,&QRadioButton::clicked,[](){
        qDebug() << "选中了女";

    });


    //多选按钮  2是选中   0是未选中
    connect(ui->cBox,&QCheckBox::stateChanged,[=](int state){
        qDebug() << state;
    });



    //利用listWidget写诗
//    QListWidgetItem * item = new QListWidgetItem("锄禾日当午");

//    //将一行诗放入到listWidget控件中
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignHCenter);

//    QStringList list;
//    list<<"锄禾日当午"<<"汗滴禾下土"<<"谁知盘中餐"<<"粒粒皆辛苦";
//    for(QListWidget<QString>::iterator it=list.begin();it!=list.end();it++)
//    {
//        ui->listWidget->addItems(it);
//        it->setTextAlignment(Qt::AlignHCenter);
//    }//怎么样才能通过循环把这个List 容器中的数都居中？？？


    //pushBotton
    QStringList list;
    list<<"锄禾日当午";
    ui->listWidget->addItems(list);



}

Widget::~Widget()
{
    delete ui;
}

