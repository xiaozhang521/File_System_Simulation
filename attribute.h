#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QWidget>

namespace Ui {
class Attribute;
}

class Attribute : public QWidget
{
    Q_OBJECT

public:
    explicit Attribute(QWidget *parent = 0);
    ~Attribute();

private:
    Ui::Attribute *ui;
};

#endif // ATTRIBUTE_H
