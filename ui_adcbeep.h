/********************************************************************************
** Form generated from reading UI file 'adcbeep.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADCBEEP_H
#define UI_ADCBEEP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdcBeep
{
public:
    QPushButton *returnBt;
    QPushButton *firebt;
    QPushButton *sr04bt;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *adcValue;
    QLabel *sr04Value;

    void setupUi(QWidget *AdcBeep)
    {
        if (AdcBeep->objectName().isEmpty())
            AdcBeep->setObjectName(QStringLiteral("AdcBeep"));
        AdcBeep->resize(800, 480);
        AdcBeep->setMinimumSize(QSize(800, 480));
        AdcBeep->setMaximumSize(QSize(800, 480));
        returnBt = new QPushButton(AdcBeep);
        returnBt->setObjectName(QStringLiteral("returnBt"));
        returnBt->setGeometry(QRect(640, 40, 61, 61));
        firebt = new QPushButton(AdcBeep);
        firebt->setObjectName(QStringLiteral("firebt"));
        firebt->setGeometry(QRect(550, 140, 151, 51));
        sr04bt = new QPushButton(AdcBeep);
        sr04bt->setObjectName(QStringLiteral("sr04bt"));
        sr04bt->setGeometry(QRect(550, 220, 151, 51));
        widget = new QWidget(AdcBeep);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(120, 130, 261, 141));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        adcValue = new QLabel(widget);
        adcValue->setObjectName(QStringLiteral("adcValue"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(adcValue->sizePolicy().hasHeightForWidth());
        adcValue->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        adcValue->setFont(font);

        verticalLayout->addWidget(adcValue);

        sr04Value = new QLabel(widget);
        sr04Value->setObjectName(QStringLiteral("sr04Value"));
        sizePolicy.setHeightForWidth(sr04Value->sizePolicy().hasHeightForWidth());
        sr04Value->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        sr04Value->setFont(font1);

        verticalLayout->addWidget(sr04Value);


        retranslateUi(AdcBeep);

        QMetaObject::connectSlotsByName(AdcBeep);
    } // setupUi

    void retranslateUi(QWidget *AdcBeep)
    {
        AdcBeep->setWindowTitle(QApplication::translate("AdcBeep", "Form", 0));
        returnBt->setText(QApplication::translate("AdcBeep", "\350\277\224\345\233\236", 0));
        firebt->setText(QApplication::translate("AdcBeep", "FIRE ON", 0));
        sr04bt->setText(QApplication::translate("AdcBeep", "SR04 ON", 0));
        adcValue->setText(QApplication::translate("AdcBeep", "FIRE MV", 0));
        sr04Value->setText(QApplication::translate("AdcBeep", "SR04 MM", 0));
    } // retranslateUi

};

namespace Ui {
    class AdcBeep: public Ui_AdcBeep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADCBEEP_H
