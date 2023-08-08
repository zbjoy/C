#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    //自定义信号
    //没有返回值void ，只需要声明不需要实现
    //可以有参数,可以重载
    void hungry();

    void hungry(QString foodName);

};

#endif // TEACHER_H
