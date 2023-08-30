#include "maindialog.h"
#include "ui_maindialog.h"
#include<QMessageBox>

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::closeEvent(QCloseEvent *event)
{
    //infomation about question warring 等
    if(QMessageBox::question(this,"退出提示","是否退出？")  //有返回值
                    == QMessageBox::Yes)
    {

        event->accept();  //同意 关闭事件请求
        Q_EMIT SIG_close();
    }
    else{
        event->ignore();   //忽略 关闭事件退出询问
    }
}
