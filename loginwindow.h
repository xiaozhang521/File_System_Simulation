#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<file_manage.h>
#include<qdebug.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    File_Manage file_manage;
private slots:
    void checkPassword();
    void create_user();
};

#endif // MAINWINDOW_H
