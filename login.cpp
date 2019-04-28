#include "login.h"
#include "ui_login.h"
#include "QDebug"
#include "adcbeep.h"
#include "smarthomemainwindow.h"
#include <QMessageBox>
#include <QLatin1Char>
QString passwd_str;

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    passwd_str.clear ();

    this->rfid_fd = open("/dev/myrc522",O_RDWR);
    if(rfid_fd < 0)
    {
        perror("open rfid");
    }
    else
    {
        rfid_timer = new QTimer();
        connect(rfid_timer,SIGNAL(timeout()),this,SLOT(update_rfid()));
        rfid_timer->start(1000);
        qDebug()<<"open rfid ok";
    }

}

login::~login()
{
    delete ui;
}

void login::on_rfidbt_clicked()
{


}

void login::update_rfid()
{
    unsigned char card_writebuf[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    unsigned char card_readbuf[16]={0};
    int len;

    bzero(card_readbuf,sizeof(card_readbuf));
    len = write(rfid_fd,card_writebuf,16);

    if(len > 0)
    {

        printf("write len=%d\n",len);
    }

    //sleep(1);

    len = read(rfid_fd,card_readbuf,5);
    if(len > 0)
    {

        printf("read len=%d\n",len);
        for(int i=0; i<5; i++)
        {
            printf("%02X ",card_readbuf[i]);

        }
        printf("\n\n");
        ui->cardid_label->setText (QString("id:%1%2%3%4%5").arg (card_readbuf[0],2,16,QLatin1Char('0')).arg (card_readbuf[1],2,16,QLatin1Char('0')).arg (card_readbuf[2],2,16,QLatin1Char('0')).arg (card_readbuf[3],2,16,QLatin1Char('0')).arg (card_readbuf[4],2,16,QLatin1Char('0')));
    }
}

void login::on_bt1_clicked()
{
    passwd_str.append ("1");
    ui->passwd_Edit->setText (passwd_str);
}

void login::on_bt6_clicked()
{
    passwd_str.append ("6");
    ui->passwd_Edit->setText (passwd_str);

}

void login::on_bt2_clicked()
{
    passwd_str.append ("2");
    ui->passwd_Edit->setText (passwd_str);
}

void login::on_bt3_clicked()
{
    passwd_str.append ("3");
    ui->passwd_Edit->setText (passwd_str);
}

void login::on_bt4_clicked()
{
    passwd_str.append ("4");
    ui->passwd_Edit->setText (passwd_str);
}

void login::on_bt5_clicked()
{
    passwd_str.append ("5");
    ui->passwd_Edit->setText (passwd_str);
}

void login::on_bt7_clicked()
{
    passwd_str.append ("7");
    ui->passwd_Edit->setText (passwd_str);
}

void login::on_bt8_clicked()
{
    passwd_str.append ("8");
    ui->passwd_Edit->setText (passwd_str);
}

void login::on_bt9_clicked()
{
    passwd_str.append ("9");
    ui->passwd_Edit->setText (passwd_str);
}

void login::on_bt0_clicked()
{
    passwd_str.append ("0");
    ui->passwd_Edit->setText (passwd_str);
}

void login::on_delete_bt_clicked()
{
    passwd_str=passwd_str.left(passwd_str.length()-1);
    ui->passwd_Edit->setText(passwd_str);
}

void login::on_enter_bt_clicked()
{
    if(passwd_str=="1")
    {
        SmartHomeMainWindow *smarthome = new SmartHomeMainWindow();
        this->hide();
        smarthome->show ();
        rfid_timer->stop ();
    }
    else
    {
        QMessageBox::about(this,tr("提示信息"),tr("密码错误！请重新输入！"));
        ui->passwd_Edit->clear();
        passwd_str.clear();

    }
}
