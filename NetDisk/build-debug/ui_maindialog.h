/********************************************************************************
** Form generated from reading UI file 'maindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *wdg_left;
    QVBoxLayout *verticalLayout;
    QPushButton *pb_file;
    QPushButton *pb_transmit;
    QPushButton *pb_share;
    QPushButton *pb_store;
    QPushButton *pb_hsz;
    QSpacerItem *verticalSpacer;
    QPushButton *pb_name;
    QWidget *wdg_right;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *sw_page;
    QWidget *page_file;
    QVBoxLayout *verticalLayout_3;
    QWidget *wdg_right_top;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_prev;
    QPushButton *pb_next;
    QLabel *lb_path;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_search;
    QPushButton *pb_addFile;
    QWidget *wdg_right_bottom;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *table_file;
    QWidget *page_transmit;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tw_transmit;
    QWidget *tab_upload;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *table_upload;
    QWidget *tab_download;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *table_download;
    QWidget *tab_complete;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *table_complete;
    QWidget *page_share;
    QVBoxLayout *verticalLayout_13;
    QTabWidget *tw_share;
    QWidget *tab_myShare;
    QVBoxLayout *verticalLayout_12;
    QTableWidget *table_share;

    void setupUi(QDialog *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName(QString::fromUtf8("MainDialog"));
        MainDialog->resize(700, 480);
        QFont font;
        font.setPointSize(11);
        MainDialog->setFont(font);
        horizontalLayout = new QHBoxLayout(MainDialog);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_left = new QWidget(MainDialog);
        wdg_left->setObjectName(QString::fromUtf8("wdg_left"));
        wdg_left->setMinimumSize(QSize(200, 0));
        wdg_left->setMaximumSize(QSize(200, 16777215));
        wdg_left->setFont(font);
        wdg_left->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 203, 203);"));
        verticalLayout = new QVBoxLayout(wdg_left);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pb_file = new QPushButton(wdg_left);
        pb_file->setObjectName(QString::fromUtf8("pb_file"));
        pb_file->setMinimumSize(QSize(0, 36));
        pb_file->setMaximumSize(QSize(16777215, 36));
        pb_file->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_file->setIcon(icon);
        pb_file->setIconSize(QSize(36, 36));

        verticalLayout->addWidget(pb_file);

        pb_transmit = new QPushButton(wdg_left);
        pb_transmit->setObjectName(QString::fromUtf8("pb_transmit"));
        pb_transmit->setMinimumSize(QSize(0, 36));
        pb_transmit->setMaximumSize(QSize(16777215, 36));
        pb_transmit->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/transmit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pb_transmit->setIcon(icon1);
        pb_transmit->setIconSize(QSize(36, 36));

        verticalLayout->addWidget(pb_transmit);

        pb_share = new QPushButton(wdg_left);
        pb_share->setObjectName(QString::fromUtf8("pb_share"));
        pb_share->setMinimumSize(QSize(0, 36));
        pb_share->setMaximumSize(QSize(16777215, 36));
        pb_share->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/share.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_share->setIcon(icon2);
        pb_share->setIconSize(QSize(36, 36));

        verticalLayout->addWidget(pb_share);

        pb_store = new QPushButton(wdg_left);
        pb_store->setObjectName(QString::fromUtf8("pb_store"));
        pb_store->setMinimumSize(QSize(0, 36));
        pb_store->setMaximumSize(QSize(16777215, 36));
        pb_store->setFont(font);

        verticalLayout->addWidget(pb_store);

        pb_hsz = new QPushButton(wdg_left);
        pb_hsz->setObjectName(QString::fromUtf8("pb_hsz"));
        pb_hsz->setMinimumSize(QSize(0, 36));
        pb_hsz->setMaximumSize(QSize(16777215, 36));
        pb_hsz->setFont(font);

        verticalLayout->addWidget(pb_hsz);

        verticalSpacer = new QSpacerItem(20, 207, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pb_name = new QPushButton(wdg_left);
        pb_name->setObjectName(QString::fromUtf8("pb_name"));
        pb_name->setMinimumSize(QSize(0, 36));
        pb_name->setMaximumSize(QSize(16777215, 36));
        pb_name->setFont(font);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/face/btn_avatar_a12.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_name->setIcon(icon3);
        pb_name->setIconSize(QSize(36, 36));
        pb_name->setFlat(true);

        verticalLayout->addWidget(pb_name);


        horizontalLayout->addWidget(wdg_left);

        wdg_right = new QWidget(MainDialog);
        wdg_right->setObjectName(QString::fromUtf8("wdg_right"));
        verticalLayout_2 = new QVBoxLayout(wdg_right);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        sw_page = new QStackedWidget(wdg_right);
        sw_page->setObjectName(QString::fromUtf8("sw_page"));
        page_file = new QWidget();
        page_file->setObjectName(QString::fromUtf8("page_file"));
        verticalLayout_3 = new QVBoxLayout(page_file);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        wdg_right_top = new QWidget(page_file);
        wdg_right_top->setObjectName(QString::fromUtf8("wdg_right_top"));
        wdg_right_top->setMinimumSize(QSize(0, 31));
        wdg_right_top->setMaximumSize(QSize(16777215, 31));
        horizontalLayout_2 = new QHBoxLayout(wdg_right_top);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pb_prev = new QPushButton(wdg_right_top);
        pb_prev->setObjectName(QString::fromUtf8("pb_prev"));
        pb_prev->setMinimumSize(QSize(30, 30));
        pb_prev->setMaximumSize(QSize(30, 30));
        pb_prev->setFlat(true);

        horizontalLayout_2->addWidget(pb_prev);

        pb_next = new QPushButton(wdg_right_top);
        pb_next->setObjectName(QString::fromUtf8("pb_next"));
        pb_next->setMinimumSize(QSize(30, 30));
        pb_next->setMaximumSize(QSize(30, 30));
        pb_next->setFlat(true);

        horizontalLayout_2->addWidget(pb_next);

        lb_path = new QLabel(wdg_right_top);
        lb_path->setObjectName(QString::fromUtf8("lb_path"));
        lb_path->setMinimumSize(QSize(0, 30));
        lb_path->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(lb_path);

        horizontalSpacer = new QSpacerItem(327, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pb_search = new QPushButton(wdg_right_top);
        pb_search->setObjectName(QString::fromUtf8("pb_search"));
        pb_search->setMinimumSize(QSize(30, 30));
        pb_search->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_search->setIcon(icon4);
        pb_search->setIconSize(QSize(30, 30));
        pb_search->setFlat(true);

        horizontalLayout_2->addWidget(pb_search);

        pb_addFile = new QPushButton(wdg_right_top);
        pb_addFile->setObjectName(QString::fromUtf8("pb_addFile"));
        pb_addFile->setMinimumSize(QSize(30, 30));
        pb_addFile->setMaximumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/addFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_addFile->setIcon(icon5);
        pb_addFile->setIconSize(QSize(30, 30));
        pb_addFile->setFlat(true);

        horizontalLayout_2->addWidget(pb_addFile);


        verticalLayout_3->addWidget(wdg_right_top);

        wdg_right_bottom = new QWidget(page_file);
        wdg_right_bottom->setObjectName(QString::fromUtf8("wdg_right_bottom"));
        verticalLayout_4 = new QVBoxLayout(wdg_right_bottom);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        table_file = new QTableWidget(wdg_right_bottom);
        if (table_file->columnCount() < 3)
            table_file->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_file->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_file->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_file->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        table_file->setObjectName(QString::fromUtf8("table_file"));
        table_file->horizontalHeader()->setDefaultSectionSize(160);
        table_file->horizontalHeader()->setStretchLastSection(true);
        table_file->verticalHeader()->setVisible(false);

        verticalLayout_4->addWidget(table_file);


        verticalLayout_3->addWidget(wdg_right_bottom);

        sw_page->addWidget(page_file);
        page_transmit = new QWidget();
        page_transmit->setObjectName(QString::fromUtf8("page_transmit"));
        verticalLayout_5 = new QVBoxLayout(page_transmit);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tw_transmit = new QTabWidget(page_transmit);
        tw_transmit->setObjectName(QString::fromUtf8("tw_transmit"));
        tab_upload = new QWidget();
        tab_upload->setObjectName(QString::fromUtf8("tab_upload"));
        verticalLayout_6 = new QVBoxLayout(tab_upload);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        table_upload = new QTableWidget(tab_upload);
        if (table_upload->columnCount() < 6)
            table_upload->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_upload->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_upload->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_upload->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_upload->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_upload->setHorizontalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_upload->setHorizontalHeaderItem(5, __qtablewidgetitem8);
        table_upload->setObjectName(QString::fromUtf8("table_upload"));
        table_upload->horizontalHeader()->setDefaultSectionSize(95);
        table_upload->horizontalHeader()->setStretchLastSection(true);
        table_upload->verticalHeader()->setVisible(false);

        verticalLayout_6->addWidget(table_upload);

        tw_transmit->addTab(tab_upload, QString());
        tab_download = new QWidget();
        tab_download->setObjectName(QString::fromUtf8("tab_download"));
        verticalLayout_7 = new QVBoxLayout(tab_download);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        table_download = new QTableWidget(tab_download);
        if (table_download->columnCount() < 3)
            table_download->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_download->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_download->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_download->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        table_download->setObjectName(QString::fromUtf8("table_download"));
        table_download->horizontalHeader()->setDefaultSectionSize(160);
        table_download->horizontalHeader()->setStretchLastSection(true);
        table_download->verticalHeader()->setVisible(false);

        verticalLayout_7->addWidget(table_download);

        tw_transmit->addTab(tab_download, QString());
        tab_complete = new QWidget();
        tab_complete->setObjectName(QString::fromUtf8("tab_complete"));
        verticalLayout_8 = new QVBoxLayout(tab_complete);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        table_complete = new QTableWidget(tab_complete);
        if (table_complete->columnCount() < 4)
            table_complete->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table_complete->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table_complete->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table_complete->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table_complete->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        table_complete->setObjectName(QString::fromUtf8("table_complete"));
        table_complete->horizontalHeader()->setDefaultSectionSize(130);
        table_complete->horizontalHeader()->setStretchLastSection(true);
        table_complete->verticalHeader()->setVisible(false);

        verticalLayout_8->addWidget(table_complete);

        tw_transmit->addTab(tab_complete, QString());

        verticalLayout_5->addWidget(tw_transmit);

        sw_page->addWidget(page_transmit);
        page_share = new QWidget();
        page_share->setObjectName(QString::fromUtf8("page_share"));
        verticalLayout_13 = new QVBoxLayout(page_share);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        tw_share = new QTabWidget(page_share);
        tw_share->setObjectName(QString::fromUtf8("tw_share"));
        tab_myShare = new QWidget();
        tab_myShare->setObjectName(QString::fromUtf8("tab_myShare"));
        verticalLayout_12 = new QVBoxLayout(tab_myShare);
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        table_share = new QTableWidget(tab_myShare);
        if (table_share->columnCount() < 3)
            table_share->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        table_share->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        table_share->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        table_share->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        table_share->setObjectName(QString::fromUtf8("table_share"));
        table_share->horizontalHeader()->setDefaultSectionSize(160);
        table_share->horizontalHeader()->setStretchLastSection(true);
        table_share->verticalHeader()->setVisible(false);

        verticalLayout_12->addWidget(table_share);

        tw_share->addTab(tab_myShare, QString());

        verticalLayout_13->addWidget(tw_share);

        sw_page->addWidget(page_share);

        verticalLayout_2->addWidget(sw_page);


        horizontalLayout->addWidget(wdg_right);


        retranslateUi(MainDialog);

        sw_page->setCurrentIndex(1);
        tw_transmit->setCurrentIndex(2);
        tw_share->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QDialog *MainDialog)
    {
        MainDialog->setWindowTitle(QCoreApplication::translate("MainDialog", "MainDialog", nullptr));
        pb_file->setText(QCoreApplication::translate("MainDialog", "\346\226\207\344\273\266", nullptr));
        pb_transmit->setText(QCoreApplication::translate("MainDialog", "\344\274\240\350\276\223", nullptr));
        pb_share->setText(QCoreApplication::translate("MainDialog", "\345\210\206\344\272\253", nullptr));
        pb_store->setText(QCoreApplication::translate("MainDialog", "\346\224\266\350\227\217", nullptr));
        pb_hsz->setText(QCoreApplication::translate("MainDialog", "\345\233\236\346\224\266\347\253\231", nullptr));
        pb_name->setText(QCoreApplication::translate("MainDialog", "name", nullptr));
        pb_prev->setText(QCoreApplication::translate("MainDialog", "<", nullptr));
        pb_next->setText(QCoreApplication::translate("MainDialog", ">", nullptr));
        lb_path->setText(QCoreApplication::translate("MainDialog", "/", nullptr));
        pb_search->setText(QString());
        pb_addFile->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table_file->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainDialog", "\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_file->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainDialog", "\345\244\247\345\260\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_file->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainDialog", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_upload->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainDialog", "\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_upload->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainDialog", "\345\244\247\345\260\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_upload->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainDialog", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table_upload->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainDialog", "\351\200\237\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table_upload->horizontalHeaderItem(4);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainDialog", "\350\277\233\345\272\246", nullptr));
        tw_transmit->setTabText(tw_transmit->indexOf(tab_upload), QCoreApplication::translate("MainDialog", "\344\270\212\344\274\240\344\270\255", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table_download->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainDialog", "\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = table_download->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainDialog", "\345\244\247\345\260\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = table_download->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainDialog", "\346\227\266\351\227\264", nullptr));
        tw_transmit->setTabText(tw_transmit->indexOf(tab_download), QCoreApplication::translate("MainDialog", "\344\270\213\350\275\275\344\270\255", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = table_complete->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainDialog", "\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = table_complete->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainDialog", "\345\244\247\345\260\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = table_complete->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainDialog", "\346\227\266\351\227\264", nullptr));
        tw_transmit->setTabText(tw_transmit->indexOf(tab_complete), QCoreApplication::translate("MainDialog", "\345\267\262\345\256\214\346\210\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = table_share->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainDialog", "\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = table_share->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainDialog", "\345\244\247\345\260\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = table_share->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainDialog", "\346\227\266\351\227\264", nullptr));
        tw_share->setTabText(tw_share->indexOf(tab_myShare), QCoreApplication::translate("MainDialog", "\346\210\221\347\232\204\345\210\206\344\272\253", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
