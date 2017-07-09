#include "loginwindow.h"
#include "ui_loginwindow.h"
#include<qdebug.h>
#include<file_upper_deal.h>
#include<qmessagebox.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->file_manage.hide();
    file_manage.setParent(this);
    connect(ui->pushButton,SIGNAL(released()),this,SLOT(checkPassword()));
}
void MainWindow::checkPassword()
{
    File_Upper_Deal *upper_deal=new File_Upper_Deal("user","/");
    upper_deal->file_open();
    QString user_message=upper_deal->file_read();
    QString name=ui->lineEdit->text();
    QString psw=ui->lineEdit_2->text();
    if(true)//name=="admin"&&psw=="admin")
    {
        this->file_manage.user_name=name;
        this->file_manage.show();
        this->resize(684,444);
    }
    else
    {
        QMessageBox::information(this, tr("提示"), "用户名错误或密码错误");
    }
}
void MainWindow::reshow()
{
    //qDebug()<<this->file_manage.ui->pushButton;
}
MainWindow::~MainWindow()
{
    delete ui;
}
