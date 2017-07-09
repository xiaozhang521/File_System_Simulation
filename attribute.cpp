#include "attribute.h"
#include "ui_attribute.h"

Attribute::Attribute(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Attribute)
{
    ui->setupUi(this);
}

Attribute::~Attribute()
{
    delete ui;
}
