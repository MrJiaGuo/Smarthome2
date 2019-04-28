#include "sr04qthread.h"
#include <adcbeep.h>
#include <QDebug>
#include "adcqthread.h"
extern int gloable_adcfd;
extern int beep_flag;
int gloable_sr04fd = 0;
SR04Qthread::SR04Qthread(QObject *parent) : QThread(parent)
{
    //打开adc设备
    this->sr04fd = open("/dev/mysr04",O_RDWR);
    if(this->sr04fd < 0)
    {
        qDebug()<<"sr04 open fail";
    }
    else
    {
       gloable_sr04fd = this->sr04fd;
        qDebug()<<"sr04fd:"<<gloable_sr04fd;
    }
}

void SR04Qthread::run()
{
    int len ;
    int d;//测距
    while(1)
    {
        if(sr04fd>0)
        {
            len = ::read(sr04fd,&d,4);

            if(len <= 0)
            {
                perror("read sr04");

                continue;
            }

            if(d<20 || d>4000)
            {
                printf("distance is error\r\n");
            }
            else
            {
                printf("distance:%dmm\n",d);
                emit SR04_isDone (d);
                if(d<=50)
                    ioctl(gloable_adcfd,GEC6818_BEEP_ON,4);
                else if(d>50 && !beep_flag)
                    ioctl(gloable_adcfd,GEC6818_BEEP_OFF,5);
            }
        }
        sleep(1);
    }
    ::close(sr04fd);
}
