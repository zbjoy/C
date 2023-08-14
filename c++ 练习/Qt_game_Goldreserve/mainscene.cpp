#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QSound>//多媒体模块的音效头文件


MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

  //配置主场景


    //设置固定大小
    setFixedSize(320,588);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("翻金币主场景");

    //退出按钮实现
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //准备开始按钮的音效
    QSound * startSound = new QSound(":/res/TapButtonSound.wav",this);

    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");//把MyPushButton写成MyPuahButton找了1个半小时！！！！！！！！！！！！！！
    //不要总是把问题复杂化，先认真认真再认真的检查是否有拼写错误，写的时候要认真写！！！！！！！！！！！！！！
    startBtn->setParent(this);
    startBtn->setObjectName("my_index_button");
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5,this->height()*0.7);

    //实例化选择关卡场景
    chooseScene = new ChooseLeveScene;

    //监听选择关卡的返回按钮的信号
    connect(chooseScene,&ChooseLeveScene::chooseSceneBack,this,[=](){
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();
        this->show();
    });

    connect(startBtn,&MyPushButton::clicked,[=](){
        //qDebug()<<"点击了开始";

        //播放开始音效资源
        startSound->play();


        //做弹跳特效
        startBtn->zoom1();
        startBtn->zoom2();

        //延时进入让seesee做的弹跳动画
        QTimer::singleShot(500,this,[=](){
            //设置chooseScene场景的位置
            chooseScene->setGeometry(this->geometry());
            //进入到选择关卡场景中
            this->hide();//隐藏自身
            chooseScene->show();//显示选择关卡场景



        });


    });




}



//重写paintevent事件 画背景图
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);//this->width(),this->height()为拉伸图片

    //画背景上图标
    pix.load(":/res/Title.png");

    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);//缩放图片

    painter.drawPixmap(10,30,pix);



}


MainScene::~MainScene()
{
    delete ui;
}

