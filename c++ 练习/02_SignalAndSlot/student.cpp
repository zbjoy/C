#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}



void Student::treat()
{
    qDebug() << "请老师吃饭";
}

void Student::treat(QString foodName)
{
    //把QString转为char*则不会打印引号
    //先转成QByteArray (.toUtf8())再转成char*(.data())
    qDebug() << "请老师吃饭，老师要吃:" << foodName.toUtf8().data() ;
}
