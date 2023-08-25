#include "student.h"
#include <QDebug>

Student::Student(QWidget *parent) : QWidget(parent)
{

}


void Student::treat()
{
    qDebug()<<"请老师吃饭";
}

void Student::treat(QString foodName)
{
    //先转成QByteArray (.toUtf8) 再转成char* (.data())
    qDebug()<<"请老师吃："<<foodName.toUtf8().data();
}
