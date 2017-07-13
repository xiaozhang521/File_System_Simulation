#ifndef FILE_UPPER_DEAL_H
#define FILE_UPPER_DEAL_H
#include<qstring.h>
#include<QPair>
#include<qlibrary.h>
#define URWX    0000700 //user read\write\exe or search
#define UR      0000400 //user read
#define UW      0000200 //user write
#define UX      0000100 //user exe or search
#define GRWX    0000070 //group read\write\exe or search
#define GR      0000040 //group read
#define GW      0000020 //group write
#define GX      0000010 //group exe or search
#define ORWX    0000007 //others read\write\exe or search
#define OR      0000004 //others read
#define OW      0000002 //others write
#define OX      0000001 //others exe or search
extern QMap<QString,int> file_point;
class File_Upper_Deal
{
public:
    QString file_name;
    QString file_path;
    QLibrary mylib;
public:
    File_Upper_Deal(QString file_name,QString file_path);
    bool file_open();
    QString file_read();
    int file_create();
    bool file_mkdir();
    bool file_close();
    bool file_write(QString text);
    bool file_delete();
    void file_attribute();
};
struct deinfo{
    char name[14];
    int type;
    struct deinfo *next;
};
class File_Path_Find
{
private:
    QString file_path;
    QLibrary mylib;
public:
    File_Path_Find(QString file_path);
    QList<QPair<QString, QString> > file_dir();
    bool file_chdir();
    bool file_rmdir();
};

#endif // FILE_UPPER_DEAL_H
