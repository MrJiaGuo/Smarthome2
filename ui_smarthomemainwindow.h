/********************************************************************************
** Form generated from reading UI file 'smarthomemainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTHOMEMAINWINDOW_H
#define UI_SMARTHOMEMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmartHomeMainWindow
{
public:
    QPushButton *cameraBt;
    QPushButton *pushButton;
    QPushButton *recordBt;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *humiLable;
    QLabel *tempLable;
    QVBoxLayout *verticalLayout_2;
    QLabel *templable;
    QLabel *humilable;

    void setupUi(QWidget *SmartHomeMainWindow)
    {
        if (SmartHomeMainWindow->objectName().isEmpty())
            SmartHomeMainWindow->setObjectName(QStringLiteral("SmartHomeMainWindow"));
        SmartHomeMainWindow->resize(800, 480);
        SmartHomeMainWindow->setMinimumSize(QSize(800, 480));
        SmartHomeMainWindow->setMaximumSize(QSize(800, 480));
        cameraBt = new QPushButton(SmartHomeMainWindow);
        cameraBt->setObjectName(QStringLiteral("cameraBt"));
        cameraBt->setGeometry(QRect(630, 60, 81, 61));
        pushButton = new QPushButton(SmartHomeMainWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(630, 170, 91, 51));
        recordBt = new QPushButton(SmartHomeMainWindow);
        recordBt->setObjectName(QStringLiteral("recordBt"));
        recordBt->setGeometry(QRect(630, 310, 91, 61));
        widget = new QWidget(SmartHomeMainWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 191, 71));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        humiLable = new QLabel(widget);
        humiLable->setObjectName(QStringLiteral("humiLable"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(humiLable->sizePolicy().hasHeightForWidth());
        humiLable->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        humiLable->setFont(font);

        verticalLayout->addWidget(humiLable);

        tempLable = new QLabel(widget);
        tempLable->setObjectName(QStringLiteral("tempLable"));
        sizePolicy.setHeightForWidth(tempLable->sizePolicy().hasHeightForWidth());
        tempLable->setSizePolicy(sizePolicy);
        tempLable->setFont(font);

        verticalLayout->addWidget(tempLable);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        templable = new QLabel(widget);
        templable->setObjectName(QStringLiteral("templable"));
        sizePolicy.setHeightForWidth(templable->sizePolicy().hasHeightForWidth());
        templable->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(16);
        templable->setFont(font1);

        verticalLayout_2->addWidget(templable);

        humilable = new QLabel(widget);
        humilable->setObjectName(QStringLiteral("humilable"));
        sizePolicy.setHeightForWidth(humilable->sizePolicy().hasHeightForWidth());
        humilable->setSizePolicy(sizePolicy);
        humilable->setFont(font1);

        verticalLayout_2->addWidget(humilable);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(SmartHomeMainWindow);

        QMetaObject::connectSlotsByName(SmartHomeMainWindow);
    } // setupUi

    void retranslateUi(QWidget *SmartHomeMainWindow)
    {
        SmartHomeMainWindow->setWindowTitle(QApplication::translate("SmartHomeMainWindow", "SmartHomeMainWindow", 0));
        cameraBt->setText(QApplication::translate("SmartHomeMainWindow", "camera", 0));
        pushButton->setText(QApplication::translate("SmartHomeMainWindow", "adc", 0));
        recordBt->setText(QApplication::translate("SmartHomeMainWindow", "record", 0));
        humiLable->setText(QApplication::translate("SmartHomeMainWindow", "temp:", 0));
        tempLable->setText(QApplication::translate("SmartHomeMainWindow", "humi:", 0));
        templable->setText(QApplication::translate("SmartHomeMainWindow", "\302\260C", 0));
        humilable->setText(QApplication::translate("SmartHomeMainWindow", "%", 0));
    } // retranslateUi

};

namespace Ui {
    class SmartHomeMainWindow: public Ui_SmartHomeMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTHOMEMAINWINDOW_H
