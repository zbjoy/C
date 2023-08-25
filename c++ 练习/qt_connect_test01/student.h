#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>

class Student : public QWidget
{
    Q_OBJECT
public:
    explicit Student(QWidget *parent = nullptr);

    //可以写成全局函数,或者public下
    //返回值是void ，需要声明也需要实现
    //可以有参数，可以发生重载
    void treat();

    void treat(QString foodName);


signals:

};

#endif // STUDENT_H
