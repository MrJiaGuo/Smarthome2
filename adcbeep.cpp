#include "adcbeep.h"
#include "ui_adcbeep.h"
#include <smarthomemainwindow.h>
#include <QDebug>
extern int gloable_adcfd;
extern int gloable_sr04fd;
AdcQthread *mythread = new AdcQthread();
SR04Qthread *sr04_thread = new SR04Qthread() ;
int adc_flag = 0;
int sr04_flag = 0;

AdcBeep::AdcBeep(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdcBeep)
{
    ui->setupUi(this);
    qDebug()<<"adcbeep_ui";

    if(gloable_adcfd>0 && !adc_flag)
    {
        connect (mythread,SIGNAL(isDone(int)),this,SLOT(dealDone(int)));
        mythread->start ();
        ui->firebt->setText("FIRE OFF");
        adc_flag = 1;
    }
    else
    {
        connect (mythread,SIGNAL(isDone(int)),this,SLOT(dealDone(int)));
         ui->firebt->setText("FIRE OFF");
    }

    if(gloable_sr04fd>0 && !sr04_flag)
    {
        connect (sr04_thread,SIGNAL(SR04_isDone(int)),this,SLOT(SR04_dealDone(int)));
        sr04_thread->start ();
        ui->sr04bt->setText("SR04 OFF");
        sr04_flag = 1;
    }
    else
    {
        connect (sr04_thread,SIGNAL(SR04_isDone(int)),this,SLOT(SR04_dealDone(int)));
        ui->sr04bt->setText("SR04 OFF");
    }

}

AdcBeep::~AdcBeep()
{
    delete ui;
    qDebug()<<"delete adcbeep";
}

void AdcBeep::on_returnBt_clicked()
{
    SmartHomeMainWindow *myMainWindow = new SmartHomeMainWindow();
    this->hide ();
    myMainWindow->show ();
}

void AdcBeep::dealDone(int num)
{
    if(num)
    {
        ui->adcValue->setText (QString::number (num));
    }
}

void AdcBeep::SR04_dealDone(int num)
{
    if(num)
    {
        ui->sr04Value->setText (QString::number (num));
    }
}


void AdcBeep::on_firebt_clicked()
{

    if(!adc_flag)
    {

        connect (mythread,SIGNAL(isDone(int)),this,SLOT(dealDone(int)));
        mythread->start ();
        ui->firebt->setText("FIRE OFF");
        adc_flag = 1;
    }
    else
    {
        qDebug()<<"ADC EXIT";
        disconnect (mythread,0,0,0);
        mythread->disconnect ();
        mythread->terminate ();
       /* ui->firebt->setEnabled(false);
        mythread->wait();
        ui->firebt->setEnabled(true);*/
       // ::close(gloable_adcfd);
        //gloable_adcfd = 0;
        //delete mythread;
        //mythread = NULL;
        ui->firebt->setText("FIRE ON");
        ui->adcValue->setText ("FIRE MV");
        qDebug()<<"ADC EXIT OK";
        adc_flag = 0;
    }
}


void AdcBeep::on_sr04bt_clicked()
{

    if(!sr04_flag)
    {
        connect (sr04_thread,SIGNAL(SR04_isDone(int)),this,SLOT(SR04_dealDone(int)));
        sr04_thread->start ();
        ui->sr04bt->setText("SR04 OFF");
        sr04_flag = 1;
    }
    else
    {
        qDebug()<<"SR04 EXIT";
        disconnect (sr04_thread,0,0,0);
        sr04_thread->disconnect ();
        //sr04_thread->quit();
        /*ui->sr04bt->setEnabled(false);
        sr04_thread->wait();
        ui->sr04bt->setEnabled(true);*/
        sr04_thread->terminate ();
        //::close(gloable_sr04fd);
      //  gloable_sr04fd = 0;
       // delete sr04_thread;
        //sr04_thread = NULL;
        ui->sr04bt->setText("SR04 ON");
        ui->sr04Value->setText ("SR04 MM");
        qDebug()<<"SR04 EXIT OK";
        sr04_flag = 0;
    }
}
