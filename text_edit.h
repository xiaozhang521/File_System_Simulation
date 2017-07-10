#ifndef TEXT_EDIT_H
#define TEXT_EDIT_H

#include <QWidget>
#include<file_upper_deal.h>
namespace Ui {
class Text_Edit;
}

class Text_Edit : public QWidget
{
    Q_OBJECT

public:
    explicit Text_Edit(QWidget *parent = 0);
    void show_text(QString content);
    File_Upper_Deal *file_upper_deal;
    ~Text_Edit();
private slots:
    void close();
    void save_file();

private:
    Ui::Text_Edit *ui;
protected:
    void showEvent(QShowEvent *);
};

#endif // TEXT_EDIT_H
