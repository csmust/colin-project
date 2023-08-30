//#include "maindialog.h"
#include <QApplication>
#include"ckernel.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//TODO 窗口让核心类去管理
//    Maindialog w;
//    w.show();
    CKernel::GetInstance();  //获取单例kernel

    return a.exec();
}
