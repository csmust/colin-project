#include "maindialog.h"
#include "ui_maindialog.h"
#include<QMessageBox>
#include<QDebug>
MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    //默认文件分页
    ui->sw_page->setCurrentIndex(0);
    //传输页默认分页
    ui->tw_transmit->setCurrentIndex(2);
    //设置标题栏
    this->setWindowTitle("我的网盘");
    //设置最小最大化
    this->setWindowFlags(Qt::WindowMinMaxButtonsHint|Qt::WindowCloseButtonHint);

    //首先定义菜单项
    QAction * action_addFolder = new QAction(QIcon(":/images/folder.png") , "新建文件夹");
    QAction * action_uploadFile = new QAction( "上传文件");
    QAction * action_uploadFolder = new QAction( "上传文件夹");

    //添加菜单项
    m_menuAddFile.addAction(action_addFolder);
    m_menuAddFile.addSeparator();//加入分隔符
    m_menuAddFile.addAction(action_uploadFile);
    m_menuAddFile.addAction(action_uploadFolder);

    connect(action_addFolder,SIGNAL(triggered(bool)),
            this,SLOT(slot_addFolder(bool)));
    connect(action_uploadFile,SIGNAL(triggered(bool)),
            this,SLOT(slot_uploadFile(bool)));
    connect(action_uploadFolder,SIGNAL(triggered(bool)),
            this,SLOT(slot_uploadFolder(bool)));
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

void MainDialog::on_pb_file_clicked()
{
    ui->sw_page->setCurrentIndex(0);
}


void MainDialog::on_pb_transmit_clicked()
{
        ui->sw_page->setCurrentIndex(1);
}


void MainDialog::on_pb_share_clicked()
{
        ui->sw_page->setCurrentIndex(2);
}

//点击添加文件图标
void MainDialog::on_pb_addFile_clicked()
{
    //弹出菜单
    m_menuAddFile.exec(QCursor::pos());//鼠标的坐标  在该点显示菜单
}

void MainDialog::slot_addFolder(bool flag)
{
    qDebug()<<__func__;
}


//上传文件
#include<QFileDialog>
void MainDialog::slot_uploadFile(bool flag)
{
    qDebug()<<__func__;
    //弹出窗口 选择文件 路径path
    QString path = QFileDialog::getOpenFileName(this,"选择文件","./");
    if(path.isEmpty()) return;


    //目前上传的有没有一样的文件 如果是 取消  TODO

    //发送信号 核心类处理  传递的信息 ：上传什么文件到什么目录下
    QString dir = ui->lb_path->text();//获取网盘app界面中的路径
    Q_EMIT SIG_uploadFile(path, dir);
}

void MainDialog::slot_uploadFolder(bool flag)
{
    qDebug()<<__func__;
}

//上传信息插入
#include<QProgressBar>
void MainDialog::slot_insertUploadFile(FileInfo &info)
{
    //表格插入信息
    //列：文件 大小 时间 速率 进度 按钮
    //1、新增一行 获取当前行+1 设置行数
    int rows = ui->table_upload->rowCount() ;
    ui->table_upload->setRowCount(rows+1);
    //2、设置这一行的每一列控件 添加对象
    MyTableWidgetItem *item0 = new MyTableWidgetItem;
    item0->slot_setInfo(info);
    ui->table_upload->setItem(rows , 0 , item0);

    QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(info.size));
    ui->table_upload->setItem(rows , 1 , item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(info.time);
    ui->table_upload->setItem(rows , 2, item2);

    QTableWidgetItem *item3 = new QTableWidgetItem("0KB/s");
    ui->table_upload->setItem(rows, 3 , item3);

    //进度条
    QProgressBar* progress = new QProgressBar;
    progress->setMaximum(info.size);
    ui->table_upload->setCellWidget(rows , 4 , progress);

    //暂停开始按钮
    QPushButton* button = new QPushButton;
    if(info.isPause==0){
        button->setText("暂停");
    }else{
        button->setText("开始");
    }
    ui->table_upload->setCellWidget(rows,5,button);
}

//上传完成
void MainDialog::slot_insertUploadComplete(FileInfo &info)
{
    //列：文件 大小 时间 上传完成
    //1、新增一行 获取当前行+1 设置行数
    int rows = ui->table_complete->rowCount();
    ui->table_complete->setRowCount(rows+1);
    //2、设置这一行的每一列控件 添加对象
    MyTableWidgetItem *item0 = new MyTableWidgetItem;
    item0->slot_setInfo(info);
    ui->table_complete->setItem(rows , 0 , item0);

    QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(info.size));
    ui->table_complete->setItem(rows , 1 , item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(info.time);
    ui->table_complete->setItem(rows , 2, item2);

    QTableWidgetItem *item3 = new QTableWidgetItem("上传完成");
    ui->table_complete->setItem(rows, 3 , item3);
}

void MainDialog::slot_updateUploadFileProgress(int timestamp, int pos)
{
    //遍历所有项 第0列
    int row = ui->table_upload->rowCount();
    for(int i = 0 ;i<row;i++){
        //取到每一个文件信息的时间戳，看是否一致
        MyTableWidgetItem* item0 =(MyTableWidgetItem*)ui->table_upload->item(i,0);
        if(item0->m_info.timestamp == timestamp){
            //一致 ，更新进度
            QProgressBar* item4 =(QProgressBar*)ui->table_upload->cellWidget(i,4);
            item0->m_info.pos=pos;
            item4->setValue(pos);
            //看是否结束
            if(item4->value() >= item4->maximum()){
                //是 删除这一项 添加到已完成
                slot_deleteUploadFileByRow(i);
                slot_insertUploadComplete(item0->m_info);
                return;
            }
        }
    }



    //一致，更新进度

    //看是否结束
    //是 删除这一项 添加到完成
    //return
}

void MainDialog::slot_deleteUploadFileByRow(int row)
{

}

