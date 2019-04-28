#include "adcqthread.h"
#include <QDebug>
int gloable_adcfd = 0;
int beep_flag = 0;
AdcQthread::AdcQthread(QObject *parent) : QThread(parent)
{
    //打开adc设备
    this->adcfd = open("/dev/myadc",O_RDWR);
    if(this->adcfd < 0)
    {
        qDebug()<<"adc open fail";
    }
    else
    {
        gloable_adcfd = this->adcfd;
        qDebug()<<"adcfd:"<<gloable_adcfd;
    }
}

void AdcQthread::run()
{
    int rt;
    int adc_vol;

    while(1)
    {
        if(adcfd>0)
        {
            //读取ADC通道0的电压值
            rt = ioctl(adcfd,GEC6818_ADC_IN1,&adc_vol);
            if(rt == 0)
            {
                if(adc_vol<500)
                {
                    ioctl(adcfd,GEC6818_BEEP_ON,4);
                    beep_flag = 1;
                    printf("adc in0 vol=%dmv\n",adc_vol);
                }
                else
                {
                    if(beep_flag)
                    {
                        ioctl(adcfd,GEC6818_BEEP_OFF,5);
                        beep_flag = 0;
                    }

                }
                emit isDone (adc_vol);
            }
        }
        usleep(500000);
    }

    ::close (adcfd);

}
