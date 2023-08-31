
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

};

















#endif // COMMON_H
