/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QPushButton *rfidbt;
    QLabel *cardid_label;
    QLineEdit *passwd_Edit;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *bt1;
    QPushButton *bt2;
    QPushButton *bt3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bt4;
    QPushButton *bt5;
    QPushButton *bt6;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *bt7;
    QPushButton *bt8;
    QPushButton *bt9;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *delete_bt;
    QPushButton *bt0;
    QPushButton *enter_bt;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(800, 480);
        login->setMinimumSize(QSize(800, 480));
        login->setMaximumSize(QSize(800, 480));
        rfidbt = new QPushButton(login);
        rfidbt->setObjectName(QStringLiteral("rfidbt"));
        rfidbt->setGeometry(QRect(570, 260, 131, 61));
        cardid_label = new QLabel(login);
        cardid_label->setObjectName(QStringLiteral("cardid_label"));
        cardid_label->setGeometry(QRect(160, 20, 511, 41));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        cardid_label->setFont(font);
        passwd_Edit = new QLineEdit(login);
        passwd_Edit->setObjectName(QStringLiteral("passwd_Edit"));
        passwd_Edit->setGeometry(QRect(140, 80, 301, 41));
        passwd_Edit->setEchoMode(QLineEdit::Password);
        widget = new QWidget(login);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(110, 180, 371, 251));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        bt1 = new QPushButton(widget);
        bt1->setObjectName(QStringLiteral("bt1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bt1->sizePolicy().hasHeightForWidth());
        bt1->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(bt1);

        bt2 = new QPushButton(widget);
        bt2->setObjectName(QStringLiteral("bt2"));
        sizePolicy.setHeightForWidth(bt2->sizePolicy().hasHeightForWidth());
        bt2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(bt2);

        bt3 = new QPushButton(widget);
        bt3->setObjectName(QStringLiteral("bt3"));
        sizePolicy.setHeightForWidth(bt3->sizePolicy().hasHeightForWidth());
        bt3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(bt3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        bt4 = new QPushButton(widget);
        bt4->setObjectName(QStringLiteral("bt4"));
        sizePolicy.setHeightForWidth(bt4->sizePolicy().hasHeightForWidth());
        bt4->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(bt4);

        bt5 = new QPushButton(widget);
        bt5->setObjectName(QStringLiteral("bt5"));
        sizePolicy.setHeightForWidth(bt5->sizePolicy().hasHeightForWidth());
        bt5->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(bt5);

        bt6 = new QPushButton(widget);
        bt6->setObjectName(QStringLiteral("bt6"));
        sizePolicy.setHeightForWidth(bt6->sizePolicy().hasHeightForWidth());
        bt6->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(bt6);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        bt7 = new QPushButton(widget);
        bt7->setObjectName(QStringLiteral("bt7"));
        sizePolicy.setHeightForWidth(bt7->sizePolicy().hasHeightForWidth());
        bt7->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(bt7);

        bt8 = new QPushButton(widget);
        bt8->setObjectName(QStringLiteral("bt8"));
        sizePolicy.setHeightForWidth(bt8->sizePolicy().hasHeightForWidth());
        bt8->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(bt8);

        bt9 = new QPushButton(widget);
        bt9->setObjectName(QStringLiteral("bt9"));
        sizePolicy.setHeightForWidth(bt9->sizePolicy().hasHeightForWidth());
        bt9->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(bt9);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        delete_bt = new QPushButton(widget);
        delete_bt->setObjectName(QStringLiteral("delete_bt"));
        sizePolicy.setHeightForWidth(delete_bt->sizePolicy().hasHeightForWidth());
        delete_bt->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(delete_bt);

        bt0 = new QPushButton(widget);
        bt0->setObjectName(QStringLiteral("bt0"));
        sizePolicy.setHeightForWidth(bt0->sizePolicy().hasHeightForWidth());
        bt0->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(bt0);

        enter_bt = new QPushButton(widget);
        enter_bt->setObjectName(QStringLiteral("enter_bt"));
        sizePolicy.setHeightForWidth(enter_bt->sizePolicy().hasHeightForWidth());
        enter_bt->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(enter_bt);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Form", 0));
        rfidbt->setText(QApplication::translate("login", "RFID", 0));
        cardid_label->setText(QApplication::translate("login", "cardID", 0));
        passwd_Edit->setInputMask(QString());
        passwd_Edit->setText(QString());
        passwd_Edit->setPlaceholderText(QApplication::translate("login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        bt1->setText(QApplication::translate("login", "1", 0));
        bt2->setText(QApplication::translate("login", "2", 0));
        bt3->setText(QApplication::translate("login", "3", 0));
        bt4->setText(QApplication::translate("login", "4", 0));
        bt5->setText(QApplication::translate("login", "5", 0));
        bt6->setText(QApplication::translate("login", "6", 0));
        bt7->setText(QApplication::translate("login", "7", 0));
        bt8->setText(QApplication::translate("login", "8", 0));
        bt9->setText(QApplication::translate("login", "9", 0));
        delete_bt->setText(QApplication::translate("login", "del", 0));
        bt0->setText(QApplication::translate("login", "0", 0));
        enter_bt->setText(QApplication::translate("login", "enter", 0));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
