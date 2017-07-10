#include "text_edit.h"
#include "ui_text_edit.h"
#include<QMessageBox>
Text_Edit::Text_Edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Text_Edit)
{
    ui->setupUi(this);
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(close()));
    connect(ui->pushButton,SIGNAL(released()),this,SLOT(save_file()));
}
//关闭
void Text_Edit::close()
{
    this->hide();
}
//存储
void Text_Edit::save_file()
{
    file_upper_deal->file_open();
    file_upper_deal->file_write(ui->textEdit->toPlainText());
    file_upper_deal->file_close();
    QMessageBox::information(this, tr("提示"), "保存成功");
}
void Text_Edit::show_text(QString content)
{
    ui->textEdit->setText(content);
}
//显示事件
void Text_Edit::showEvent(QShowEvent *)
{
    file_upper_deal->file_open();
    ui->textEdit->setText(file_upper_deal->file_read());
    file_upper_deal->file_close();
}
Text_Edit::~Text_Edit()
{
    delete ui;
}
