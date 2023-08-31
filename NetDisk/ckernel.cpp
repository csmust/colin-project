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
    NetMap(_DEF_PACK_FILE_CONTENT_RS) = &CKernel::slot_dealFileContentRs;



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

//CKernel构造函数
CKernel::CKernel(QObject *parent) : QObject(parent),m_id(0)
{
    //设置协议映射
    setNetPackMap();
    //加载ini配置文件 ip port
    loadIniFile();

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
    int timestamp = QDateTime::currentDateTime().toString("hhmmsszzz").toInt();
    qDebug()<<"timestamp: "<<timestamp;
    info.timestamp = timestamp;
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

        //TODO 获取 根目录下面文件列表

        break;
    }


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

}

//处理服务器发来的传输文件数据块的回复
void CKernel::slot_dealFileContentRs(unsigned int lSendIP, char *buf, int nlen)
{
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
            fclose(info.pFile);
            m_mapTimestampToFileInfo.erase(rs->timestamp);
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
    qDebug()<<"配置文件中--"<<"ip:"<<m_ip<<" port:"<<m_port;

}


