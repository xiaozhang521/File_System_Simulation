#include "loginwindow.h"
#include <QApplication>
#include <direct.h>
#include <stdlib.h>
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("文件管理器");
    return a.exec();
}
