#include "smarthomemainwindow.h"
#include "ui_smarthomemainwindow.h"
#include <camera.h>
#include <adcbeep.h>
#include "./inc/common.h"
#include "irqthread.h"
extern int gloable_irfd;
extern int fd_led;
int ir_flag = 0;
int led_flag = 0;
int led4_flag = 0;
IrQthread *irthread = new IrQthread();

SmartHomeMainWindow::SmartHomeMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmartHomeMainWindow)
{
    ui->setupUi(this);

    this->dht11_fd = open("/dev/mydht11",O_RDWR);
    if(dht11_fd < 0)
    {
        perror("open dht11 faild");
    }
    else
    {
        //温湿度获取
        DHT11_Timer = new QTimer();
        connect(DHT11_Timer,SIGNAL(timeout()),this, SLOT(update_dht11()));
        DHT11_Timer->start (6000);
    }

    if(gloable_irfd>0 && !ir_flag)
    {
        connect (irthread,SIGNAL(ir_isDone(int)),this,SLOT(ir_dealDone(int)));
        printf("connect ir ok\n");
        irthread->start ();
        ir_flag = 1;

    }
    if(fd_led<=0)
    {
        init_led ();
        printf("init led ok\n");
    }
}

SmartHomeMainWindow::~SmartHomeMainWindow()
{
    delete ui;
}

void SmartHomeMainWindow::on_cameraBt_clicked()
{
    camera * myCamera = new camera();
    this->close();
    myCamera->show ();
}

void SmartHomeMainWindow::on_pushButton_clicked()
{
    AdcBeep *myadc = new AdcBeep();
    this->close();
    myadc->show ();
}

void SmartHomeMainWindow::on_recordBt_clicked()
{
    int rt = mian_record();
    if(!rt)
        qDebug()<<"shi bie ok";
}

void SmartHomeMainWindow::update_dht11()
{
    int rt = 0;
    unsigned char dht11_data[5] = {0};


    bzero(dht11_data,sizeof(dht11_data));

    rt = read(dht11_fd,dht11_data,sizeof(dht11_data));

    if(rt<0)
    {
        perror("read dht11 error:");
        //return;
    }
    else
    {
        printf("dht11 ok,temp=%d.%d,humi=%d.%d\r\n",dht11_data[2],dht11_data[3],dht11_data[0],dht11_data[1]);
        ui->templable->setText(QString("%1.%2°C").arg (dht11_data[2]).arg (dht11_data[3]));
        ui->humilable->setText(QString("%1.%2%").arg (dht11_data[0]).arg (dht11_data[1]));

    }
}

void SmartHomeMainWindow::ir_dealDone(int num)
{
    qDebug()<<"ir num:"<<num;
    //QString ir =  QString("%1").arg(num,2,16,QLatin1Char('0'));;

    /*if(num == 68)
    {
        ioctl(fd_led,GEC6818_LED1_ON,7);
       // ioctl(fd_led,GEC6818_LED2_ON,3);
        //ioctl(fd_led,GEC6818_LED3_ON,5);
        //ioctl(fd_led,GEC6818_LED4_ON,7);
    }
    else if(num == 64)
    {
        ioctl(fd_led,GEC6818_LED1_OFF,7);
       // ioctl(fd_led,GEC6818_LED2_OFF,4);
       // ioctl(fd_led,GEC6818_LED3_OFF,6);
       // ioctl(fd_led,GEC6818_LED4_OFF,8);
    }
    else
    {
        printf("ir error\n");
    }
*/
    switch(num)
    {
        case 68:
            if(!led_flag)
            {
                ioctl(fd_led,GEC6818_LED1_ON,7);
                led_flag = 1;
            }
            else
            {
                ioctl(fd_led,GEC6818_LED1_OFF,7);
                led_flag = 0;
            }
            break;
        case 64:
            if(!led4_flag)
            {
                ioctl(fd_led,GEC6818_LED4_ON,10);
                led4_flag = 1;
            }
            else
            {
                ioctl(fd_led,GEC6818_LED4_OFF,10);
                led4_flag = 0;
            }
            break;
        default:
            printf("no action\n");
            break;

    }
}
