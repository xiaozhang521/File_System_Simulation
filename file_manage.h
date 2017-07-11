#ifndef FILE_MANAGE_H
#define FILE_MANAGE_H

#include <QMainWindow>
#include <QString>
#include<QMouseEvent>
#include<text_edit.h>
#include<attribute.h>
namespace Ui {
class File_Manage;
}
class User
{
public:

    QString name;
    int uid;
    QString gid;
    QString gname;
};
class File_Manage : public QMainWindow
{
    Q_OBJECT

public:
    QString user_name;
    QString current_path;
    QString choose_name;
    QString choose_type;
    User user;
    void setUser(QString n,int u,QString g,QString gn);
    explicit File_Manage(QWidget *parent = 0);
    ~File_Manage();

private:
    Ui::File_Manage *ui;
    Text_Edit text_edit;
    Attribute attribute;

private slots:
    void change_chioce();
    void test();
    void show_text_window();
    void logout();
    void show_attributes();
    void change_path();
    void delete_file();
    void delete_folder();
    void add_file();
    void add_folder();
    void path_up();
protected:
    void showEvent(QShowEvent *);
    void contextMenuEvent ( QContextMenuEvent * event );
    void paintEvent(QPaintEvent *);
};

#endif // FILE_MANAGE_H
