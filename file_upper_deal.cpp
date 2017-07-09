#include "file_upper_deal.h"
#include<qvector.h>
#include<QList>
File_Upper_Deal::File_Upper_Deal(QString file_name, QString file_path)
{
    this->file_name=file_name;
    this->file_path=file_path;
}
bool File_Upper_Deal::file_open()
{
    return true;
}
bool File_Upper_Deal::file_close()
{
    return true;
}
QString File_Upper_Deal::file_read()
{
    QString user;
    user.append("");
    return user;
}
bool File_Upper_Deal::file_create()
{
    return true;
}
bool File_Upper_Deal::file_mkdir()
{
    return true;
}
bool File_Upper_Deal::file_delete()
{
    return true;
}
bool File_Upper_Deal::file_write()
{
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
