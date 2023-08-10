#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮 弹出一个对话窗
    connect(ui->actionnew,&QAction::triggered,[=](){
        //对话框 分类
        //模态对话框(不可以对其他窗口进行操作)  非模态对话框(可以对其他窗口进行操作)
        //模态的创建
//        QDialog dlg(this);
//        dlg.resize(200,100);
//        dlg.exec();

//        qDebug() << "模态对话框弹出了";


        //非模态对话框
//        QDialog * dlg2 = new QDialog(this);
//        dlg2->show();
//        dlg2->resize(200,100);
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);//防止狂点内存泄漏
//        qDebug() << "非模态对话框的弹出";

//        QDialog dlg2;
//        dlg2.show();
//        dlg2.exec();


        //消息对话框
        //QMessageBox::critical(this,"critical","错误");

        //信息对话框
        //QMessageBox::information(this,"info","信息");

        //提问对话框
//        if(QMessageBox::question(this,"ques","提问",QMessageBox::Save|QMessageBox::Cancel)) //第五个参数是默认回车时的按键
//        {
//            qDebug() << "保存";
//        }
//        else
//        {
//            qDebug() << "取消";
//        }

        //警告对话框
        //QMessageBox::warning(this,"warning","警告");


        //颜色对话框
//        QColor color = QColorDialog::getColor(QColor(255,0,0));
//        qDebug() << "r = "<<color.red() << "g = " << color.green() << "b = "<< color.blue();

        //文件对话框    参数1、父类     参数2、标题      参数3、默认打开路径      参数4、过滤文件格式
//        QString str = QFileDialog::getOpenFileName(this,"打开文件","E:");
//        qDebug()<<str;//返回值是路径

        //字体对话框
//        bool flag;
//        QFont font = QFontDialog::getFont(&flag,QFont("华文彩云",36));
//        qDebug() << "字体："<< font.pointSize() <<" 是否加粗："<< font.bold()<<" 是否倾斜:"<<font.italic();



    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

