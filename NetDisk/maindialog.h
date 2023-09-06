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
    //上传什么路径的文件夹 到什么目录下面
    void SIG_uploadFolder(QString path , QString dir);
    //什么文件id，什么目录下的文件  下载
    void SIG_downloadFile(int fileid,QString dir);
    //什么文件id，什么目录下的文件夹 下载
    void SIG_downloadFolder(int fileid,QString dir);
    //什么路径下创建什么名字的文件夹
    void SIG_addFolder(QString name,QString dir);
    //双击改变路径,希望更新当前目录
    void SIG_changeDir(QString dir);

    //分享  什么目录下面的文件列表
    void SIG_shareFile(QVector<int> fileidArray, QString dir);
    //获取什么分享码的文件 添加到什么目录
    void SIG_getShareByLink(int code ,QString dir);
    //删除什么目录下的一系列文件
    void SIG_deleteFile(QVector<int> fileidArray, QString dir);

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

    void slot_downloadFile(bool flag);//点击下载，触发此下载文件或者文件夹的槽函数
    void slot_shareFile(bool flag);
    void slot_deleteFile(bool flag);

    void slot_insertUploadFile (FileInfo& info);
    void slot_insertDownloadFile (FileInfo& info);
    void slot_insertUploadComplete (FileInfo& info);  //在已完成中添加已上传
    void slot_insertDownloadComplete(FileInfo& info);  //在已完成中添加已下载
    void slot_insertShareFileInfo(QString name , int size ,QString time,int shareLink);
    void slot_updateUploadFileProgress(int timestamp,int pos);  //更新上传进度条
    void slot_updateDownloadFileProgress(int timestamp,int pos);  //更新下载进度条

    void slot_deleteUploadFileByRow(int row);  //上传完后删除界面上传中的某一行
    void slot_deleteDownloadFileByRow(int row); //下载完后删除界面下载中的某一行
    void slot_insertFileInfo(FileInfo& info);    //在界面显示网盘中已有的某一个文件信息
    void slot_openPath(bool flag);

    void slot_deleteAllFileInfo();
    void slot_deleteAllShareInfo();//删除界面所有的分享信息
    void slot_getShare(bool flag);


    void on_table_file_cellClicked(int row, int column);

    void on_table_file_customContextMenuRequested(const QPoint &pos);

    void on_table_file_cellDoubleClicked(int row, int column);

    void on_pb_prev_clicked();

private:
    Ui::MainDialog *ui;
    QMenu m_menuAddFile;
    QMenu m_menuFileInfo;//文件信息的菜单对象
    friend class CKernel;

};

#endif // MAINDIALOG_H

//点击 叉叉x   --》执行关闭事件  -》 弹窗询问  --=》发送关闭信号    核心类接收 然后回收资源
