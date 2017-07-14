#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QWidget>
#include<file_upper_deal.h>
namespace Ui {
class Attribute;
}
struct m_inode{
    short mode; //类型和属性
    short uid; //文件宿主的用户ID
    int file_len; //文件长度（字节）
    int mtime; //修改时间
    char gid; //文件宿主的组ID
    char nlinks; //链接数（有多少个文件目录项指向该i节点）
    short zone[9]; //逻辑块号数组：0-6直接，7一次间接，8二次间接
    //以下仅内存
    int atime; //最后访问时间
    int ctime; //节点自身修改时间
    int inum; //i节点号
    int icount; //i节点引用计数
    int dirty; //脏标志
};
class Attribute : public QWidget
{
    Q_OBJECT

public:
    explicit Attribute(QWidget *parent = 0);
    File_Upper_Deal *file_deal;
    ~Attribute();

private:
    Ui::Attribute *ui;
protected:
    void showEvent(QShowEvent *);
};

#endif // ATTRIBUTE_H
