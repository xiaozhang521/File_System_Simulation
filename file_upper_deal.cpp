#include "file_upper_deal.h"
#include<qvector.h>
#include<QList>
#include<qdebug.h>
File_Upper_Deal::File_Upper_Deal(QString file_name, QString file_path)
{
    this->file_name=file_name;
    this->file_path=file_path;
    mylib.setFileName("./testfile2.dll");
}
bool File_Upper_Deal::file_open()
{
    if (mylib.load())              //判断是否正确加载
    {
        typedef int (*Fun)(char *pathname,int flag,int mode);
        Fun sys_open=(Fun)mylib.resolve("sys_open");
        QByteArray ba = file_name.toLatin1();
        int tmp=sys_open(ba.data(),02,UR|UW);
        qDebug()<<tmp<<file_name;
    }
    return true;
}
bool File_Upper_Deal::file_close()
{
    int fd=file_point[file_name];
    if (mylib.load())              //判断是否正确加载
    {
        typedef int (*Fun)(int fd); //定义函数指针，以备调用
        Fun close=(Fun)mylib.resolve("sys_close");
            int tmp=close(fd);
            qDebug()<<tmp;
    }
    return true;
}
QString File_Upper_Deal::file_read()
{
    QString content="";
    int fd=file_point[file_name];
    qDebug()<<"fd is"<<fd;
    if (mylib.load())              //判断是否正确加载
    {
        typedef int (*Fun)(int fd);
        Fun getcount=(Fun)mylib.resolve("return_file_size");
        int size=getcount(fd);
        typedef int (*Fun2)(int fd,char *buf,int count); //定义函数指针，以备调用
        Fun2 read=(Fun2)mylib.resolve("sys_read");
        char s[100];
        int tmp=read(fd,s,size);
        content=s;
        qDebug()<<"return:"<<tmp<<" length:"<<size;
    }
    return content;
}
int File_Upper_Deal::file_create()
{
    if (mylib.load())              //判断是否正确加载
    {
        typedef int (*Fun)(char *pathname, int mode); //定义函数指针，以备调用
        Fun create=(Fun)mylib.resolve("sys_create");
        if(create)
        {
            QByteArray ba = file_name.toLatin1();
            int filepointer=create(ba.data(),UR|UW);
            file_point[file_name]=filepointer;
            qDebug()<<filepointer<<file_name;
        }
        else qDebug()<<"func fail";
    }
    else
        qDebug()<<"fail";
}
bool File_Upper_Deal::file_mkdir()
{
    return true;
}
bool File_Upper_Deal::file_delete()
{
    return true;
}
bool File_Upper_Deal::file_write(QString text)
{
    if (mylib.load())              //判断是否正确加载
    {
        typedef int (*Fun)(int fd,char *buf,int count); //定义函数指针，以备调用
        Fun write=(Fun)mylib.resolve("sys_write");
        QByteArray ba = text.toLatin1();
        int tmp=write(0,ba.data(),ba.length());
        qDebug()<<tmp;
    }
    return true;
}
File_Path_Find::File_Path_Find(QString file_path)
{
    this->file_path=file_path;
}

QList<QPair<QString,QString> > File_Path_Find::file_dir()
{
    QList<QPair<QString,QString> > s;
    QPair<QString,QString> tmp;
    QString type="file";
    QString name="test";
    tmp.first=name;
    tmp.second=type;
    s.append(tmp);
    type="folder";
    name="test2";
    tmp.first=name;
    tmp.second=type;
    s.append(tmp);
    type="file";
    name="test3";
    tmp.first=name;
    tmp.second=type;
    s.append(tmp);
    return s;
}
