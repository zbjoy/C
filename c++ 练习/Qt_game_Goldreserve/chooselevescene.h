#ifndef CHOOSELEVESCENE_H
#define CHOOSELEVESCENE_H

#include <QMainWindow>
#include "playscene.h"

class ChooseLeveScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLeveScene(QWidget *parent = nullptr);

    //重写绘图事件
    void paintEvent(QPaintEvent *);

    //游戏场景对象指针
    PlayScene * play = NULL;

signals:
    //写一个自定义的信号告诉主场景去返回
    void chooseSceneBack();

};

#endif // CHOOSELEVESCENE_H
