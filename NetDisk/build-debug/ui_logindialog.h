/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *pb_icon;
    QTabWidget *tw_page;
    QWidget *tab_login;
    QPushButton *pb_login;
    QPushButton *pb_clear;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *lb_tel;
    QLineEdit *le_tel;
    QLabel *lb_password;
    QLineEdit *le_password;
    QWidget *tab_register;
    QPushButton *pb_login_register;
    QPushButton *pb_clear_register;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *lb_password_register;
    QLabel *lb_confirm_register;
    QLineEdit *le_confirm_register;
    QLabel *lb_tel_register;
    QLineEdit *le_password_register;
    QLineEdit *le_tel_register;
    QLabel *lb_name_register;
    QLineEdit *le_name_register;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(621, 300);
        LoginDialog->setMinimumSize(QSize(621, 300));
        LoginDialog->setMaximumSize(QSize(621, 300));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        LoginDialog->setFont(font);
        pb_icon = new QLabel(LoginDialog);
        pb_icon->setObjectName(QString::fromUtf8("pb_icon"));
        pb_icon->setGeometry(QRect(30, 15, 251, 261));
        pb_icon->setPixmap(QPixmap(QString::fromUtf8(":/tb/baidu.png")));
        pb_icon->setScaledContents(true);
        tw_page = new QTabWidget(LoginDialog);
        tw_page->setObjectName(QString::fromUtf8("tw_page"));
        tw_page->setGeometry(QRect(310, 10, 301, 271));
        tab_login = new QWidget();
        tab_login->setObjectName(QString::fromUtf8("tab_login"));
        pb_login = new QPushButton(tab_login);
        pb_login->setObjectName(QString::fromUtf8("pb_login"));
        pb_login->setGeometry(QRect(210, 200, 80, 24));
        pb_clear = new QPushButton(tab_login);
        pb_clear->setObjectName(QString::fromUtf8("pb_clear"));
        pb_clear->setGeometry(QRect(120, 200, 80, 24));
        widget = new QWidget(tab_login);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 261, 101));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lb_tel = new QLabel(widget);
        lb_tel->setObjectName(QString::fromUtf8("lb_tel"));

        gridLayout->addWidget(lb_tel, 0, 0, 1, 1);

        le_tel = new QLineEdit(widget);
        le_tel->setObjectName(QString::fromUtf8("le_tel"));

        gridLayout->addWidget(le_tel, 0, 1, 1, 1);

        lb_password = new QLabel(widget);
        lb_password->setObjectName(QString::fromUtf8("lb_password"));

        gridLayout->addWidget(lb_password, 1, 0, 1, 1);

        le_password = new QLineEdit(widget);
        le_password->setObjectName(QString::fromUtf8("le_password"));
        le_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(le_password, 1, 1, 1, 1);

        tw_page->addTab(tab_login, QString());
        tab_register = new QWidget();
        tab_register->setObjectName(QString::fromUtf8("tab_register"));
        pb_login_register = new QPushButton(tab_register);
        pb_login_register->setObjectName(QString::fromUtf8("pb_login_register"));
        pb_login_register->setGeometry(QRect(210, 200, 80, 24));
        pb_clear_register = new QPushButton(tab_register);
        pb_clear_register->setObjectName(QString::fromUtf8("pb_clear_register"));
        pb_clear_register->setGeometry(QRect(120, 200, 80, 24));
        layoutWidget = new QWidget(tab_register);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 261, 132));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lb_password_register = new QLabel(layoutWidget);
        lb_password_register->setObjectName(QString::fromUtf8("lb_password_register"));

        gridLayout_2->addWidget(lb_password_register, 1, 0, 1, 1);

        lb_confirm_register = new QLabel(layoutWidget);
        lb_confirm_register->setObjectName(QString::fromUtf8("lb_confirm_register"));

        gridLayout_2->addWidget(lb_confirm_register, 2, 0, 1, 1);

        le_confirm_register = new QLineEdit(layoutWidget);
        le_confirm_register->setObjectName(QString::fromUtf8("le_confirm_register"));
        le_confirm_register->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(le_confirm_register, 2, 1, 1, 1);

        lb_tel_register = new QLabel(layoutWidget);
        lb_tel_register->setObjectName(QString::fromUtf8("lb_tel_register"));

        gridLayout_2->addWidget(lb_tel_register, 0, 0, 1, 1);

        le_password_register = new QLineEdit(layoutWidget);
        le_password_register->setObjectName(QString::fromUtf8("le_password_register"));
        le_password_register->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(le_password_register, 1, 1, 1, 1);

        le_tel_register = new QLineEdit(layoutWidget);
        le_tel_register->setObjectName(QString::fromUtf8("le_tel_register"));

        gridLayout_2->addWidget(le_tel_register, 0, 1, 1, 1);

        lb_name_register = new QLabel(layoutWidget);
        lb_name_register->setObjectName(QString::fromUtf8("lb_name_register"));

        gridLayout_2->addWidget(lb_name_register, 3, 0, 1, 1);

        le_name_register = new QLineEdit(layoutWidget);
        le_name_register->setObjectName(QString::fromUtf8("le_name_register"));

        gridLayout_2->addWidget(le_name_register, 3, 1, 1, 1);

        tw_page->addTab(tab_register, QString());
        QWidget::setTabOrder(le_tel_register, le_password_register);
        QWidget::setTabOrder(le_password_register, le_confirm_register);
        QWidget::setTabOrder(le_confirm_register, le_name_register);
        QWidget::setTabOrder(le_name_register, pb_clear_register);
        QWidget::setTabOrder(pb_clear_register, pb_login_register);
        QWidget::setTabOrder(pb_login_register, tw_page);
        QWidget::setTabOrder(tw_page, le_tel);
        QWidget::setTabOrder(le_tel, le_password);
        QWidget::setTabOrder(le_password, pb_clear);
        QWidget::setTabOrder(pb_clear, pb_login);

        retranslateUi(LoginDialog);

        tw_page->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        pb_icon->setText(QString());
        pb_login->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        pb_clear->setText(QCoreApplication::translate("LoginDialog", "\346\270\205\347\251\272", nullptr));
        lb_tel->setText(QCoreApplication::translate("LoginDialog", "\346\211\213\346\234\272\345\217\267", nullptr));
        le_tel->setText(QCoreApplication::translate("LoginDialog", "13313331333", nullptr));
        lb_password->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        le_password->setText(QCoreApplication::translate("LoginDialog", "1", nullptr));
        tw_page->setTabText(tw_page->indexOf(tab_login), QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        pb_login_register->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
        pb_clear_register->setText(QCoreApplication::translate("LoginDialog", "\346\270\205\347\251\272", nullptr));
        lb_password_register->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        lb_confirm_register->setText(QCoreApplication::translate("LoginDialog", "\347\241\256\350\256\244", nullptr));
        le_confirm_register->setText(QString());
        lb_tel_register->setText(QCoreApplication::translate("LoginDialog", "\346\211\213\346\234\272\345\217\267", nullptr));
        le_password_register->setText(QString());
        lb_name_register->setText(QCoreApplication::translate("LoginDialog", "\346\230\265\347\247\260", nullptr));
        le_name_register->setText(QString());
        tw_page->setTabText(tw_page->indexOf(tab_register), QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
