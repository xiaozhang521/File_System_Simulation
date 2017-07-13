#include "loginwindow.h"
#include <QApplication>
#include <direct.h>
#include <stdlib.h>
#include<QDebug>
#include<qlibrary.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLibrary mylib("./testfile2.dll");
    if (mylib.load())              //判断是否正确加载
    {
        typedef void (*Fun)(); //定义函数指针，以备调用
        Fun init=(Fun)mylib.resolve("init");
        if(init)
        {
            init();
            //printf("%d",123);
            //qDebug()<<result;
        }
        else qDebug()<<"asd";
    }
    else
        qDebug()<<"fail";
    MainWindow w;
    w.show();
    w.setWindowTitle("文件管理器");
    return a.exec();
}
