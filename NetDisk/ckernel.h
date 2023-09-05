#ifndef CKERNEL_H
#define CKERNEL_H
#include "maindialog.h"   //窗口类
#include <QObject>
#include "INetMediator.h"   //也可以class INetMediator;
#include "packdef.h"
#include "logindialog.h"
#include "common.h"
//核心处理类
//单例
//1.构造 拷贝构造 析构 私有化

//协议映射表

//类成员函数指针类型
class CKernel;
typedef void (CKernel::*PFUN)(unsigned int lSendIP,char *buf,int nlen);



//2.提供静态的公有的获取对象的方法。接口

//#define USE_SERVER 1   //与#ifdef  #endif联动     是否注释掉  决定是否使用windows的服务端测试

class CKernel : public QObject
{
    Q_OBJECT
private:
    explicit CKernel(QObject *parent = nullptr);   //explicit关键字一般用来修饰类的构造函数，作用是告诉编译器按照实际的类型来构造函数，不允许做隐式转换
    explicit CKernel(const CKernel &kernel){}   //拷贝构造
    ~CKernel(){}

    void setNetPackMap();
    void SendData(char * buf ,int len);
    void setSystemPath(); //设置系统默认下载路径
    void loadIniFile();  //读取配置文件
    /*----------------配置文件-------------------*/
    //区别于宏，程序就不用再编译了，exe同级目录  根据目录看文件是否存在，存在加载，不存在创建并且写入默认值
    // .ini
    //QT支持格式
    //[组名]
    //key=value

    //例如
    //[net]
    //ip=192.168.5.198
    //port=8004

signals:
    void SIG_updateUploadFileProgress(int timestamp, int pos); //更新上传进度条
    void SIG_updateDownloadFileProgress(int timestamp, int pos); //更新下载进度条


public:
    static CKernel* GetInstance(){
        //全局区简单、（也可以在堆区）线程安全的
        static CKernel kernel;
        return &kernel;
    }


private slots:

    //普通槽函数
    //回收窗口
    void slot_destory();
    void slot_registerCommit(QString tel , QString password, QString name);
    void slot_loginCommit(QString tel , QString password);
    //什么绝对路径的文件，上传到什么目录下
    void slot_uploadFile(QString path , QString dir);
    //上传什么路径的文件夹 到什么目录下面
    void slot_uploadFolder(QString path , QString dir);
    //向服务器发送获取当前路径的文件信息列表的请求
    void slot_getCurDirFileList();
    //什么文件id，什么目录下的文件  下载
    void slot_downloadFile(int fileid,QString dir);
    //什么文件id，什么目录下的文件夹 下载
    void slot_downloadFolder(int fileid,QString dir);
    //什么路径下创建什么名字的文件夹
    void slot_addFolder(QString name,QString dir);
    //改变路径
    void slot_changeDir(QString dir);
    //分享  什么目录下面的文件列表
    void slot_shareFile(QVector<int> fileidArray, QString dir);
    //请求获取自己的分享
    void slot_getMyShare();
    //获取什么分享码的文件 添加到什么目录
    void slot_getShareByLink(int code ,QString dir);


    //网络响应槽函数
    void slot_dealClientData(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的登录回复
    void slot_dealLoginRs(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的注册回复
    void slot_dealRegisterRs(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的上传文件回复
    void slot_dealUploadFileRs(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的传输文件数据块的回复
    void slot_dealFileContentRs(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的获取文件列表回复  ----- 获取到了自己在网盘中的文件id等信息
    void slot_dealGetFileInfoRs(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的文件头请求，客户端准备下载文件，服务器准备向客户端“上传”文件
    void slot_dealFileHeaderRq(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的文件内容，客户端下载文件
    void slot_dealFileContentRq(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的新建文件夹回复
    void slot_dealAddFolderRs(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的快传回复
    void slot_dealQuickUploadRs(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的分享文件回复
    void slot_dealShareFileRs(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的分享获取回复
    void slot_dealMyShareRs(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的获取分享码的分享回复
    void slot_dealGetShareRs(unsigned int lSendIP,char *buf,int nlen);


#ifdef USE_SERVER
    //网络响应槽函数
    void slot_dealServerData(unsigned int lSendIP,char *buf,int nlen);
#endif

private:

    #ifdef USE_SERVER
    INetMediator *m_tcpServer;
    #endif
    MainDialog * m_mainDialog;   //指针 堆区窗口，避免函数结束回收
    LoginDialog* m_loginDialog;


    QString m_ip;  //配置文件ip
    QString m_port;  //配置文件端口号
    //登录成功后保存个人信息：
    QString m_name;  //用户昵称
    int m_id; //用户id
    QString m_curDir;//客户端网盘app实时当前的目录位置,首先是根目录
    QString m_sysPath;//默认存储的系统路径，绝对路径，设置exe同级下

    INetMediator *m_tcpClient;

    //key 时间戳 hhmmsszzz   value 文件信息对象
    std::map<int , FileInfo> m_mapTimestampToFileInfo;

    PFUN m_netPackMap[_DEF_PACK_COUNT];//协议数组,用map有点大材小用，也可以
};

#endif // CKERNEL_H
