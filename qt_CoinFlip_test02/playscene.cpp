#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "mycoin.h"
#include "dataconfig.h"
#include <QPropertyAnimation>
#include "chooselevelscene.h"    //如果胜利则在隔两秒后自动进入下一关
#include <QSound>

//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}
PlayScene::PlayScene(int levelNum)
{
//    QString str = QString("进入了第%1关").arg(levelNum);
//    qDebug()<<str;
    this->levelIndex = levelNum;

    //初始化游戏场景

    //t = levelNum;

    //设置固定大小
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币场景");

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

    //添加音效资源
    QSound * filpSound = new QSound(":/res/ConFlipSound.wav",this);
    QSound * winSound = new QSound(":/res/LevelWinSound.wav",this);

    //返回按钮
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    ChooseLevelScene * chooseScene = new ChooseLevelScene;
    //点击返回
    connect(backBtn,&MyPushButton::clicked,[=](){
        //qDebug()<<"点击了返回按钮";




        //if(levelNum != 20)
        //{
            QTimer::singleShot(300,this,[=](){
                //qDebug()<<"点击了返回按钮";
                //emit this->chooseSceneBack();
                this->hide();

                chooseScene->show();
            });
        //}

    });

    //显示第几关
    QLabel * label = new QLabel;
    label->setParent(this);

    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str1 = QString("Level:%1").arg(this->levelIndex);

    //将字体设置到标签控件中
    label->setFont(font);

    label->setText(str1);
//    label->setFixedSize()
//    label->move(100,500);
    label->setGeometry(30,this->height()-50,120,50);


    dataConfig config;
    //初始化每个关卡的二维数组
    for(int i = 0;i < 4; i++)
    {
        for(int j = 0;j < 4; j++)
        {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    QLabel * winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move((this->width()-tmpPix.width())*0.5,-tmpPix.height());


    //显示金币的背景图案
    for(int i =0 ;i < 4;i++)
    {
        for(int j = 0;j < 4; j++)
        {
            QLabel * label = new QLabel;
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->setParent(this);
            label->move(57 + i*50,200+j*50);
            //也可以
            //Pixmap pix = QPixmap(":/res/BoardNode.png");
            //label->setGeometry(0,0,pix.width(),pix.height());
            //label->setPixmap(pix);


            //创建金币
            QString str;
            if(this->gameArray[i][j]==1)
            {
                //显示金币
                str = ":/res/Coin0001.png";
            }
            else
            {
                str = ":/res/Coin0008.png";
            }

            MyCoin * coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59 + i*50,204+j*50);

            //给金币属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];//1正面  0反面

            //将金币放入到金币的二维数组里，以便后期的维护
            coinBtn[i][j] = coin;

            //点击金币进行反转
            connect(coin,&MyCoin::clicked,[=](){

                //播放翻金币音效
                filpSound->play();


                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        this->coinBtn[i][j]->isWin = true;
                    }
                }


                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1 : 0;

                //翻转周围硬币的操作

                //延时翻转
                QTimer::singleShot(300,this,[=](){
                    //周围右侧硬币翻转
                    if(coin->posX + 1 <= 3)
                    {
                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY] = this->gameArray[coin->posX+1][coin->posY] == 0 ? 1 : 0;
                    }
                    //周围左侧硬币翻转
                    if(coin->posX - 1 >= 0)
                    {
                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY] = this->gameArray[coin->posX-1][coin->posY] == 0 ? 1 : 0;
                    }
                    //周围上侧硬币翻转
                    if(coin->posY - 1 >= 0)
                    {
                        coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY-1] = this->gameArray[coin->posX][coin->posY-1] == 0 ? 1 : 0;
                    }
                    //周围下侧硬币翻转
                    if(coin->posY + 1 <= 3)
                    {
                        coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY+1] = this->gameArray[coin->posX][coin->posY+1] == 0 ? 1 : 0;
                    }

                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            this->coinBtn[i][j]->isWin = false;
                        }
                    }


                    //判断是否胜利   //为什么一旦放到QTimer外就没用了？？？？？
                    this->isWin = true;
                    for(int i = 0; i < 4; i++)
                    {
                        for(int j = 0; j < 4; j++)
                        {
                            if(coinBtn[i][j]->flag == false)
                            {
                                this->isWin = false;
                                break;
                            }
                        }

                        if(this->isWin == false)//已经可以退出了，不需要再循环了
                        {
                            break;
                        }
                    }

                    if(this->isWin == true)
                    {

                        //添加胜利音效
                        winSound->play();

//                        QTimer::singleShot(2000,this,[=](){
//                            emit this->finsh();
//                        });
                        //胜利
                       // qDebug()<<"胜利了";

                        //将所有按钮胜利的标志改为true

                        //t++;

                        for(int i = 0; i<4;i++)
                        {
                            for(int j=0;j<4;j++)
                            {
                                coinBtn[i][j]->isWin = true;
                            }
                        }

                        //将胜利图片移动下来
                        QPropertyAnimation * animation = new QPropertyAnimation(winLabel,"geometry");

                        //设置时间间隔
                        animation->setDuration(1000);

                        //起始位置
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));

                        //结束位置
                        animation->setEndValue(QRect(winLabel->x(),winLabel->y() + 114,winLabel->width(),winLabel->height()));

                        //设置弹跳曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);

                        //执行动画
                        animation->start();


                        if(levelNum != 20)//为什么写一个finsh信号在chooselevelscene中实现不了接收？？？？？？？？
                        {
                            QTimer::singleShot(2000,this,[=](){
                                delete this;
                                PlayScene * play = new PlayScene(levelNum + 1);
                                //this->destroy();
                                play->show();
                            });
                        }



                    }

                });



            });
        }
    }

}

void PlayScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}















