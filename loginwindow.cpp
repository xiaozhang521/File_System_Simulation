#include "loginwindow.h"
#include "ui_loginwindow.h"
#include<qdebug.h>
#include<file_upper_deal.h>
#include<qmessagebox.h>
#include<file_pointer.h>
#include<qlibrary.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    now_uid=0;
    this->file_manage.hide();
    file_manage.setParent(this);
    connect(ui->pushButton,SIGNAL(released()),this,SLOT(checkPassword()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(create_user()));
}
void MainWindow::closeEvent(QCloseEvent *)
{
    QLibrary mylib("./testfile3.dll");
    mylib.load();
    typedef int (*Fun)(); //定义函数指针，以备调用
    Fun sys_sync=(Fun)mylib.resolve("sys_sync");
    if(sys_sync)
    {
        int tmp=sys_sync();
        qDebug()<<tmp;
    }
    else qDebug()<<"fail";
    qDebug()<<"asd";
}
void MainWindow::checkPassword()
{
    QFile file("./user.in");
    QString name=ui->lineEdit->text();
    QString psw=ui->lineEdit_2->text();
    this->file_manage.user_name=name;
    this->file_manage.show();
    this->resize(684,444);
    /*if(file.open(QFile::ReadOnly)|QIODevice::ReadOnly)
    {
        QTextStream in(&file);
        bool flag=true;
        while(!in.atEnd())
        {
            QString str=in.readLine();
            if(str==name)
            {
                flag=false;
                if(in.readLine()==psw)
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
            else
            {
                str=in.readLine();
                str=in.readLine();
                str=in.readLine();
                str=in.readLine();
            }
        }
        if(flag)
        {
            QMessageBox::information(this, tr("提示"), "用户名错误或密码错误");
        }
    }*/
    file.close();
}
void MainWindow::create_user()
{
    QString name=ui->lineEdit->text();
    QString psw=ui->lineEdit_2->text();

    if(name!=""&&psw!="")
    {
        QFile file("./user.in");
        bool flag=true;
        if(file.open(QFile::ReadOnly)|QIODevice::ReadOnly)
        {
            QTextStream in(&file);
            while(!in.atEnd())
            {
                now_uid++;
                QString str=in.readLine();
                if(str==name)
                {
                    flag=false;
                }
                else
                {
                   str=in.readLine();
                   str=in.readLine();
                   str=in.readLine();
                   str=in.readLine();
                }
            }
        }
        file.close();
        if(flag)
        {
            if(file.open(QFile::WriteOnly|QIODevice::Append))
            {
                QTextStream out(&file);
                out<<name<<'\r'<<'\n';
                out<<psw;
                out<<"\r\n";
                out<<now_uid;
                out<<"\r\n0\r\nhome\r\n";
                QMessageBox::information(this, tr("提示"), "注册成功");
            }
            file.close();
        }
        else
        {
            QMessageBox::information(this, tr("提示"), "用户名已存在");
        }
    }
    else {
        QMessageBox::information(this, tr("提示"), "用户名或密码不能为空");
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
