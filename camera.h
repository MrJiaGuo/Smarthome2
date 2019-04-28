#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <api_v4l2.h>
#include <QTimer>
#include <QDebug>
namespace Ui {
class camera;
}

class camera : public QWidget
{
    Q_OBJECT

public:
    explicit camera(QWidget *parent = 0);
    ~camera();

private slots:
    void on_yuvTyRb_clicked(bool checked);

    void on_jpegTyRb_clicked(bool checked);

    void on_startBt_clicked();

    void on_stopBt_clicked();

    void on_camBt_clicked();
    void update_video();
    void on_returnBt_clicked();

private:
    Ui::camera *ui;
    ApiV4l2 *mApiV4l2;
    QTimer *mTimer;
    FreamBuffer mFrame;

    bool typeflag;  //false-yuv， true-mjpeg

    unsigned char rgbbuff[1843200];
};

#endif // CAMERA_H
