#include "irqthread.h"
#include "adcbeep.h"
int gloable_irfd = 0;
#define DEV_PATH   "/dev/input/event1"
IrQthread::IrQthread(QObject *parent) : QThread(parent)
{
    this->ir_fd = open(DEV_PATH,O_RDONLY);
    if(ir_fd <0)
    {
        perror(" Open ir");
    }
    else
    {
        printf("open ir ok\n");
        gloable_irfd = ir_fd;
    }
}

void IrQthread::run()
{
    int rt = 0;
    //按键按下释放会读取32个字节，其中第12字节为按键值
    char recv_buf[32];

    while(1)
    {
        bzero(recv_buf,sizeof(recv_buf));
        printf("wait data......\n");
        rt = read(ir_fd,recv_buf,sizeof(recv_buf));
        if(rt>0)
        {
            printf("recv_buf ir:%02X \n",recv_buf[12]);
            emit ir_isDone (recv_buf[12]);
        }
        else
        {
            perror("read ir error");
        }
    }
}
