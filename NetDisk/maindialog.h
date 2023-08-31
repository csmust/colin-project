#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QCloseEvent>  //添加关闭事件头文件
#include <QMenu>
#include "common.h"
#include "mytablewidgetitem.h"

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

signals:
    //关闭事件的信号
    void SIG_close();
    //什么绝对路径的文件，上传到什么目录下
    void SIG_uploadFile(QString path , QString dir);

public:
    explicit MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

    //添加窗口的关闭事件，斜体代表重写的虚函数。
    void closeEvent(QCloseEvent *event);
private slots:
    void on_pb_file_clicked();

    void on_pb_transmit_clicked();

    void on_pb_share_clicked();

    void on_pb_addFile_clicked();

    void slot_addFolder(bool flag);
    void slot_uploadFile(bool flag);
    void slot_uploadFolder(bool flag);

    void slot_insertUploadFile (FileInfo& info);
    void slot_insertUploadComplete (FileInfo& info);
    void slot_updateUploadFileProgress(int timestamp,int pos);
    void slot_deleteUploadFileByRow(int row);


private:
    Ui::MainDialog *ui;
    QMenu m_menuAddFile;
    friend class CKernel;
};

#endif // MAINDIALOG_H

//点击 叉叉x   --》执行关闭事件  -》 弹窗询问  --=》发送关闭信号    核心类接收 然后回收资源
