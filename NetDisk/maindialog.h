#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QCloseEvent>  //添加关闭事件头文件

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

signals:
    //关闭事件的信号
    void SIG_close();

public:
    explicit MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

    //添加窗口的关闭事件，斜体代表重写的虚函数。
    void closeEvent(QCloseEvent *event);
private:
    Ui::MainDialog *ui;
};

#endif // MAINDIALOG_H

//点击 叉叉x   --》执行关闭事件  -》 弹窗询问  --=》发送关闭信号    核心类接收 然后回收资源
