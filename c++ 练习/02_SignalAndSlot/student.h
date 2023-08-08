#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    //也可以直接写到public权限下或全局函数,如果是低版本只能solts下了
    //返回值为void ，需要声明，也需要实现
    //可以有参数，也可以发生重载
    void treat();

    void treat(QString foodName);

};

#endif // STUDENT_H
