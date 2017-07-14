#include "attribute.h"
#include "ui_attribute.h"
#include<qlibrary.h>
#include<QDebug>
#include<QDateTime>
Attribute::Attribute(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Attribute)
{
    ui->setupUi(this);
}
void Attribute::showEvent(QShowEvent *)
{
    QLibrary mylib("./testfile3.dll");
    if (mylib.load())              //判断是否正确加载
    {
        typedef struct m_inode *(*Fun)(char *name); //定义函数指针，以备调用
        Fun detail=(Fun)mylib.resolve("detail");
        QByteArray ba = file_deal->file_name.toLatin1();
        m_inode *inode=detail(ba.data());
        ui->label_3->setText(file_deal->file_name);
        ui->label_6->setText(QString::number(inode->file_len)+"B");
        QDateTime time = QDateTime::fromTime_t(inode->mtime);
                //qDebug()<<"i"<<inode->file_len<<time.toString("yyyy-MM-dd hh:mm:ss");
        ui->label_4->setText(time.toString("yyyy-MM-dd hh:mm:ss"));
    }
    else
        qDebug()<<"fail";
}
Attribute::~Attribute()
{
    delete ui;
}
