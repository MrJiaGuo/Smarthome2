#include "camera.h"
#include "ui_camera.h"
#include <smarthomemainwindow.h>
camera::camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::camera)
{
    ui->setupUi(this);
    //按钮失效设置
    ui->stopBt->setEnabled(false);
    ui->camBt->setEnabled(false);

    //初始化摄像头对象
    mApiV4l2 = new ApiV4l2();

    //定时器初始化
    mTimer = new QTimer();
    connect(mTimer,SIGNAL(timeout()),this, SLOT(update_video()));
}

camera::~camera()
{
    delete ui;
}

void camera::on_yuvTyRb_clicked(bool checked)
{
    if(checked) typeflag = false;
}

void camera::on_jpegTyRb_clicked(bool checked)
{
    if(checked) typeflag = true;
}

void camera::on_startBt_clicked()
{
    ui->deviceCb->setEnabled(false);
    ui->stopBt->setEnabled(true);
    ui->camBt->setEnabled(true);
    ui->startBt->setEnabled(false);

    qDebug()<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
    //初始化摄像头
    mApiV4l2->linux_v4l2_device_init(ui->deviceCb->currentText().toUtf8().data());
    mApiV4l2->linux_v4l2_start_capturing();

    //开启定时器--更新显示
    mTimer->start(100);
}

void camera::on_stopBt_clicked()
{
    ui->deviceCb->setEnabled(true);
    ui->stopBt->setEnabled(false);
    ui->camBt->setEnabled(false);
    ui->startBt->setEnabled(true);

    //停止定时器--停止显示刷新
    mTimer->stop();
    mApiV4l2->linux_v4l2_stop_capturing();
    mApiV4l2->linux_v4l2_device_uinit();
}

void camera::on_camBt_clicked()
{
    if(typeflag)
    {
        QPixmap mmp;
        mmp.loadFromData(mFrame.buf,mFrame.length);
        mmp.save("./mmp.jpg");
    }else
    {
        mApiV4l2->yuyv_to_rgb888(mFrame.buf,rgbbuff, 640,480);
        QPixmap mmp;
        mmp.loadFromData(rgbbuff,mFrame.length);
        mmp.save("./mmp.jpg");
    }
}

void camera::update_video()
{
    //采集一帧数据
    mApiV4l2->linux_v4l2_get_fream(&mFrame);
    //显示
    if(typeflag)
    {
        QPixmap mmp;
        mmp.loadFromData(mFrame.buf,mFrame.length);
        ui->videoLb->setPixmap(mmp);
    }else
    {
        mApiV4l2->yuyv_to_rgb888(mFrame.buf,rgbbuff, 640,480);
        QPixmap mmp;
        mmp.loadFromData(rgbbuff,mFrame.length);
        ui->videoLb->setPixmap(mmp);
    }
}

void camera::on_returnBt_clicked()
{
    SmartHomeMainWindow *myMainWindow = new SmartHomeMainWindow();
    this->close ();
    myMainWindow->show ();
}
