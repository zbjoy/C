#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QWidget *parent = nullptr);

    //参数代表传入金币的路径 和 银币的路径
    MyCoin(QString btnImg);


    //金币的属性
    int posX;
    int posY;
    bool flag;

    //改变标志的方法
    void changeFlag();
    QTimer* time1;//正面翻反面的定时器
    QTimer* time2;//反面翻正面的//也可用一个定时器来实现
    int min = 1;
    int max = 8;

    //执行动画的标志
    bool isAnimation = false;

    //重写按下和释放
    void mousePressEvent(QMouseEvent *e);

    //是否胜利
    bool isWin = false;


signals:

};

#endif // MYCOIN_H
