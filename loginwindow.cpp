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
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(create_user()));
}
void MainWindow::checkPassword()
{
    File_Upper_Deal *upper_deal=new File_Upper_Deal("user","/");
    upper_deal->file_open();
    QString user_message=upper_deal->file_read();
    upper_deal->file_close();
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
void MainWindow::create_user()
{
    QString name=ui->lineEdit->text();
    QString psw=ui->lineEdit_2->text();
    File_Upper_Deal *upper_deal=new File_Upper_Deal("user","/");
    upper_deal->file_open();
    if(name!=""&&psw!="")
    {
        QMessageBox::information(this, tr("提示"), "注册成功");
    }
    else {
        QMessageBox::information(this, tr("提示"), "用户名或密码不能为空");
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
