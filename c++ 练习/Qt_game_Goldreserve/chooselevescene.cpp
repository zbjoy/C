#include "chooselevescene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QSound>

ChooseLeveScene::ChooseLeveScene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    this->setFixedSize(320,588);

    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle("选择关卡场景");

    //创建菜单栏
    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");

    //创建退出的菜单项
    QAction * quitAction = startMenu->addAction("退出");

    //点击退出
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    //选择关卡按钮音效
    QSound * chooseSound = new QSound(":/res/TapButtonSound.wav");

    //返回按钮的yxiao
    QSound * backSound = new QSound(":/res/TapButtonSound.wav");

    //返回按钮
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    //点击返回
    connect(backBtn,&MyPushButton::clicked,[=](){
        //qDebug()<<"点击了返回按钮";
        //this->hide();

        //播放返回按钮音效
        backSound->play();


        //延时返回
        QTimer::singleShot(300,this,[=](){
            emit this->chooseSceneBack();
        });


    });

    //选择关卡按钮
    for(int i = 0 ;i < 20 ; i++)//一个for循环做出矩阵，但是好像时间和空间复杂度没什么区别吧？（对比两个for循环）一个n方与两个n来n*n好像没区别
    {
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move( 25 + i%4 * 70 , 150 + i/4 * 70 );

        //监听每个按钮的点击事件
        connect(menuBtn,&MyPushButton::clicked,[=](){
            //播放选择关卡音效
            chooseSound->play();


            //QString str = QString("您选择的是第 %1 关").arg(i+1);
            //qDebug()<< str;

            //进入游戏场景
            this->hide();
            play = new PlayScene(i+1);//创建游戏场景

            //设置游戏场景的初始位置
            play->setGeometry(this->geometry());

            play->show();



            connect(play,&PlayScene::chooseSceneBack,[=](){
                this->setGeometry(play->geometry());
                this->show();
                delete play;
                play = NULL;
            });
        });

        QLabel * label = new QLabel;
        label->setParent(this);
        //label->setParent(menuBtn);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move( 25 + i%4 * 70 , 150 + i/4 * 70 );

        //设置label上的文字的对齐方式   变为水平居中和垂直居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置让鼠标进行穿透   51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }


}


void ChooseLeveScene::paintEvent(QPaintEvent *)
{
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);
}










