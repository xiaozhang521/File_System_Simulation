#include "file_upper_deal.h"
#include<qvector.h>
#include<QList>
#include<qdebug.h>
File_Upper_Deal::File_Upper_Deal(QString file_name, QString file_path)
{
    this->file_name=file_name;
    this->file_path=file_path;
    mylib.setFileName("./testfile3.dll");
}
bool File_Upper_Deal::file_open()
{
    if (mylib.load())              //判断是否正确加载
    {
        typedef int (*Fun)(char *pathname,int flag,int mode);
        Fun sys_open=(Fun)mylib.resolve("sys_open");
        QByteArray ba = file_name.toLatin1();
        int tmp=sys_open(ba.data(),02,UR|UW);
        qDebug()<<"open "<<tmp<<file_name;
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
        char s[150];
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
            qDebug()<<"create file:"<<filepointer;
            //file_close();
        }
        else qDebug()<<"func fail";
    }
    else
        qDebug()<<"fail";
}
bool File_Upper_Deal::file_mkdir()
{
    if (mylib.load())              //判断是否正确加载
    {
        typedef int (*Fun)(char *pathname, int mode); //定义函数指针，以备调用
        Fun mkdir=(Fun)mylib.resolve("sys_mkdir");
        QByteArray ba = file_name.toLatin1();
        int tmp=mkdir(ba.data(),UR|UW);
        qDebug()<<"create folder"<<tmp;
    }
    return true;
}
bool File_Upper_Deal::file_delete()
{
    if (mylib.load())              //判断是否正确加载
    {
        typedef int (*Fun)(char *name); //定义函数指针，以备调用
        Fun rmfile=(Fun)mylib.resolve("sys_unlink");
        QByteArray ba = file_name.toLatin1();
        int tmp=rmfile(ba.data());
        qDebug()<<"delete return"<<tmp;
    }
    return true;
}

//文件读
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

//路径寻找类
File_Path_Find::File_Path_Find(QString file_path)
{
    this->file_path=file_path;
    mylib.setFileName("./testfile3.dll");
}
//改变路径
bool File_Path_Find::file_chdir()
{
    if (mylib.load())              //判断是否正确加载
    {
        typedef int (*Fun)(char *filename); //定义函数指针，以备调用
        Fun chdir=(Fun)mylib.resolve("sys_chdir");
        QByteArray ba = file_path.toLatin1();
        qDebug()<<file_path;
        int tmp=chdir(ba.data());
        qDebug()<<"change filepath"<<tmp;
    }
    return true;
}
//删除文件
bool File_Path_Find::file_rmdir()
{
    if (mylib.load())              //判断是否正确加载
    {
        typedef int (*Fun)(char *filename); //定义函数指针，以备调用
        Fun rmdir=(Fun)mylib.resolve("sys_rmdir");
        QByteArray ba = file_path.toLatin1();
        qDebug()<<file_path;
        int tmp=rmdir(ba.data());
        qDebug()<<"remove filepath"<<tmp;
    }
}
QList<QPair<QString,QString> > File_Path_Find::file_dir()
{
    QList<QPair<QString,QString> > s;
    if (mylib.load())              //判断是否正确加载
    {
        typedef struct deinfo *(*Fun)(); //定义函数指针，以备调用
        Fun dir=(Fun)mylib.resolve("sys_dir");
        if(dir)
        {
            deinfo *nowp=dir();
            QPair<QString,QString> tmp;
            while(nowp!=NULL)
            {
                tmp.first=nowp->name;
                if(nowp->type==0)
                {
                    tmp.second="file";
                }
                else tmp.second="folder";
                if(tmp.first!=".."&&tmp.first!=".")
                s.append(tmp);
                qDebug()<<tmp.first<<"append";
                nowp=nowp->next;
            }
            qDebug()<<"suceed";
        }
        else qDebug()<<"func fail";
    }
    else
        qDebug()<<"fail";
    return s;
}
