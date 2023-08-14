#include "mycoin.h"
#include <QDebug>

//MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
//{

//}



MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret)
    {
        QString str = QString("图片%1加载失败").arg(btnImg);
        qDebug()<<str;
        return;
    }

    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    //初始化定时器对象
    time1 = new QTimer(this);
    time2 = new QTimer(this);

    //监听正面翻反面的信号  并且反转金币
    connect(time1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1").arg(this->min++);
        pix.load(str);

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));

        //判断  如果翻完了，将min重置为1
        if(this->min > this->max)
        {
            this->min = 1;
            isAnimation = false;
            time1->stop();
        }

    });


    //监听反面翻正面的信号  并且反转金币
    connect(time2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1").arg(this->max--);
        pix.load(str);

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));

        //判断  如果翻完了，将min重置为1
        if(this->min > this->max)
        {
            this->max = 8;
            isAnimation = false;
            time2->stop();
        }

    });

}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || this->isWin)
    {
        return;
    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
}


//改变正反面标志的方法
void MyCoin::changeFlag()
{
    //如果是正面  翻成反面
    if(this->flag)
    {
        //开始正面翻反面的定时器
        time1->start(30);
        isAnimation = true; //开始做动画
        this->flag = false;
    }
    else
    {
        time2->start(30);
        isAnimation = true;
        this->flag = true;
    }


}








