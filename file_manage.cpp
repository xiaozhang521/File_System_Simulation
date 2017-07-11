#include "file_manage.h"
#include "ui_file_manage.h"
#include<QDebug>
#include<file_upper_deal.h>
#include<QList>
#include<QPair>
#include<QVBoxLayout>
#include<qlistwidget.h>
#include<QInputDialog>
#include<QMessageBox>
File_Manage::File_Manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::File_Manage)
{
    ui->setupUi(this);
    user_name="";
    current_path="/";
    choose_name="";
    choose_type="";
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem *)),this,SLOT(change_chioce()));
    connect(ui->pushButton,SIGNAL(released()),this,SLOT(logout()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(path_up()));
}
//刷新事件
void File_Manage::paintEvent(QPaintEvent *)
{
}
//显示事件
void File_Manage::showEvent(QShowEvent *)
{
    qDebug()<<"show";
    ui->label_2->setText(user_name);
    ui->label_4->setText(current_path);
    File_Path_Find file_find(current_path);
    QList<QPair<QString,QString> > file_detail=file_find.file_dir();
    ui->listWidget->setIconSize(QSize(80,70));
    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setMovement(QListView::Static);
    for(int i=0;i<file_detail.length();++i)
    {
        QString tmp=file_detail.at(i).first;
        QIcon icon;
        QListWidgetItem *item=new QListWidgetItem();
        item->setText(tmp);
        if(file_detail.at(i).second=="file")
        {
            icon.addFile("./file.png");
            item->setIcon(icon);
            item->setWhatsThis("file");
        }
        else
        {
            icon.addFile("./folder.png");
            item->setIcon(icon);
            item->setWhatsThis("folder");
        }
        ui->listWidget->addItem(item);
    }
}

//右击菜单
void File_Manage::contextMenuEvent ( QContextMenuEvent * event )
{
    QMenu* popMenu = new QMenu(this);
    QListWidgetItem *choose_item=ui->listWidget->itemAt( event->x()-ui->listWidget->x(), event->y()-ui->listWidget->y());
    //qDebug()<<ui->listWidget->itemAt( event->x()-ui->listWidget->x(), event->y()-ui->listWidget->y());
    if(choose_item!= NULL) //如果有item则添加"修改"菜单 [1]*
    {
        choose_name=choose_item->text();
        if(choose_item->whatsThis()=="file")
        {
            QAction *action1=new QAction("打开文件", this);
            QAction *action2=new QAction("删除文件", this);
            connect(action1,SIGNAL(triggered()),this,SLOT(show_text_window()));
            connect(action2,SIGNAL(triggered()),this,SLOT(delete_file()));
            popMenu->addAction(action1);
            popMenu->addAction(action2);
            choose_type="file";
        }
        else
        {
            QAction *action1=new QAction("打开文件夹", this);
            QAction *action2=new QAction("删除文件夹", this);
            QString file_name=choose_item->text();
            connect(action1,SIGNAL(triggered()),this,SLOT(change_path()));
            connect(action2,SIGNAL(triggered()),this,SLOT(test()));
            popMenu->addAction(action1);
            popMenu->addAction(action2);
            choose_type="folder";
        }
        QAction *action5=new QAction("属性", this);
        connect(action5,SIGNAL(triggered()),this,SLOT(show_attributes()));
        popMenu->addAction(action5);
    }
    QAction *action3=new QAction("新建文件", this);
    connect(action3,SIGNAL(triggered()),this,SLOT(add_file()));
    QAction *action4=new QAction("新建文件夹", this);
    connect(action4,SIGNAL(triggered()),this,SLOT(add_folder()));
    popMenu->addAction(action3);
    popMenu->addAction(action4);
    popMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置
}

//选择改变
void File_Manage::change_chioce()
{
    choose_name=ui->listWidget->currentItem()->text();
    if(ui->listWidget->currentItem()->whatsThis()=="file")
    {
        choose_type="file";
    }
    else
    {
        choose_type="folder";
    }
}
//改变文件路径
void File_Manage::change_path()
{
    this->current_path=current_path+choose_name+"/";
    ui->listWidget->clear();
    this->hide();
    this->show();
}
//向上
void File_Manage::path_up()
{
    if(current_path.length()==1)
    {
        QMessageBox::information(this, tr("提示"), "已经是根目录！");
    }
    else
    {
        for(int i=current_path.length()-2;i>=0;--i)
        {
            if(current_path.at(i)=='/')
            {
                current_path=current_path.mid(0,i+1);
            }
        }
        ui->listWidget->clear();
        this->hide();
        this->show();
    }
}

//登出
void File_Manage::logout()
{
    this->hide();
    ui->listWidget->clear();
    user_name="";
    current_path="/";
    choose_name="";
    choose_type="";
    this->parentWidget()->resize(400,300);
}
//测试槽
void File_Manage::test()
{
    qDebug()<<"asd";
}

//显示文本编辑
void File_Manage::show_text_window()
{
    File_Upper_Deal *upper_deal=new File_Upper_Deal(choose_name,current_path);
    text_edit.file_upper_deal=upper_deal;
    this->text_edit.show();
}

//显示属性
void File_Manage::show_attributes()
{
    File_Upper_Deal *upper_deal=new File_Upper_Deal(choose_name,current_path);
    this->attribute.file_deal=upper_deal;
    this->attribute.show();
}

//删除文件
void File_Manage::delete_file()
{
    QList<QListWidgetItem *>list=ui->listWidget->findItems(choose_name,Qt::MatchExactly);
    for(int i=0;i<list.size();++i)
    {
        if(list.at(i)->whatsThis()==choose_type)
        {
            delete list.at(i);
        }
    }
}
//删除文件夹
void File_Manage::delete_folder()
{

}

//添加文件
void File_Manage::add_file()
{
    bool isOK;
    QString text=QInputDialog::getText(NULL, "输入文件名", "请输入文件名",
                          QLineEdit::Normal, "newfile", &isOK);
    if(isOK)
    {
        QIcon icon;
        QListWidgetItem *item=new QListWidgetItem();
        icon.addFile("./file.png");
        item->setIcon(icon);
        item->setWhatsThis("file");
        item->setText(text);
        ui->listWidget->addItem(item);
    }
}
//添加文件夹
void File_Manage::add_folder()
{
    bool isOK;
    QString text=QInputDialog::getText(NULL, "输入文件夹名", "请输入文件夹名",
                          QLineEdit::Normal, "newfolder", &isOK);
    if(isOK)
    {
        QIcon icon;
        QListWidgetItem *item=new QListWidgetItem();
        icon.addFile("./folder.png");
        item->setIcon(icon);
        item->setWhatsThis("folder");
        item->setText(text);
        ui->listWidget->addItem(item);
    }
}
//设置用户
void File_Manage::setUser(QString n, int u, QString g, QString gn)
{
    user.name=n;
    user.uid=u;
    user.gid=g;
    user.gname=gn;
}
File_Manage::~File_Manage()
{
    delete ui;
}

