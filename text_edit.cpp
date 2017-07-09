#include "text_edit.h"
#include "ui_text_edit.h"

Text_Edit::Text_Edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Text_Edit)
{
    ui->setupUi(this);
}

Text_Edit::~Text_Edit()
{
    delete ui;
}
