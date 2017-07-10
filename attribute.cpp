#include "attribute.h"
#include "ui_attribute.h"

Attribute::Attribute(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Attribute)
{
    ui->setupUi(this);
}
void Attribute::showEvent(QShowEvent *)
{
    //file_deal->file_attribute();
    ui->label_3->setText(file_deal->file_name);
    ui->label_4->setText("");
    ui->label_6->setText("");
}
Attribute::~Attribute()
{
    delete ui;
}
