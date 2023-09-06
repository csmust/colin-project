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
    //菜单动作
    QAction * action_downloadFile = new QAction("下载文件");
    QAction * action_shareFile = new QAction("分享文件");
    QAction * action_deleteFile = new QAction("删除文件");
    QAction * action_getShare = new QAction("获取分享");//获取分享到本地目录，分享预览不看了

    m_menuFileInfo.addAction(action_addFolder);
    m_menuFileInfo.addSeparator();  //加入分隔符
    m_menuFileInfo.addAction(action_downloadFile);
    m_menuFileInfo.addAction(action_shareFile);
    m_menuFileInfo.addAction(action_deleteFile);
    m_menuFileInfo.addAction("收藏");
    m_menuFileInfo.addSeparator();  //加入分隔符
    m_menuFileInfo.addAction(action_getShare);


    connect(action_downloadFile,SIGNAL(triggered(bool)),
            this,SLOT( slot_downloadFile(bool)  ));
    connect(action_shareFile,SIGNAL(triggered(bool)),
            this,SLOT( slot_shareFile(bool))  );
    connect(action_deleteFile,SIGNAL(triggered(bool)),
            this,SLOT( slot_deleteFile(bool)  ));
    connect(action_getShare,SIGNAL(triggered(bool)),
            this,SLOT( slot_getShare(bool)  ));

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

//新建文件夹
#include<QInputDialog>
void MainDialog::slot_addFolder(bool flag)
{
    qDebug()<<__func__;
    //弹出输入窗口
    QString name = QInputDialog::getText(this,"新建文件夹","输入名称");
    QString tmp = name;
    //空白符的处理
    if(name.isEmpty() || tmp.remove(" ").isEmpty() || name.length()>100){
        QMessageBox::about(this , "提示","名字非法");
            return;
    }
    //TODO 正则不可以用的名字

    //一些非法 / \ : ? < > | "
    if(name.contains("\\")||name.contains("/")||name.contains(":")||
        name.contains(">")||name.contains("*")||name.contains("<")||
        name.contains(">")||name.contains("|")||name.contains("\"")){
            QMessageBox::about(this , "提示","名字非法");
            return;
    }
    //TODO 判断是否已经存在

    //发送信号
    QString dir = ui->lb_path->text();
    Q_EMIT SIG_addFolder(name,dir);

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

//上传文件夹和内部的文件和文件夹。。递归
void MainDialog::slot_uploadFolder(bool flag)
{
    qDebug()<<"MainDialog::"<<__func__;
    //点击 弹出文件选择对话框 选择路径
    QString path = QFileDialog::getExistingDirectory(this , "选择文件夹" ,"./");
    //判断非空,用户点×，没选就是空
    if(path.isEmpty()) return;
    //过滤 是否正在传 TODO

    // 发信号 上传什么路径的文件夹 到什么目录下面
    Q_EMIT SIG_uploadFolder(path , ui->lb_path->text());
}

void MainDialog::slot_downloadFile(bool flag)
{
    qDebug()<<"MainDialog::"<<__func__;
    //遍历列表
    int rows = ui->table_file->rowCount();
    QString dir = ui->lb_path->text();// 获取界面显示的目录
    for(int i = 0 ; i<rows;i++){

        MyTableWidgetItem *item0 = (MyTableWidgetItem*)ui->table_file->item(i,0);
         //看选中的
        if(item0->checkState() == Qt::Checked){
            //TODO下载列表中已经有此下载，不能开始
            //获取类型 发送信号 下载文件或下载文件夹
            if(item0->m_info.type=="file"){
                Q_EMIT SIG_downloadFile(item0->m_info.fileid,dir);
            }else{
                Q_EMIT SIG_downloadFolder(item0->m_info.fileid,dir);

            }
        }
    }

}

void MainDialog::slot_shareFile(bool flag)
{
    qDebug()<<"MainDialog::"<<__func__;
    //申请数组 存文件id
    QVector<int> array;
    int count = ui->table_file->rowCount();
    //遍历所有项
    for(int i =0;i<count ; ++i){
        MyTableWidgetItem * item0 =(MyTableWidgetItem*)ui->table_file->item(i,0);
        //看是否是打钩的
        if(item0->checkState()==Qt::Checked){
            //添加到数组里面
            array.push_back(item0->m_info.fileid);
        }
    }

    //发送信号
    Q_EMIT SIG_shareFile(array,ui->lb_path->text());
}

//删除网盘文件或文件夹
void MainDialog::slot_deleteFile(bool flag)
{
    qDebug()<<"MainDialog::"<<__func__;
    //申请数组 存文件id
    QVector<int> array;
    int count = ui->table_file->rowCount();
    //遍历所有项
    for(int i =0;i<count ; ++i){
        MyTableWidgetItem * item0 =(MyTableWidgetItem*)ui->table_file->item(i,0);
        //看是否是打钩的
        if(item0->checkState()==Qt::Checked){
            //添加到数组里面
            array.push_back(item0->m_info.fileid);
        }
    }

    //发送信号
    Q_EMIT SIG_deleteFile(array,ui->lb_path->text());


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

    QTableWidgetItem *item1 = new QTableWidgetItem(FileInfo::getSize(info.size));
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

void MainDialog::slot_insertDownloadFile(FileInfo &info)
{
    //表格插入信息
    //列：文件 大小 时间 速率 进度 按钮
    //1、新增一行 获取当前行+1 设置行数
    int rows = ui->table_download->rowCount() ;
    ui->table_download->setRowCount(rows+1);
    //2、设置这一行的每一列控件 添加对象
    MyTableWidgetItem *item0 = new MyTableWidgetItem;
    item0->slot_setInfo(info);
    ui->table_download->setItem(rows , 0 , item0);

    QTableWidgetItem *item1 = new QTableWidgetItem(FileInfo::getSize(info.size));
    ui->table_download->setItem(rows , 1 , item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(info.time);
    ui->table_download->setItem(rows , 2, item2);

    QTableWidgetItem *item3 = new QTableWidgetItem("0KB/s");
    ui->table_download->setItem(rows, 3 , item3);

    //进度条
    QProgressBar* progress = new QProgressBar;
    progress->setMaximum(info.size);
    ui->table_download->setCellWidget(rows , 4 , progress);

    //暂停开始按钮
    QPushButton* button = new QPushButton;
    if(info.isPause==0){
        button->setText("暂停");
    }else{
        button->setText("开始");
    }
    ui->table_download->setCellWidget(rows,5,button);
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

    QTableWidgetItem *item1 = new QTableWidgetItem(FileInfo::getSize(info.size));
    ui->table_complete->setItem(rows , 1 , item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(info.time);
    ui->table_complete->setItem(rows , 2, item2);

    QTableWidgetItem *item3 = new QTableWidgetItem("上传完成");
    ui->table_complete->setItem(rows, 3 , item3);
}

 //在已完成中添加已下载
void MainDialog::slot_insertDownloadComplete(FileInfo &info)
{
    //列：文件 大小 时间 按钮
    //1、新增一行 获取当前行+1 设置行数
    int rows = ui->table_complete->rowCount();
    ui->table_complete->setRowCount(rows+1);
    //2、设置这一行的每一列控件 添加对象
    MyTableWidgetItem *item0 = new MyTableWidgetItem;
    item0->slot_setInfo(info);
    ui->table_complete->setItem(rows , 0 , item0);

    QTableWidgetItem *item1 = new QTableWidgetItem(FileInfo::getSize(info.size));
    ui->table_complete->setItem(rows , 1 , item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(info.time);
    ui->table_complete->setItem(rows , 2, item2);

    //点击按钮弹出下载后所在的文件夹
    QPushButton * button = new QPushButton;
    button ->setIcon(QIcon(":/images/folder.png"));
            //设置扁平
    button->setFlat(true);

    //tooltip 提示  方法1：通过加个提示属性获取控件外的信息   方法2：重写控件，加入额外的成员属性
    button->setToolTip(info.absolutePath);
    connect(button , SIGNAL(clicked(bool)) ,
            this , SLOT(slot_openPath(bool)));
    ui->table_complete->setCellWidget(rows, 3 , button);


//    QTableWidgetItem *item3 = new QTableWidgetItem("上传完成");
    //    ui->table_complete->setItem(rows, 3 , item3);
}

void MainDialog::slot_insertShareFileInfo(QString name, int size, QString time, int shareLink)
{
    //列：文件 大小 时间 分享码
    //1、新增一行 获取当前行+1 设置行数
    int rows = ui->table_share->rowCount();
    ui->table_share->setRowCount(rows+1);
    //2、设置这一行的每一列控件 添加对象
    QTableWidgetItem *item0 = new QTableWidgetItem(name);
    ui->table_share->setItem(rows , 0 , item0);

    QTableWidgetItem *item1 = new QTableWidgetItem(FileInfo::getSize(size));
    ui->table_share->setItem(rows , 1 , item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(time);
    ui->table_share->setItem(rows , 2, item2);

    QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(shareLink));
    ui->table_share->setItem(rows, 3 , item3);
}



#include<QProcess>
void MainDialog::slot_openPath(bool flag)
{
    QPushButton * button = (QPushButton * )QObject::sender();
    QString path = button->toolTip();
    // 转化路径分隔符
    path.replace('/' , '\\');
    //如何打开文件夹
    //explorer /select, D:\软件\NetDisk\测试.jpg
    //通过Qt 打开进程
    QProcess process;
    QStringList lst;
    //加参数方法1
//    lst.push_back("/select,");
//    lst.push_back(path);
    //加参数方法2
    lst<<QString("/select,")<<path;
    process.startDetached("explorer",lst);
}

//删除列表所有文件信息，可用于更新文件列表
void MainDialog::slot_deleteAllFileInfo()
{
    int rows= ui->table_file->rowCount();
    for(int i=rows-1;i>=0;i--){
        ui->table_file->removeRow(i);
    }
}

void MainDialog::slot_deleteAllShareInfo()
{
    int rows= ui->table_share->rowCount();
    for(int i=rows-1;i>=0;i--){
        ui->table_share->removeRow(i);
    }
}

void MainDialog::slot_getShare(bool flag)
{
    qDebug()<<"MainDialog::"<<__func__;
    //弹窗 输入分享码
    QString txt = QInputDialog::getText(this,"获取分享","输入分享码");

    //过滤9位且全是数字
    int code = txt.toInt();
    if(txt.length()!=9 || code <100000000 ||code >=1000000000){
        QMessageBox::about(this,"提示","分享码非法");
        return;
    }
    //发送信号 什么目录下面 添加什么分享文件
    Q_EMIT SIG_getShareByLink(code,ui->lb_path->text());
}

void MainDialog::slot_updateUploadFileProgress(int timestamp, int pos)
{
    //遍历所有项 第0列
    int row = ui->table_upload->rowCount();
    for(int i = 0 ;i<row;i++){
        //取到每一个文件信息的时间戳，看是否一致
        MyTableWidgetItem* item0 =(MyTableWidgetItem*)ui->table_upload->item(i,0);
        if(item0->m_info.timestamp == timestamp){
            //一致 ，更新上传进度条
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
}

void MainDialog::slot_updateDownloadFileProgress(int timestamp, int pos)
{
    //遍历所有项 第0列
    int row = ui->table_download->rowCount();
    for(int i = 0 ;i<row;i++){
        //取到每一个文件信息的时间戳，看是否一致
        MyTableWidgetItem* item0 =(MyTableWidgetItem*)ui->table_download->item(i,0);
        if(item0->m_info.timestamp == timestamp){
            //一致 ，更新上传进度条
            QProgressBar* item4 =(QProgressBar*)ui->table_download->cellWidget(i,4);
            item0->m_info.pos=pos;
            item4->setValue(pos);
            //看是否结束
            if(item4->value() >= item4->maximum()){
                //是 删除这一项 添加到已完成
                slot_deleteDownloadFileByRow(i);
                slot_insertDownloadComplete(item0->m_info);
                return;
            }
        }
    }
}

void MainDialog::slot_deleteUploadFileByRow(int row)
{

}

void MainDialog::slot_deleteDownloadFileByRow(int row)
{

}
//在界面显示网盘中已有的某一个文件信息
void MainDialog::slot_insertFileInfo(FileInfo &info)
{
    //列：文件 大小 时间
    //1、新增一行 获取当前行+1 设置行数
    int rows = ui->table_file->rowCount();
    ui->table_file->setRowCount(rows+1);
    //2、设置这一行的每一列控件 添加对象
    MyTableWidgetItem *item0 = new MyTableWidgetItem;
    item0->slot_setInfo(info);
    ui->table_file->setItem(rows , 0 , item0);

//    QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(info.size));
    QTableWidgetItem *item1 = new QTableWidgetItem(FileInfo::getSize(info.size));
    ui->table_file->setItem(rows , 1 , item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(info.time);
    ui->table_file->setItem(rows , 2, item2);


}

//选中文件表格的某一行
void MainDialog::on_table_file_cellClicked(int row, int column)
{
    //切换 勾选和未勾选状态
    MyTableWidgetItem * item0 =(MyTableWidgetItem*)ui->table_file->item(row,0);
    if(item0->checkState()==Qt::Checked){
        item0->setCheckState(Qt::Unchecked);
    }else{
        item0->setCheckState(Qt::Checked);
    }
}

//表格位置鼠标右键
void MainDialog::on_table_file_customContextMenuRequested(const QPoint &pos)
{
    //鼠标位置弹出菜单
    m_menuFileInfo.exec(QCursor::pos());
}

//双击列表中的文件夹
void MainDialog::on_table_file_cellDoubleClicked(int row, int column)
{
    //首先 拿到双击的那行的文件名字
    MyTableWidgetItem * item0 = (MyTableWidgetItem *)ui->table_file->item(row,0);

    //判断是不是文件夹  TODO 文件可以考虑打开文件
    if(item0->m_info.type != "file"){
        //是文件夹 路径拼接
        QString dir = ui->lb_path->text()+item0->m_info.name +"/";
        //设置路径 lb_path->text
        ui->lb_path->setText(dir);
        //发送信号 更新当前目录 刷新文件列表
        Q_EMIT SIG_changeDir(dir);
    }


}

//点击回退按钮
void MainDialog::on_pb_prev_clicked()
{
    //获取目录
    QString path = ui->lb_path->text();
    //判断 "/"结束
    if(path == "/") return;
    //首先找到 最右边的"/"从他左边 开始再向右找 找"/"
    // /03/ left 取多少个长度
    path = path.left(path.lastIndexOf("/"));   //-> /03

    //新的目录就是 找到的"/" 以及左边的所有字符
    path = path.left(path.lastIndexOf("/")+1);  //  /
    qDebug() << path;
    ui->lb_path->setText(path);
    //跳转路径
    Q_EMIT SIG_changeDir(path);
}

