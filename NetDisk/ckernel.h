#ifndef CKERNEL_H
#define CKERNEL_H
#include"maindialog.h"   //窗口类
#include <QObject>
#include "INetMediator.h"   //也可以class INetMediator;
#include"packdef.h"
#include"logindialog.h"

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


    //网络响应槽函数
    void slot_dealClientData(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的登录回复
    void slot_dealLoginRs(unsigned int lSendIP,char *buf,int nlen);
    //处理服务器发来的注册回复
    void slot_dealRegisterRs(unsigned int lSendIP,char *buf,int nlen);
#ifdef USE_SERVER
    //网络响应槽函数
    void slot_dealServerData(unsigned int lSendIP,char *buf,int nlen);
#endif
private:
    void setNetPackMap();
    void SendData(char * buf ,int len);
private:
    MainDialog * m_mainDialog;   //指针 堆区窗口，避免函数结束回收
    LoginDialog* m_loginDialog;


    QString m_ip;  //配置文件ip
    QString m_port;  //配置文件端口号

    INetMediator *m_tcpClient;
#ifdef USE_SERVER
    INetMediator *m_tcpServer;
#endif
    PFUN m_netPackMap[_DEF_PACK_COUNT];//协议数组,用map有点大材小用，也可以
};

#endif // CKERNEL_H
