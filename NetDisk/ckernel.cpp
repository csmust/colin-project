#include "ckernel.h"
#include<QDebug>
#include"TcpClientMediator.h"
#include"TcpServerMediator.h"
#include<QMessageBox>

#define NetMap(a) m_netPackMap[a - _DEF_PACK_BASE]
void CKernel::setNetPackMap()
{
    //TODO 记得在构造中使用！！！！！

    memset(m_netPackMap , 0 , sizeof(PFUN)*_DEF_PACK_COUNT);
    //协议映射表m_netPackMap是一个数组：   下标 是 协议头偏移量   值 是 函数指针
    //通过 下标 可以找到 对应处理函数
    //初始化协议数组:
    //m_netPackMap[_DEF_PACK_LOGIN_RS - _DEF_PACK_BASE] = &CKernel::slot_dealLoginRs;
    //宏定义替换简化:
    NetMap(_DEF_PACK_REGISTER_RS)=&CKernel::slot_dealRegisterRs;
    NetMap(_DEF_PACK_LOGIN_RS)=&CKernel::slot_dealLoginRs;
    NetMap(_DEF_PACK_UPLOAD_FILE_RS) = &CKernel::slot_dealUploadFileRs;
    NetMap(_DEF_PACK_FILE_CONTENT_RS) = &CKernel::slot_dealFileContentRs;//上传
    NetMap(_DEF_PACK_GET_FILE_INFO_RS) = &CKernel::slot_dealGetFileInfoRs;
    NetMap(_DEF_PACK_FILE_HEADER_RQ) = &CKernel::slot_dealFileHeaderRq;
    NetMap(_DEF_PACK_FILE_CONTENT_RQ) = &CKernel::slot_dealFileContentRq;//下载
    NetMap(_DEF_PACK_ADD_FOLDER_RS) = &CKernel::slot_dealAddFolderRs;
    NetMap(_DEF_PACK_QUICK_UPLOAD_RS)=&CKernel::slot_dealQuickUploadRs; //快传 /秒传
    NetMap(_DEF_PACK_SHARE_FILE_RS)=&CKernel::slot_dealShareFileRs;
    NetMap(_DEF_PACK_MY_SHARE_RS) = &CKernel::slot_dealMyShareRs;
    NetMap(_DEF_PACK_GET_SHARE_RS) = &CKernel::slot_dealGetShareRs;
    NetMap(_DEF_PACK_FOLDER_HEADER_RQ) = &CKernel::slot_dealFolderHeadRq;
    NetMap(_DEF_PACK_DELETE_FILE_RS)=&CKernel::slot_dealDeleteFileRs;




}

//生成MD5函数，static函数 当前文件可用
#include"md5.h"
#define MD5_KEY "1234"
static std::string getMD5(QString val)
{
    QString str = QString("%1_%2").arg(val).arg(MD5_KEY);
    MD5 md(str.toStdString());
    qDebug()<<str<<" md5: "<<md.toString().c_str();
    return md.toString();
}

#include<QTextCodec>

// QString -> char* gb2312
void Utf8ToGB2312( char* gbbuf , int nlen ,QString& utf8)
{
    //转码的对象
    QTextCodec * gb2312code = QTextCodec::codecForName( "gb2312");
    //QByteArray char 类型数组的封装类 里面有很多关于转码 和 写IO的操作
    QByteArray ba = gb2312code->fromUnicode( utf8 );// Unicode -> 转码对象的字符集

    strcpy_s ( gbbuf , nlen , ba.data() );
}

//获取文件的MD5
static std::string getFileMD5(QString path)
{
    //打开文件， 读取文件内容， 读到MD5类 ，生成MD5
    FILE* pFile = nullptr;
    //fopen 如果有中文 支持ANSI 编码  使用ASCII码
    //path 里面是UTF8 qt默认 编码
    char buf[1000]="";
    Utf8ToGB2312(buf,1000,path);
    pFile = fopen(buf, "rb");
    if(!pFile){
        qDebug()<<"file md5 open fail";
        return string();
    }
    int len = 0;
    MD5 md;
    do{
        //缓冲区 , 一次读多少 ,读多少次 ,文件指针 ，返回值读成功次数
        len = fread (buf , 1 ,1000 , pFile);
        md.update(buf,len);//不断拼接文本，不断更新Md5
    }while(len >0);
    fclose(pFile);
    std::string mdstr = md.toString();
    qDebug()<<"file md5:"<<mdstr.c_str();
    qDebug()<<"file md5:"<<mdstr.c_str();
    return mdstr;
//    //下面方法大部分是对的 但是ui_logindialog.h 会有MD5两次不一致 ，原因未知
//    qDebug()<<"file md5:"<<md.toString().c_str();
//    qDebug()<<"file md5:"<<md.toString().c_str();
//    return md.toString();
}

//通过中介者发送数据
void CKernel::SendData(char *buf, int len)
{
    m_tcpClient->SendData(0,buf,len);
}

//系统路径组成  exe同级  ./NetDisk
#include<QDir>
#include<QCoreApplication>
void CKernel::setSystemPath()
{
    QString path = QCoreApplication::applicationDirPath()+"/NetDisk";
    QDir dir;
    //没有文件夹 就创建
    if(!dir.exists(path)){
        dir.mkdir(path); //只能创建一层
        qDebug()<<"创建路径: "<<path;
    }
    //TODO 目前使用默认路径
    m_sysPath = path;
}

//CKernel构造函数
CKernel::CKernel(QObject *parent) : QObject(parent),m_id(0),m_curDir("/")
{

    //设置协议映射
    setNetPackMap();
    //加载ini配置文件 ip port
    loadIniFile();
    //设置系统路径
    setSystemPath();

#ifdef USE_SERVER
    m_tcpServer = new TcpServerMediator;
    connect(m_tcpServer, SIGNAL(SIG_ReadyData(uint,char*,int)),
            this,SLOT(slot_dealServerData(uint,char*,int)));
    m_tcpServer->OpenNet();
#endif

    m_tcpClient = new TcpClientMediator;   //注意回收

    connect(m_tcpClient, SIGNAL(SIG_ReadyData(uint,char*,int)),
            this,SLOT(slot_dealClientData(uint,char*,int)));
    //测试：客户端链接真实地址或者127.0.0.1
    //m_tcpClient->OpenNet("192.168.19.132");
    //使用配置文件中的ip和port:
    m_tcpClient->OpenNet(m_ip.toStdString().c_str(),m_port.toInt());


    m_loginDialog = new LoginDialog;
    connect(m_loginDialog,SIGNAL(SIG_registerCommit(QString,QString,QString)),
            this,SLOT(slot_registerCommit(QString,QString,QString)));
    connect(m_loginDialog,SIGNAL(SIG_loginCommit(QString,QString)),
            this,SLOT(slot_loginCommit(QString,QString)));
    m_loginDialog->show();
    m_mainDialog = new MainDialog;  //创建窗口，堆区，什么时候回收窗口？
    //点× 弹出窗口，点击确认发送信号给kernel类，kernel类回收主窗口对象m_mainDialog
    //点击 叉叉x   --》执行关闭事件  -》 弹窗询问  --=》发送关闭信号    核心类接收 然后回收资源
    connect(m_mainDialog,SIGNAL(SIG_close()),  //m_mainDialog表示谁发信号，this位置表示谁去处理槽
            this,SLOT(slot_destory()));  //链接关闭槽和信号，传出信号后，连接到对应的槽函数，并执行槽函数
    //m_mainDialog->show();

    connect(m_mainDialog,SIGNAL(SIG_uploadFile(QString,QString)),
            this,SLOT(slot_uploadFile(QString,QString)));
    connect(this,SIGNAL(SIG_updateUploadFileProgress(int,int)),
            m_mainDialog,SLOT(slot_updateUploadFileProgress(int,int)) );

    connect(m_mainDialog,SIGNAL(SIG_downloadFile(int,QString)),
            this,SLOT(slot_downloadFile(int,QString)));

    connect(m_mainDialog,SIGNAL(SIG_downloadFolder(int,QString)),
            this,SLOT(slot_downloadFolder(int,QString)));

    connect(this , SIGNAL(SIG_updateDownloadFileProgress(int,int)),
            m_mainDialog,SLOT(slot_updateDownloadFileProgress(int,int)));

    connect(m_mainDialog, SIGNAL(SIG_addFolder(QString,QString)),
            this , SLOT(slot_addFolder(QString,QString)));

    connect(m_mainDialog,SIGNAL(SIG_changeDir(QString)),
            this,SLOT(slot_changeDir(QString )));

    connect(m_mainDialog,SIGNAL(SIG_uploadFolder(QString,QString)),
            this,SLOT(slot_uploadFolder(QString,QString)));

    connect(m_mainDialog ,SIGNAL(SIG_shareFile(QVector<int>,QString)),
            this , SLOT(slot_shareFile(QVector<int>,QString)));

    connect(m_mainDialog,SIGNAL(SIG_getShareByLink(int,QString)),
            this,SLOT(slot_getShareByLink(int,QString)));
    connect(m_mainDialog,SIGNAL(SIG_deleteFile(QVector<int>,QString)),
            this,SLOT(slot_deleteFile(QVector<int>,QString)));

#ifdef USE_SERVER
    //测试 对服务器发送数据
    char strBuf[100] = "hello server";   //sizeof+数组名  是整个是数组的大小 100
    int len =strlen("hello server")+1;
    m_tcpClient ->SendData(0,strBuf,len);    //客户端一定是发给服务器的，套接字参数随意
#endif

    //测试 登录请求
//    STRU_LOGIN_RQ rq;
//    m_tcpClient->SendData(0,(char*)&rq,sizeof(rq));
}


//用于回收资源
void CKernel::slot_destory()
{
    qDebug()<<__func__<<"回收了主窗口对象";
    m_tcpClient->CloseNet();
    delete m_tcpClient;
    delete m_mainDialog;  //回收主窗口对象
    delete m_loginDialog; //回收登录窗口对象
}

void CKernel::slot_registerCommit(QString tel, QString password, QString name)
{
    STRU_REGISTER_RQ rq;
    strcpy(rq.tel , tel.toStdString().c_str());

    //strcpy(rq.password,password.toStdString().c_str());
    //改为md5加密
    strcpy(rq.password , getMD5(password).c_str());
    //兼容中文
    std::string strName = name.toStdString();

    strcpy(rq.name , strName.c_str());

    SendData((char*)&rq,sizeof(rq));
}

void CKernel::slot_loginCommit(QString tel, QString password)
{
    STRU_LOGIN_RQ rq;
    strcpy(rq.tel , tel.toStdString().c_str());

    //strcpy(rq.password,password.toStdString().c_str());
    //登录也使用md5加密后发给服务器
    strcpy(rq.password , getMD5(password).c_str());

    SendData((char*)&rq,sizeof(rq));
    return;
}
//核心类上传文件的槽函数
#include<QFileInfo>
#include<QDateTime>
//dir 是网盘路径  path是本地文件路径
void CKernel::slot_uploadFile(QString path, QString dir)
{
    //QT获取文件属性
    QFileInfo qFileInfo(path);

    //文件信息的存储
    FileInfo info;//直接是对象，没用指针，内存栈
    info.absolutePath = path;
    info.dir = dir;
    string fstring =  getFileMD5(path);
    info.md5 = QString::fromStdString(fstring);

    info.name = qFileInfo.fileName();
    info.size = qFileInfo.size();
    info.time = QDateTime::currentDateTime().toString("yyyy-MM--dd hh:mm:ss");
    info.type = "file";

    char buf[1000] = "";
    Utf8ToGB2312(buf, 1000 , path);
    info.pFile = fopen(buf,"rb");
    if(!info.pFile){
        qDebug()<<"file open fail";
        return;
    }
    //获取时间戳
    int timestamp = QDateTime::currentDateTime().toString("hhmmsszzz").toInt();

    //BUG修复 反复检测时间戳是否已经检测 避免冲突
    while(m_mapTimestampToFileInfo.count(timestamp) > 0){
        //确保上传文件夹时候 所有文件的时间戳都是唯一
        timestamp++;
    }


    info.timestamp = timestamp;
    qDebug()<<"timestamp: "<<timestamp;
    //拷贝构造，存储到map里面 key 时间戳 value 文件信息
    m_mapTimestampToFileInfo[timestamp] = info;

    //发上传文件请求
    STRU_UPLOAD_FILE_RQ rq;
    //为了兼容中文 倒一手
    std::string strDir = dir.toStdString();
    strcpy(rq.dir,strDir.c_str());
    //为了兼容中文 倒一手
    std::string strName = info.name.toStdString();
    strcpy(rq.fileName,strName.c_str());


    strcpy(rq.fileType,"file");

    strcpy(rq.md5 , info.md5.toStdString().c_str());
    qDebug()<<"info.md5: "<<info.md5;
    qDebug()<<"info.md5tochar:"<<info.md5.toStdString().c_str();
    qDebug()<<"rq.md5: "<<rq.md5;
    rq.size=info.size;

    strcpy(rq.time,info.time.toStdString().c_str());

    rq.timestamp=timestamp;

    rq.userid = m_id;

    SendData((char*)&rq , sizeof(rq));
    return;
}

//上传什么路径的文件夹 到什么目录下面
void CKernel::slot_uploadFolder(QString path, QString dir)
{
    qDebug()<<"CKernel::"<<__func__;
    QFileInfo info(path);
    QDir dr(path);
    //当前文件夹的处理 addFolder c:/项目 下面 是有/0314 /   /0527/   1.txt 上传到/05/
    qDebug() << "folder:" <<info.fileName()<<"dir:"<<dir;
    slot_addFolder(info.fileName(),dir);
    //获取文件夹下面一层所有文件的路径（文件信息）
    QFileInfoList lst = dr.entryInfoList(); //获取路径下所有文件的文件信息列表
    //遍历所有文件
    QString newDir = dir+info.fileName()+"/";
    for(int i =0; i<lst.size();++i){
        QFileInfo file = lst.at(i);
        //如果是 . 继续
        if(file.fileName()==".") continue;
        //如果是 .. 继续
        if(file.fileName()=="..") continue;
        //如果是文件 uploadFile ->路径 文件信息的绝对路径 传到什么目录  /05/项目
        if(file.isFile()){
            qDebug() << "file:"<<file.absoluteFilePath()<<"dir:"<<newDir;
            slot_uploadFile(file.absoluteFilePath(),newDir); //1.txt ->/05/项目
        }
        //如果是文件夹 slot_uploadFolder 递归
        if(file.isDir()){
            slot_uploadFolder(file.absoluteFilePath(),newDir);
        }
    }
    return;
}

//获取当前路径的文件信息列表,配合删除列表，可以实现更新
void CKernel::slot_getCurDirFileList()
{
    //向服务器发送获取当前目录m_curDir文件列表
    STRU_GET_FILE_INFO_RQ rq;
    rq.userID = m_id;
    //兼容中文
    std::string strDir = m_curDir.toStdString();
    strcpy(rq.dir , strDir.c_str());
    SendData((char*)&rq,sizeof(rq));
    return;
}

//获取文件列表，处理服务器发来的获取文件列表回复
void CKernel::slot_dealGetFileInfoRs(unsigned int lSendIP, char *buf, int nlen)
{
    //拆包
    STRU_GET_FILE_INFO_RS *rs = (STRU_GET_FILE_INFO_RS *) buf;

    if(m_curDir != QString::fromStdString(rs->dir)){
        return;
    }
    //先删除再添加，实现更新
    m_mainDialog->slot_deleteAllFileInfo();   //槽函数执行是排队的，解决并发同时删和增问题
    //获取元素
    int count = rs->count;
    //循环插入文件信息到界面
    for(int i = 0;i<count;i++){
        FileInfo info;
        info.fileid=rs->fileInfo[i].fileID;
        info.type = QString::fromStdString(rs->fileInfo[i].fileType);
        info.name = QString::fromStdString(rs->fileInfo[i].name);
        info.size = rs->fileInfo[i].size;
        info.time = rs->fileInfo[i].time;

        //插入到控件
        m_mainDialog->slot_insertFileInfo(info);
    }
    return;
}

void CKernel::slot_downloadFile(int fileid, QString dir)
{
    qDebug()<<"CKernel::"<<__func__;
    //写请求
    STRU_DOWNLOAD_FILE_RQ rq;
    //兼容中文
    std::string strDir = dir.toStdString();
    strcpy(rq.dir,strDir.c_str());
    rq.fileid   = fileid;
    //生成时间戳
    int timestamp = QDateTime::currentDateTime().toString("hhmmsszzz").toInt();
    //BUG修复
    while(m_mapTimestampToFileInfo.count(timestamp) > 0){
        //确保上传文件夹时候 所有文件的时间戳都是唯一 有时候可能速度太快
        timestamp++;
    }
    rq.timestamp=timestamp;
    rq.userid = m_id;
    SendData((char*)&rq,sizeof(rq));
    return;
}
//下载文件夹
void CKernel::slot_downloadFolder(int fileid, QString dir)
{
    qDebug()<<"CKernel::"<<__func__;
    STRU_DOWNLOAD_FOLDER_RQ rq;
    string strDir = dir.toStdString();
    strcpy(rq.dir , strDir.c_str());
    rq.fileid = fileid;
    int timestamp = QDateTime::currentDateTime().toString("hhmmsszzz").toInt();
    while(m_mapTimestampToFileInfo.count(timestamp) > 0){
        timestamp++;
    }
    rq.timestamp = timestamp;
    rq.userid = m_id;
    SendData((char*)&rq,sizeof(rq));
    return;
}


//新建文件夹，什么路径下创建什么名字的文件夹
void CKernel::slot_addFolder(QString name, QString dir)
{
    //发送请求包
    STRU_ADD_FOLDER_RQ rq;
    string strDir = dir.toStdString();
    strcpy(rq.dir, strDir.c_str());

    string strName = name.toStdString();
    strcpy(rq.fileName ,strName.c_str());

    string strTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString();
    strcpy(rq.time,strTime.c_str());

    rq.timestamp =QDateTime::currentDateTime().toString("hhmmsszzz").toInt();
    rq.userid = m_id;
    SendData((char*)&rq,sizeof(rq));
    return;
}

void CKernel::slot_changeDir(QString dir)
{
    //更新当前的目录
    m_curDir = dir;
    //刷新列表
    m_mainDialog->slot_deleteAllFileInfo();
    slot_getCurDirFileList();  //再获取当前文件夹文件信息列表
    return;
}
//分享  什么目录下面的文件列表
void CKernel::slot_shareFile(QVector<int> fileidArray, QString dir)
{
    qDebug()<<"CKernel::"<<__func__;
    //打包
    int packlen = sizeof(STRU_SHARE_FILE_RQ)+sizeof(int)*fileidArray.size();
    STRU_SHARE_FILE_RQ *rq=(STRU_SHARE_FILE_RQ *)malloc(packlen);
    rq->init();
    rq->itemCount=fileidArray.size();
    for(int i = 0;i<fileidArray.size(); i++){
        rq->fileidArray[i] = fileidArray[i];
    }
    rq->userid = m_id;
    std::string strDir = dir.toStdString();
    strcpy(rq->dir,strDir.c_str());
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    strcpy(rq->shareTime,time.toStdString().c_str());
    SendData((char*)rq,packlen);
    qDebug()<<"CKernel::"<<__func__<<"share packlen = "<<packlen;
    free(rq);
    return;
}

//客户端处理收到数据
void CKernel::slot_dealClientData(unsigned int lSendIP, char *buf, int nlen)
{

    //测试
//    QString str =QString("来自服务器:%1").arg(QString::fromStdString(buf));
//    QMessageBox::about(NULL , "提示" ,str);   //about 阻塞的  模态窗口  不能点击其他部分，得先处理这个弹窗
    int type = *(int*)buf;
    qDebug()<<__func__;

    //switch(type)  //如果过多的处理函数，会很麻烦

    //通过协议头 拿到处理函数  并执行。
    if(type >= _DEF_PACK_BASE && type < _DEF_PACK_BASE + _DEF_PACK_COUNT){
        PFUN pf = NetMap(type);
        if( pf ) {
            (this->*pf)(lSendIP , buf , nlen);
        }
    }







    //回收空间
    delete[] buf;
    return;
}

//处理服务端发来的登录回复
void CKernel::slot_dealLoginRs(unsigned int lSendIP, char *buf, int nlen)
{
    qDebug()<<__func__;
    //拆包
    STRU_LOGIN_RS * rs = (STRU_LOGIN_RS*)buf;
    //根据不同的结果，有不同的提示
    switch(rs->result){
    case tel_not_exist:
        QMessageBox::about(m_loginDialog,"提示","手机号不存在，登录失败");
        break;
    case password_error:
        QMessageBox::about(m_loginDialog,"提示","密码错误，登录失败");
        break;
    case login_success:
        //前台
        m_loginDialog->hide();
        m_mainDialog->show();
        //后台
        m_name = rs->name;
        m_id = rs->userid;

        // 获取 根目录下面文件列表
        m_curDir = "/";
        slot_getCurDirFileList();

        //获取 分享列表
        slot_getMyShare();
        break;
    }

    return;
}

void CKernel::slot_dealRegisterRs(unsigned int lSendIP, char *buf, int nlen)
{
    //拆包
    STRU_REGISTER_RS* rs=(STRU_REGISTER_RS*) buf;
    //根据不同的结果，有不同的提示
    switch(rs ->result){
    case tel_is_exist:
        QMessageBox::about(m_loginDialog,"提示","手机号已存在，注册失败");
        break;
    case name_is_exist:
        QMessageBox::about(m_loginDialog,"提示","用户名已存在，注册失败");
        break;
    case register_success:
        QMessageBox::about(m_loginDialog,"提示","注册成功");
        break;
    }
    return;
}

//处理服务器发来的上传文件回复
void CKernel::slot_dealUploadFileRs(unsigned int lSendIP, char *buf, int nlen)
{
    //拆包
    STRU_UPLOAD_FILE_RS* rs = (STRU_UPLOAD_FILE_RS*)buf;
//    rs->fileid
//        rs->result
//            rs->timestamp
    //首先看结果是否为真：
    if(!rs->result){
        qDebug()<<"上传失败";
            return ;
    }
    //为真
    //从map里获取文件信息
    if(m_mapTimestampToFileInfo.count(rs->timestamp) == 0){
        qDebug() << "not found in map";
        return ;
    }
    FileInfo& info = m_mapTimestampToFileInfo[rs->timestamp];//用引用的方式操作文件信息对象
    //更新fileid
    info.fileid = rs ->fileid;
    //TODO 插入上传信息到上传中控件里
    m_mainDialog->slot_insertUploadFile(info);


    //发送文件块（内容）请求
    STRU_FILE_CONTENT_RQ rq;

    rq.fileid = rs->fileid;
    rq.timestamp = rs->timestamp;
    rq.userid =m_id;
    rq.len = fread(rq.content , 1 , _DEF_BUFFER , info.pFile);
    SendData((char*)&rq,sizeof(rq));
    //qDebug()<<"处理服务器发来的上传文件回复";
    return;
}

//处理服务器发来的传输文件数据块的回复
void CKernel::slot_dealFileContentRs(unsigned int lSendIP, char *buf, int nlen)
{
    qDebug()<<__func__;;
    //拆包
    STRU_FILE_CONTENT_RS * rs = (STRU_FILE_CONTENT_RS *) buf;
    //找到文件信息结构体
    if(m_mapTimestampToFileInfo.count(rs->timestamp) == 0){
        qDebug()<<"map not found";
        return ;
    }
    FileInfo& info = m_mapTimestampToFileInfo[rs->timestamp];

    //查看服务器存储文件块结果
    if(!rs->result) fseek(info.pFile , -1*(rs->len) , SEEK_CUR);
    else{
        info.pos += rs->len;
        //TODO 更新APP界面上传进度
        //方案1：写信号槽 考虑多线程
        //方案2：直接调用 一定是当前函数在主线程才行

        Q_EMIT SIG_updateUploadFileProgress(info.timestamp,info.pos);



        //判断是否结束
        if(info.pos >= info.size){
                        qDebug()<<"slot_dealFileContentRs已经结束";
            fclose(info.pFile);
            m_mapTimestampToFileInfo.erase(rs->timestamp);
            //刷新列表
            m_mainDialog->slot_deleteAllFileInfo();  //先删除
            slot_getCurDirFileList();   //再获取

            return ;
        }
    }
    //继续发送文件块
    STRU_FILE_CONTENT_RQ rq;
    rq.fileid = rs->fileid;
    rq.timestamp = rs->timestamp;
    rq.userid = m_id;
    rq.len = fread(rq.content , 1 ,_DEF_BUFFER , info.pFile);
    SendData((char*)&rq , sizeof(rq));
            //qDebug()<<"处理服务器发来的传输文件数据块的回复";
    return;
}



void CKernel::slot_dealFileHeaderRq(unsigned int lSendIP, char *buf, int nlen)
{
    //拆包
    STRU_FILE_HEADER_RQ * rq = (STRU_FILE_HEADER_RQ *)buf;
    //创建文件信息结构体 赋值
    FileInfo info;
    //默认路径 sysPath(不包含最后的'/') + dir + name
    //TODO dir 可能有很多层，需要循环创建目录  ，比如下载网盘比较深的文件，需要在本地循环创建文件夹
    QString tmpDir = QString::fromStdString(rq->dir); //NetDisk/111/222 下的 1.txt
    QStringList dirList = tmpDir.split("/");   //分割函数  NetDisk 111 222

    QString pathsum = m_sysPath;
    for(QString & node : dirList)
    {
        if(!node.isEmpty()){
            pathsum +="/";
            pathsum += node;
            QDir dir;
            if(!dir.exists(pathsum)){
                dir.mkdir(pathsum);
            }
        }
    }

    info.name = QString::fromStdString(rq->fileName);
    info.dir = QString::fromStdString(rq->dir);
    qDebug()<<"info.dir : "<<info.dir;
    info.absolutePath=QString ("%1%2%3").arg(m_sysPath).arg(info.dir).arg(info.name); //TODO 目前使用默认路径保存下载
    info.fileid = rq->fileid;
    info.md5 = QString::fromStdString(rq->md5);

    info.size=rq->size;
    info.time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    info.timestamp = rq->timestamp;
    info.type = "file";
    //打开文件 tips  fopen 是ASCII的编码 需要转换
    char pathbuf[1000]="";
    Utf8ToGB2312(pathbuf , 1000 , info.absolutePath);
    qDebug()<<pathbuf;
    info.pFile = fopen(pathbuf,"wb");
    if(!info.pFile){
        qDebug()<<"file open fail";
        return;
    }

    //保存下载信息到控件界面
    m_mainDialog->slot_insertDownloadFile(info);
    //保存map里面
    m_mapTimestampToFileInfo[rq->timestamp] = info;
    //写回复
    STRU_FILE_HEADER_RS rs;
    rs.fileid=rq->fileid;
    rs.result=1;
    rs.timestamp = rq->timestamp;
    rs.userid = m_id;

    SendData((char*)&rs , sizeof(rs));
    return;
}

void CKernel::slot_dealFileContentRq(unsigned int lSendIP, char *buf, int nlen)
{
    //拆包
    STRU_FILE_CONTENT_RQ * rq = (STRU_FILE_CONTENT_RQ *) buf;

    //拿到文件信息结构
    if(m_mapTimestampToFileInfo.count(rq->timestamp) == 0 ) return;
    FileInfo & info = m_mapTimestampToFileInfo[rq->timestamp];
    STRU_FILE_CONTENT_RS rs;
    //写文件          文件内容 每次写多少个字节  预计写多少次  文件描述符
    int len = fwrite(rq->content, 1,rq->len ,info.pFile);
    if(len !=rq->len){
        //不成功 调回去
        rs.result = 0;
        fseek(info.pFile , -1*len , SEEK_CUR);
    }else{
        //成功 pos+=len
        rs.result = 1;
        info.pos += len;

        //TODO更新界面显示进度
        Q_EMIT SIG_updateDownloadFileProgress(rq->timestamp,info.pos);

        //要看 有没有到末尾 是否结束
        if(info.pos >= info.size){
            //结束 关闭文件 回收
            fclose(info.pFile);
            m_mapTimestampToFileInfo.erase(rq->timestamp);
        }
    }


    //写回复
    rs.fileid = rq->fileid;
    rs.len = rq->len;
    rs.timestamp = rq->timestamp;
    rs.userid = m_id;
    //发送
    SendData((char*)&rs , sizeof(rs));
    return;
}

void CKernel::slot_dealAddFolderRs(unsigned int lSendIP, char *buf, int nlen)
{
    //拆包
    STRU_ADD_FOLDER_RS *rs = (STRU_ADD_FOLDER_RS *)buf;
    //判断是否成功
    if(rs->result !=1 ) return;
    //删除界面中原来的列表
    //m_mainDialog->slot_deleteAllFileInfo(); //先删除 这种方式上传文件夹会出现并发问题 增删同时发生
    //更新文件列表
    slot_getCurDirFileList();
    return;
}
//快传 秒传
void CKernel::slot_dealQuickUploadRs(unsigned int lSendIP, char *buf, int nlen)
{
    //拆包
    STRU_QUICK_UPLOAD_RS *rs = (STRU_QUICK_UPLOAD_RS*)buf;
    //获取文件信息
    if(m_mapTimestampToFileInfo.count(rs->timestamp) == 0) return;
    FileInfo &info = m_mapTimestampToFileInfo[rs->timestamp];
    //关闭文件句柄
    if(info.pFile)
        fclose(info.pFile);
    //写入上传已完成信息
    m_mainDialog->slot_insertUploadComplete(info);
    //发送刷新文件列表
    if(m_curDir == info.dir)
    {
        m_mainDialog->slot_deleteAllFileInfo();
        slot_getCurDirFileList();
    }
    //删除节点
    m_mapTimestampToFileInfo.erase(rs->timestamp);
    return;
}

//处理服务器发来的分享文件回复
void CKernel::slot_dealShareFileRs(unsigned int lSendIP, char *buf, int nlen)
{
    //拆包
    STRU_SHARE_FILE_RS *rs= (STRU_SHARE_FILE_RS *)buf;
    //判断是否成功
    if(rs->result!=1) return;
    //刷新 发获取请求
    slot_getMyShare();
    return;
}


void CKernel::slot_getMyShare(){
    STRU_MY_SHARE_RQ rq;
    rq.userid = m_id;
    SendData((char*)&rq , sizeof(rq));
    return;
}


void CKernel::slot_dealMyShareRs(unsigned int lSendIP, char *buf, int nlen)
{
    //拆包
    STRU_MY_SHARE_RS * rs = (STRU_MY_SHARE_RS *)buf;
    int count = rs->itemCount;
    //清空界面所有分享内容
    m_mainDialog->slot_deleteAllShareInfo();
    //遍历 分享文件的信息  添加到控件上面
    for(int i = 0; i<count ;i++){
        m_mainDialog->slot_insertShareFileInfo(rs->items[i].name , rs->items[i].size ,rs->items[i].time,rs->items[i].shareLink);
    }
    return;
}

//获取什么分享码的文件 添加到什么目录
void CKernel::slot_getShareByLink(int code, QString dir)
{
    //发请求
    STRU_GET_SHARE_RQ rq;
    string tmpDir = dir.toStdString();
    strcpy(rq.dir,tmpDir.c_str());
    rq.shareLink =code;
    //客户端请求分享的时间作为上传时间
    string time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString();
    strcpy(rq.time ,time.c_str());
    rq.userid = m_id;
    SendData((char*)&rq , sizeof(rq));
    return;
}

//处理服务器发来的获取分享码的分享回复
void CKernel::slot_dealGetShareRs(unsigned int lSendIP, char *buf, int nlen)
{
    //拆包
    STRU_GET_SHARE_RS *rs =(STRU_GET_SHARE_RS *)buf;
    //根据结果
    if(rs->result==0){
        QMessageBox::about(m_mainDialog,"提示","获取分享失败");
        //错误返回提示
    }else{
        //正确刷新界面列表 ，
        if(QString::fromStdString(rs->dir) == m_curDir){
            slot_getCurDirFileList();
        }
    }
    return;
}

void CKernel::slot_dealFolderHeadRq(unsigned int lSendIP, char *buf, int nlen)
{
    //拆包
    STRU_FOLDER_HEADER_RQ *rq=(STRU_FOLDER_HEADER_RQ*)buf;
    //创建目录
    // dir 是文件夹名字的路径，可能有很多层本地没有的目录，需要循环创建
    QString tmpDir = QString::fromStdString(rq->dir); // NetDisk/02/
    QStringList dirList = tmpDir.split("/");   //分割函数分割 NetDisk/02/
    QString pathsum = m_sysPath;
    for(QString &node : dirList)
    {
        if(!node.isEmpty()){
            pathsum+="/";
            pathsum+=node;
            QDir dir;
            if(!dir.exists(pathsum)){
                dir.mkdir(pathsum);
            }
        }
    }
    //为文件夹名字后面加上"/"
    pathsum+="/";
    pathsum+=QString::fromStdString(rq->fileName);
    QDir dir;
    if(!dir.exists(pathsum)){
        dir.mkdir(pathsum);
    }
    return;
}

//删除什么目录下的一系列文件
void CKernel::slot_deleteFile(QVector<int> fileidArray, QString dir)
{
    //发请求
    int packlen = sizeof(STRU_DELETE_FILE_RQ)+fileidArray.size()*sizeof(int);

    STRU_DELETE_FILE_RQ *rq = (STRU_DELETE_FILE_RQ * )malloc(packlen);
    rq->init();
    string strDir = dir.toStdString();
    strcpy(rq->dir , strDir.c_str());
    rq->fileCount = fileidArray.size();

    rq->userid=m_id;
    for(int i = 0;i<rq->fileCount;i++){
        rq->fileidArray[i]=fileidArray[i];
    }
    SendData((char*)rq,packlen);
    free(rq);
    return;
}

void CKernel::slot_dealDeleteFileRs(unsigned int lSendIP, char *buf, int nlen)
{
    //拆包
    STRU_DELETE_FILE_RS * rs=(STRU_DELETE_FILE_RS * )buf;
    //看是否成功，成功则刷新界面列表
    if(rs->result ==1){
        if(QString::fromStdString(rs->dir)==m_curDir){
            m_mainDialog->slot_deleteAllFileInfo();
            slot_getCurDirFileList();
        }
    }
    return;

}



#ifdef USE_SERVER
void CKernel::slot_dealServerData(unsigned int lSendIP, char *buf, int nlen)
{
    QString str =QString("来自服务器:%1").arg(QString::fromStdString(buf));
    QMessageBox::about(NULL , "提示" ,str);   //about 阻塞的  模态窗口  不能点击其他部分，得先处理这个弹窗

    m_tcpServer->SendData(lSendIP,buf,nlen);
    //回收空间
    delete[] buf;
}
#endif


#include<QFileInfo>
#include<QCoreApplication>
#include<QSettings>  //配置文件使用的类
void CKernel::loadIniFile()
{
    //默认值
    m_ip="192.168.5.198";
    m_port="8004";

    //获取编译出的应用exe目录，并拼：
    QString path=QCoreApplication::applicationDirPath() + "/config.ini";
    //根据目录
    //看文件是否存在 存在加载 不存在创建并且写入默认值
    //使用QFileInfo 来看文件是否存在
    QFileInfo info(path);
    if(info.exists()){
        //存在

        QSettings setting (path,QSettings::IniFormat);   //没有path会创建
        //打开组
        setting.beginGroup("net");
        //读取value
        QVariant strIP=setting.value("ip","");
        QVariant strPort=setting.value("port","");
        if(! strIP.toString().isEmpty())
            m_ip=strIP.toString();
        if(! strPort.toString().isEmpty())
            m_port=strPort.toString();

        //关闭组

        setting.endGroup();
    }else{
        //不存在

        QSettings setting (path,QSettings::IniFormat);   //没有会创建
        //打开组
        setting.beginGroup("net");
        //设置 key value
        setting.setValue("ip",m_ip);
        setting.setValue("port",m_port);
        //关闭组
        setting.endGroup();

    }
    qDebug()<<"--"<<"ip:"<<m_ip<<" port:"<<m_port;
    return;
}


