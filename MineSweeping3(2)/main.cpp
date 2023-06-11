#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;//创建MainWindow对象w
    w.show();//显示窗口
    return a.exec();//主事件循环
}
