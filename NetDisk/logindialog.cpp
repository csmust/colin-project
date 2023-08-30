#include "logindialog.h"
#include "ui_logindialog.h"

#define PASSWORD_MAX_LEN (20)
#define NAME_MAX_SIZE (10)

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    setWindowTitle("登录&注册");

    //窗口默认在注册页
    ui->tw_page->setCurrentIndex(1);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

#include<QMessageBox>
#include<QRegExp>
void LoginDialog::on_pb_login_register_clicked()
{
    //注册信息采集
    QString tel  = ui ->le_tel_register->text();
    QString password = ui->le_password_register->text();
    QString confirm = ui->le_confirm_register->text();
    QString name = ui->le_name_register->text();


    //过滤
    QString tmpName  = name;
    //查看输入是否为空,或者全为空格也不行
    if(tel.isEmpty() || password.isEmpty() || confirm.isEmpty()||name.isEmpty()
        ||tmpName.remove(" ").isEmpty()){
        QMessageBox::about(this , "提示" , "输入内容，不可以为空");
        return;
    }
    //手机号是否合法
    QRegExp exp("^1[356789][0-9]\{9\}$");     //首位1，然后356789之中选一个，0-9选9个
    bool res = exp.exactMatch(tel);
    if(!res){
        QMessageBox::about (this , "提示" ,"手机号非法");
        return ;
    }
    //密码是否过长
    if(password.size() > PASSWORD_MAX_LEN){
        QMessageBox::about (this , "提示" ,"密码输入过长");
        return ;
    }
    //密码是否一致
    if(password!=confirm){
        QMessageBox::about (this , "提示" ,"两次输入密码不一致");
        return ;
    }

    //昵称 是否过长  -- 敏感词汇的过滤(外部敏感词汇表，正则表达式)
    if(name.size() > NAME_MAX_SIZE){
        QMessageBox::about (this , "提示" ,"昵称过长，不能超过10个字节");
        return ;
    }

    //发送注册信号
    Q_EMIT SIG_registerCommit(tel , password , name);
}


void LoginDialog::on_pb_clear_register_clicked()
{
    ui->le_confirm_register->setText("");
    ui->le_name_register->setText("");
    ui->le_password_register->setText("");
    ui->le_tel_register->setText("");
}

//点击登录
void LoginDialog::on_pb_login_clicked()
{
    //登录信息采集
    QString tel  = ui ->le_tel->text();
    QString password = ui->le_password->text();



    //过滤

    //查看输入是否为空,或者全为空格也不行
    if(tel.isEmpty() || password.isEmpty() ){
        QMessageBox::about(this , "提示" , "输入内容，不可以为空");
        return;
    }
    //手机号是否合法
    QRegExp exp("^1[356789][0-9]\{9\}$");     //首位1，然后356789之中选一个，0-9选9个
    bool res = exp.exactMatch(tel);
    if(!res){
        QMessageBox::about (this , "提示" ,"手机号非法");
        return ;
    }
    //密码是否过长
    if(password.size() > PASSWORD_MAX_LEN){
        QMessageBox::about (this , "提示" ,"密码输入过长");
        return ;
    }


    //发送登录信号
    Q_EMIT SIG_loginCommit(tel , password);

}


void LoginDialog::on_pb_clear_clicked()
{
    ui->le_tel->setText("");
    ui->le_password->setText("");
}

