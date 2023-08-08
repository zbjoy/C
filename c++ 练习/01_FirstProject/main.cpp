#include "mywidget.h"

#include <QApplication>//包含一个应用程序的类

int main(int argc, char *argv[])
{
    //a应用程序对象，在Qt中，应用程序对象，有且仅有一个
    QApplication a(argc, argv);
    //窗口对象  myWidget父类 -> QWidget
    myWidget w;
    w.show();
    return a.exec();
}
