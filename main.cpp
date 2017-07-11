#include "loginwindow.h"
#include <QApplication>
#include <direct.h>
#include <stdlib.h>
#include<QDebug>
#include<qlibrary.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*QLibrary mylib("./libtesrdl2.dll");
    if (mylib.load())              //判断是否正确加载
    {
        typedef int (*Fun)(int,int); //定义函数指针，以备调用
        Fun open=(Fun)mylib.resolve("AddInt");
        if(open)
        {
            int result=open(5,6);      //这里函数指针调用dll中的 add() 函数
            qDebug()<<result;
        }
        else qDebug()<<"asd";
    }
    else
        qDebug()<<"fail";*/
    MainWindow w;
    w.show();
    w.setWindowTitle("文件管理器");
    return a.exec();
}
