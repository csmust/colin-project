
#ifndef COMMON_H
#define COMMON_H
#include<QString>
////////////////////文件信息/////////////////
struct FileInfo
{

    FileInfo():fileid(0) , size(0),
        pos(0) ,timestamp(0), isPause(0),pFile( nullptr ){

    }

    int fileid;  //网盘中的数据库中文件id
    QString name;
    QString dir;  //网盘目录
    QString time;
    int size;  //int 32位  最大值 2GB    假定单个文件2GB最大
    QString md5;
    QString type;
    QString absolutePath;   //文件本地绝对路径

    int pos; //上传或下载到什么位置
    int timestamp;  //时间戳，文件标识身份
    int isPause; //暂停  0 1

    //文件指针
    FILE* pFile;

    //字节单位换算 得到KB MB
    // 2GB 2 *1024 *1024 *1024
    static QString getSize(int size)
    {
        QString res;
        int count = 0;
        int tmp =size;
        while(tmp!=0){
            tmp /= 1024;
            if(tmp!=0) count++;
        }
        switch(count){
        case 0:
            //0.0x kB
            res = QString("0.%1KB").arg((int)(size%1024/1024.0*100) , 2,10,QChar('0'));
            //arg(参数二 多宽 参数三 进制 参数四 不够宽度 缺省的字符)
            break;
        case 1:
            // KB
            res = QString("%1.%2KB").arg(size/1024).arg((int)(size%1024/1024.0*100),2,10,QChar('0'));
            break;
        case 2:
        case 3:
            //MB
            res = QString("%1.%2MB").arg(size/1024/1024).arg((int)(size/1024%1024/1024.0*100),2,10,QChar('0'));
            break;
        default:
            res = QString("%1.%2MB").arg(size/1024/1024).arg((int)(size/1024%1024/1024.0*100),2,10,QChar('0'));
            break;
        }
        return res;
    }

};

















#endif // COMMON_H
