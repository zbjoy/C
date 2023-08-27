#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include "mypushbutton.h"
#include <QSound>
//#include "mainscene.h"  //返回主界面   //设置了自动进入下一关后，无法从chooseLevelScene点击返回返回到mainScene

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
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

    //创建退出菜单项
    QAction * quitAction = startMenu->addAction("退出");

    //点击退出
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    //选择关卡的音效
    QSound * chooseSound = new QSound(":/res/TapButtonSound.wav",this);

    //返回按钮的音效
    //QSound * backSound = new QSound(":/res/TapButtonSound.wav",this);

    //返回按钮
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    //MainScene * mainscene = new MainScene;
    //点击返回
    connect(backBtn,&MyPushButton::clicked,[=](){
//        qDebug()<<"点击了返回按钮";
        //返回主场景 主场景监听ChooseLevelScene的返回按钮

        //播放返回按钮的音效
       // backSound->play();

        //延时返回
        QTimer::singleShot(300,this,[=](){
            emit this->chooseSceneBack();

//            this->hide();
//            mainscene->show();
        });

    });

    //创建选择关卡按钮
    for(int i = 0;i < 20; i++)
    {
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + i%4 * 70,130 + i/4 * 70);



        //监听每个按钮的点击事件
        connect(menuBtn,&MyPushButton::clicked,[=](){

            //播放选择关卡音效
            chooseSound->play();



//            QString str = QString("您选择的是%1关").arg(i+1);
//            qDebug()<<str;
            menuBtn->zoom1();
            menuBtn->zoom2();



            QTimer::singleShot(500,this,[=](){


                //设置游戏场景初始位置
                //play->setGeometry(this->geometry());   //为什么加上这个会在进入游戏时失败？？？？？？？？


                //隐藏选关场景

                this->hide();

                //进入游戏场景
                play = new PlayScene(i+1);
                play->show();

                //为什么下面这些代码放到Timer外就不行了？？？
//                connect(play,&PlayScene::chooseSceneBack,[=](){
//    //                qDebug()<<"点击了按钮";
//                    this->show();
//                    delete play;
//                    play = NULL;




//                });


            });


        });
//        connect(play,&PlayScene::finsh,[=](){
//            qDebug()<<"胜利";
//            delete play;
//            play = NULL;
//            play = new PlayScene(play->t);
//            play->show();
//        });




        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText((QString::number(i+1)));
        label->move(25 + i%4 * 70,130 + i/4 * 70);

        //设置Label上的文字对齐方式  水平居中与 垂直居中
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        //设置让鼠标进行穿透  51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}




void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap( (this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);
}












