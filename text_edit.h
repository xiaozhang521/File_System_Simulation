#ifndef TEXT_EDIT_H
#define TEXT_EDIT_H

#include <QWidget>

namespace Ui {
class Text_Edit;
}

class Text_Edit : public QWidget
{
    Q_OBJECT

public:
    explicit Text_Edit(QWidget *parent = 0);
    ~Text_Edit();

private:
    Ui::Text_Edit *ui;
};

#endif // TEXT_EDIT_H
