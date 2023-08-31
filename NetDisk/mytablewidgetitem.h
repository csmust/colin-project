
#ifndef MYTABLEWIDGETITEM_H
#define MYTABLEWIDGETITEM_H

#include <QTableWidgetItem>
#include"common.h"

class MainDialog;
class MyTableWidgetItem : public QTableWidgetItem
{
   // Q_OBJECT  不需要信号和槽 且影响暴力强转
public:
    MyTableWidgetItem();
public slots:
    void slot_setInfo(FileInfo & info);
private:
    FileInfo m_info;
    friend class MainDialog; //友元核心类。可以使用自己的私有成员
};

#endif // MYTABLEWIDGETITEM_H
