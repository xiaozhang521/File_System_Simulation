#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QWidget>
#include<file_upper_deal.h>
namespace Ui {
class Attribute;
}

class Attribute : public QWidget
{
    Q_OBJECT

public:
    explicit Attribute(QWidget *parent = 0);
    File_Upper_Deal *file_deal;
    ~Attribute();

private:
    Ui::Attribute *ui;
protected:
    void showEvent(QShowEvent *);
};

#endif // ATTRIBUTE_H
