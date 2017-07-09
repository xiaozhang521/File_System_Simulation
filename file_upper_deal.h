#ifndef FILE_UPPER_DEAL_H
#define FILE_UPPER_DEAL_H
#include<qstring.h>
#include<QPair>
class File_Upper_Deal
{
private:
    QString file_name;
    QString file_path;
public:
    File_Upper_Deal(QString file_name,QString file_path);
    bool file_open();
    QString file_read();
    bool file_create();
    bool file_mkdir();
    bool file_close();
    bool file_write();
    bool file_delete();
    bool file_chdir();
};

class File_Path_Find
{
private:
    QString file_path;
public:
    File_Path_Find(QString file_path);
    QList<QPair<QString, QString> > file_dir();
};

#endif // FILE_UPPER_DEAL_H
