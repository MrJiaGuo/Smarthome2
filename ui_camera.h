/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_camera
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *videoLb;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *yuvTyRb;
    QRadioButton *jpegTyRb;
    QComboBox *deviceCb;
    QPushButton *startBt;
    QPushButton *stopBt;
    QPushButton *camBt;
    QPushButton *returnBt;

    void setupUi(QWidget *camera)
    {
        if (camera->objectName().isEmpty())
            camera->setObjectName(QStringLiteral("camera"));
        camera->resize(800, 480);
        camera->setMinimumSize(QSize(800, 480));
        camera->setMaximumSize(QSize(800, 480));
        gridLayout = new QGridLayout(camera);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        videoLb = new QLabel(camera);
        videoLb->setObjectName(QStringLiteral("videoLb"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(videoLb->sizePolicy().hasHeightForWidth());
        videoLb->setSizePolicy(sizePolicy);
        videoLb->setMinimumSize(QSize(600, 480));
        videoLb->setMaximumSize(QSize(600, 480));
        videoLb->setStyleSheet(QStringLiteral("background-color: rgb(146, 255, 219);"));

        horizontalLayout_2->addWidget(videoLb);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(camera);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(150, 0));
        label_2->setMaximumSize(QSize(100, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        yuvTyRb = new QRadioButton(camera);
        yuvTyRb->setObjectName(QStringLiteral("yuvTyRb"));
        yuvTyRb->setMinimumSize(QSize(50, 0));
        yuvTyRb->setMaximumSize(QSize(100, 16777215));
        yuvTyRb->setFont(font);

        horizontalLayout->addWidget(yuvTyRb);

        jpegTyRb = new QRadioButton(camera);
        jpegTyRb->setObjectName(QStringLiteral("jpegTyRb"));
        jpegTyRb->setMinimumSize(QSize(50, 0));
        jpegTyRb->setMaximumSize(QSize(100, 16777215));
        jpegTyRb->setFont(font);

        horizontalLayout->addWidget(jpegTyRb);


        verticalLayout->addLayout(horizontalLayout);

        deviceCb = new QComboBox(camera);
        deviceCb->setObjectName(QStringLiteral("deviceCb"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(deviceCb->sizePolicy().hasHeightForWidth());
        deviceCb->setSizePolicy(sizePolicy2);
        deviceCb->setMinimumSize(QSize(150, 0));
        deviceCb->setMaximumSize(QSize(200, 16777215));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        deviceCb->setFont(font1);

        verticalLayout->addWidget(deviceCb);

        startBt = new QPushButton(camera);
        startBt->setObjectName(QStringLiteral("startBt"));
        sizePolicy2.setHeightForWidth(startBt->sizePolicy().hasHeightForWidth());
        startBt->setSizePolicy(sizePolicy2);
        startBt->setMinimumSize(QSize(150, 0));
        startBt->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(startBt);

        stopBt = new QPushButton(camera);
        stopBt->setObjectName(QStringLiteral("stopBt"));
        sizePolicy2.setHeightForWidth(stopBt->sizePolicy().hasHeightForWidth());
        stopBt->setSizePolicy(sizePolicy2);
        stopBt->setMinimumSize(QSize(150, 0));
        stopBt->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(stopBt);

        camBt = new QPushButton(camera);
        camBt->setObjectName(QStringLiteral("camBt"));
        sizePolicy2.setHeightForWidth(camBt->sizePolicy().hasHeightForWidth());
        camBt->setSizePolicy(sizePolicy2);
        camBt->setMinimumSize(QSize(150, 0));
        camBt->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(camBt);

        returnBt = new QPushButton(camera);
        returnBt->setObjectName(QStringLiteral("returnBt"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(returnBt->sizePolicy().hasHeightForWidth());
        returnBt->setSizePolicy(sizePolicy3);
        returnBt->setMinimumSize(QSize(150, 0));
        returnBt->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(returnBt);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(camera);

        QMetaObject::connectSlotsByName(camera);
    } // setupUi

    void retranslateUi(QWidget *camera)
    {
        camera->setWindowTitle(QApplication::translate("camera", "Form", 0));
        videoLb->setText(QString());
        label_2->setText(QApplication::translate("camera", "\351\200\211\346\213\251\350\246\201\346\211\223\345\274\200\347\232\204\350\256\276\345\244\207", 0));
        yuvTyRb->setText(QApplication::translate("camera", "YUV", 0));
        jpegTyRb->setText(QApplication::translate("camera", "MJPEG", 0));
        deviceCb->clear();
        deviceCb->insertItems(0, QStringList()
         << QApplication::translate("camera", "/dev/video0", 0)
         << QApplication::translate("camera", "/dev/video1", 0)
         << QApplication::translate("camera", "/dev/video2", 0)
         << QApplication::translate("camera", "/dev/video3", 0)
         << QApplication::translate("camera", "/dev/video4", 0)
         << QApplication::translate("camera", "/dev/video5", 0)
         << QApplication::translate("camera", "/dev/video6", 0)
         << QApplication::translate("camera", "/dev/video7", 0)
         << QApplication::translate("camera", "/dev/video8", 0)
        );
        startBt->setText(QApplication::translate("camera", "\345\274\200\345\220\257", 0));
        stopBt->setText(QApplication::translate("camera", "\345\205\263\351\227\255", 0));
        camBt->setText(QApplication::translate("camera", "\346\213\215\347\205\247", 0));
        returnBt->setText(QApplication::translate("camera", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class camera: public Ui_camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
