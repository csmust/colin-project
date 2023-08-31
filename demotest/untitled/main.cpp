
#include "dialog.h"
#include<QDebug>
#include <QApplication>

struct STRU_FILE_INFO
{
    int fileID;
    char name[260];
    char time[40];
    int size;
    char type[10];
};

//获取文件信息回复
struct STRU_GET_FILE_INFO_RS
{
    char dir[260];
    int count;
    //文件信息数组
    STRU_FILE_INFO fileInfo[];  //柔性数组
};





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug()<<"STRU_GET_FILE_INFO_RS size:" <<sizeof(STRU_GET_FILE_INFO_RS);

    //元素个数
    int count =3;
    STRU_GET_FILE_INFO_RS *rs =(STRU_GET_FILE_INFO_RS*)malloc(sizeof(STRU_GET_FILE_INFO_RS) + count * sizeof(STRU_FILE_INFO));
    for(int i =0;i<count;++i){
        rs->fileInfo[i].fileID=i;
    }
    free(rs);
    Dialog w;
    w.show();
    return a.exec();
}
