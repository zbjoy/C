#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class mywidget : public QWidget
{
    Q_OBJECT

public:
    mywidget(QWidget *parent = nullptr);
    ~mywidget();
};
#endif // MYWIDGET_H
