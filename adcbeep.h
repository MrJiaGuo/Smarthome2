#ifndef ADCBEEP_H
#define ADCBEEP_H

#include <QWidget>
#include <adcqthread.h>
#include <sr04qthread.h>
extern "C"
{
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>


#define GEC6818_ADC_IN0			_IOR('A',1,unsigned long)
#define GEC6818_ADC_IN1			_IOR('A',2,unsigned long)
#define GEC6818_ADC_IN3			_IOR('A',3,unsigned long)
#define GEC6818_BEEP_ON		    _IOW('B',4,unsigned int)
#define GEC6818_BEEP_OFF		_IOW('B',5,unsigned int)
}



namespace Ui {
class AdcBeep;
}

class AdcBeep : public QWidget
{
    Q_OBJECT

public:
    explicit AdcBeep(QWidget *parent = 0);
    ~AdcBeep();

private slots:
    void on_returnBt_clicked();
    void dealDone(int num); //ADC
    void SR04_dealDone(int num);//SR04
    void on_firebt_clicked();

    void on_sr04bt_clicked();

private:
    Ui::AdcBeep *ui;
    //int beep_on_number;
};

#endif // ADCBEEP_H
