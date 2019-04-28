//////////////////////////////////////////////////////////////////
//
//  Copyright(C), 2013-2017, GEC Tech. Co., Ltd.
//
//  File name: GPLE/common.c
//
//  Author: GEC
//
//  Date: 2017-01
//  
//  Description: 通用函数汇总
//
//
//////////////////////////////////////////////////////////////////



#include "common.h"


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

int music_flag = 0;
int fd_led = 0;
int sockfd = 0;
static struct timeval timeout;
/********************* 通用函数列表 *******************/

int Open(const char *pathname, int flag)
{
	int fd;
	while((fd=open(pathname, flag)) == -1 && errno == EINTR);

	if(fd == -1)
	{
		perror("open() failed");
		exit(0);
	}

	return fd;
}

ssize_t Write(int fildes, const void *buf, size_t nbyte)
{
	ssize_t n;
	size_t total = 0;

	char *tmp = (char *)buf;
	while(nbyte > 0)
	{
		while((n=write(fildes, tmp, nbyte)) == -1 &&
				errno == EINTR);

		if(n == -1)
		{
			perror("write() error");
			exit(0);
		}

		nbyte -= n;
		tmp += n;
		total += n;
	}

	return total;
}

ssize_t Read(int fildes, void *buf, size_t nbyte)
{
	ssize_t n;
	while((n=read(fildes, buf, nbyte)) == -1
			&& errno == EINTR);

	if(n == -1)
	{
		perror("read() failed");
		exit(0);
	}

	return n;
}


/********************* 网络函数列表 *******************/

int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
	int ret = bind(sockfd, addr, addrlen);
	if(ret == -1)
	{
		perror("bind() failed");
		exit(0);
	}

	return ret;
}

int Listen(int sockfd, int backlog)
{
	int ret = listen(sockfd, backlog);
	if(ret == -1)
	{
		perror("listen() failed");
		exit(0);
	}

	return ret;
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
	int connfd = accept(sockfd, addr, addrlen);
	if(connfd == -1)
	{
		perror("accept() failed");
		exit(0);
	}

	return connfd;
}

int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
	int ret = connect(sockfd, addr, addrlen);
	if(ret == -1)
	{
		perror("connect() failed");
		exit(0);
	}

	return ret;
}

int Socket(int domain, int type, int protocol)
{
	int sockfd = socket(domain, type, protocol);
	if(sockfd == -1)
	{
		perror("socket() error");
	}

	return sockfd;
}

int Setsockopt(int sockfd, int level, int optname,
	       const void *optval, socklen_t optlen)
{
	int retval = setsockopt(sockfd, level, optname, optval, optlen);
	if(retval == -1)
	{
		perror("setsockopt() error");
	}

	return retval;
}

int Select(int nfds, fd_set *readfds, fd_set *writefds,
	   fd_set *exceptfds, struct timeval *timeout)
{
	int n = select(nfds, readfds, writefds, exceptfds, timeout);
	if(n == -1)
	{
		perror("select() failed");
		exit(0);
	}

	return n;
}

int init_sock(const char *ubuntu_ip)
{
	struct sockaddr_in sin;
	int sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	int on = 1;
	Setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(1));
	
	//连接到虚拟机中
	bzero((char *) &sin, sizeof(sin));
	sin.sin_family = AF_INET;
	inet_pton(AF_INET, ubuntu_ip, &sin.sin_addr);
	sin.sin_port = htons(DEF_PORT);
	
	Connect(sockfd, (struct sockaddr *)&sin, sizeof(sin));
	printf("connected.\n");

	return sockfd;
}


void send_pcm(int sockfd, char *pcmfile)
{
	// 打开PCM文件
	int fd = Open(pcmfile, O_RDONLY);

	// 取得PCM数据的大小
	off_t pcm_size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);

	// 读取PCM数据
	char *pcm = calloc(1, pcm_size);
	Read(fd, pcm, pcm_size);

	// 将PCM发送给语音识别引擎系统
	int m = Write(sockfd, pcm, pcm_size);
	printf("%d bytes has been write into socket!\n", m);

	free(pcm);
}

xmlChar *wait4id(int sockfd)
{
	int ret = 0;
	fd_set sock_fd;
	
	FD_ZERO(&sock_fd);
	FD_SET(sockfd,&sock_fd);
	//5秒超时
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;
	
	
	ret = select(sockfd + 1,&sock_fd, NULL,NULL,&timeout);// select 出错返回-1 select 超时返回0
	printf("set time out ok.\n");
	if(ret<0)
		return NULL;
	
	//calloc动态分配完内存后，自动初始化该内存空间为零
	//申请XMLSIZE大小的内存空间
	char *xml = calloc(1, XMLSIZE);

	// 从ubuntu接收XML结果
	int n = Read(sockfd, xml, XMLSIZE);
	
	printf("%d bytes has been recv from ubuntu.\n", n);
	
	// 接收XML结果写入本地文件 XMLFILE 中
	FILE *fp = fopen(XMLFILE, "w");
	if(fp == NULL)
	{
		perror("fopen() failed");
		exit(0);
	}

	size_t m = fwrite(xml, 1, n, fp);
	if(m != n)
	{
		perror("fwrite() failed");
		exit(0);
	}

	//强迫将缓冲区内的数据写回参数fp指定的文件中
	fflush(fp);

	//解析XMLFILE文件
	return parse_xml(XMLFILE);
}


/********************* XML函数列表 *******************/

xmlChar *__get_cmd_id(xmlDocPtr doc, xmlNodePtr cur)
{
	xmlChar *key, *id;
	cur = cur->xmlChildrenNode;
	while (cur != NULL)
	{
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"cmd")))
	    {
			//获取字符串
		    key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		    printf("cmd: %s\n", key);
		    xmlFree(key);

			//读取节点属性
		    id = xmlGetProp(cur, (const xmlChar *)"id");
		    printf("id: %s\n", id);

		    xmlFree(doc);
		    return id;
 	    }
		cur = cur->next;
	}
	//释放文档指针
	xmlFree(doc);
    return NULL;
}

xmlChar *parse_xml(char *xmlfile)
{
	xmlDocPtr doc;
	xmlNodePtr cur1, cur2;

	//分析一个xml文件，并返回一个xml文档的对象指针
	doc = xmlParseFile(xmlfile);
	if (doc == NULL)
	{
		fprintf(stderr,"Document not parsed successfully. \n");
		return NULL;
	}
	
	//获得文档的根节点
	cur1 = xmlDocGetRootElement(doc);
	if(cur1 == NULL)
	{
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return NULL;
	}

	if(xmlStrcmp(cur1->name, (const xmlChar *)"nlp"))
	{
		fprintf(stderr,"document of the wrong type, root node != nlp");
		xmlFreeDoc(doc);
		return NULL;
	}
	
	cur1 = cur1->xmlChildrenNode;

	while (cur1 != NULL)
	{
		if ((!xmlStrcmp(cur1->name, (const xmlChar *)"result")))
		{
			cur2 = cur1->xmlChildrenNode;
			while(cur2 != NULL)
			{
				if((!xmlStrcmp(cur2->name, (const xmlChar *)"confidence")))
				{
					xmlChar *key = xmlNodeListGetString(doc, cur2->xmlChildrenNode, 1);
					if(atoi((char *)key) < 30)
					{
						xmlFree(doc);
						fprintf(stderr, "sorry, I'm NOT sure what you say.\n");
						return NULL;
						
					}
				}
				
				if((!xmlStrcmp(cur2->name, (const xmlChar *)"object")))
				{
					return __get_cmd_id(doc, cur2);
				}
				cur2 = cur2->next;
			}
		}
		cur1 = cur1->next;
	}

	//释放文档指针
	xmlFreeDoc(doc);
	return NULL;
}


int play_music(const char *pathname)
{
	int pid;

	char play_command[100];
	
	//字符串格式化：madplay 路径名 &
	//&：程序后台播放
	sprintf(play_command,"madplay %s & \n",pathname);
	
	//创建子进程
	pid = fork();
	
	//子进程ID为0
	if(pid == 0)
	{
		//播放音乐
		system(play_command);
		
		//播放后，子进程退出
		exit(0);
	}

	return 0;

}


void speech_recognition(int num)
{
	
	switch(num)
	{
		case 1:
			printf("开窗!\n");
			play_music("/gdou_iot/mp3/ok.mp3");
			break;
		case 2:
			printf("开门!\n");
			play_music("/gdou_iot/mp3/ok.mp3");
			break;
		case 3:
			printf("开灯!\n");
			play_music("/gdou_iot/mp3/ok.mp3");
			ioctl(fd_led,GEC6818_LED1_ON,7);
			ioctl(fd_led,GEC6818_LED2_ON,8);
			break;
		case 4:
			printf("关窗!\n");
			play_music("/gdou_iot/mp3/ok.mp3");
			break;
		case 5:
			printf("关门!\n");
			play_music("/gdou_iot/mp3/ok.mp3");
			break;
		case 6:
			printf("关灯!\n");
			play_music("/gdou_iot/mp3/ok.mp3");
			ioctl(fd_led,GEC6818_LED1_OFF,7);
			ioctl(fd_led,GEC6818_LED2_OFF,8);
			break;
		case 7:
			if(!music_flag)
			{
				play_music("/gdou_iot/mp3/master.mp3");
				music_flag = 1;
			}
			else
			{
				system("killall -9 madplay");
				play_music("/gdou_iot/mp3/master.mp3");
			}
			break;
		case 8:
			if(!music_flag)
			{
				play_music("/gdou_iot/mp3/meihuo.mp3");
				music_flag = 1;
			}
			else
			{
				system("killall -9 madplay");
				play_music("/gdou_iot/mp3/meihuo.mp3");
			}
			break;
		case 9:
		
			if(!music_flag)
			{
				play_music("/gdou_iot/mp3/qijizaixian.mp3");
				music_flag = 1;
			}
			else
			{
				system("killall -9 madplay");
				play_music("/gdou_iot/mp3/qijizaixian.mp3");
			}
			break;
		case 10:
			if(!music_flag)
			{
				play_music("/gdou_iot/mp3/qingtian.mp33");
				music_flag = 1;
			}
			else
			{
				system("killall -9 madplay");
				play_music("/gdou_iot/mp3/qingtian.mp3");
			}
			break;
		case 999:
			printf("bye-bye!\n");	
			if(music_flag)
			{
				system("killall -9 madplay");
				music_flag = 0;
			}
			play_music("/gdou_iot/mp3/ok.mp3");
			break;
		default:
			if(music_flag)
			{
				system("killall -9 madplay");
				play_music("/gdou_iot/mp3/sorry.mp3");
			}
			else
				play_music("/gdou_iot/mp3/sorry.mp3");
			break;
		
		
	}
	
	
}

int init_led()
{
	
	int fd = open("/dev/myled",O_RDWR);
	if(fd < 0)
	{
		perror("open led");
	}
	else
	{
        ioctl(fd,GEC6818_LED1_OFF,7);
        ioctl(fd,GEC6818_LED2_OFF,8);
        ioctl(fd,GEC6818_LED3_OFF,9);
        ioctl(fd,GEC6818_LED4_OFF,10);
        printf("open leddrv ok ,close led %d\n",fd);

        fd_led = fd;
        //return fd;
	}
	
}

//int main(int argc, char const *argv[]) // ./wav2pcm ubuntu-IP
int mian_record()
{
    int id_num=0;
	/*if(argc != 2)
	{
        printf("Usage: %s <ubuntu-IP>\n", argv[0]);
		exit(0);
	}*/
    if(fd_led<=0)
    {


        init_led();
        printf("init led_fd\n");
    }
	
    if(sockfd<=0)
    {
        //由命令行传入一个对方的IP 等效于socket+bind+listen+accept
        sockfd = init_sock("192.168.6.134");
        printf("init sockfd \n");
    }

    // 1，调用arecord来录一段音频
    printf("please press enter to start record in 3s...\n");

    //scanf("%d",&num);//可以修改为getc

    getchar();

    //启动录音
    system(REC_CMD);

    // 2，将录制好的PCM音频发送给语音识别引擎
    send_pcm(sockfd, PCM_FILE);

    // 3，等待对方回送识别结果（字符串ID）
    xmlChar *id = wait4id(sockfd);
    if(id == NULL)
    {
        printf("wait for id fail!\n");
        if(music_flag)
        {
            system("killall -9 madplay");
            play_music("/gdou_iot/mp3/sorry.mp3");
            music_flag = 0;
        }
        else
        {
            play_music("/gdou_iot/mp3/sorry.mp3");
        }
        //continue;
        return -1;
    }


    //将字符串的id转化成为整形的id
    id_num=atoi((char *)id);

    printf("id: %d\n",id_num);

    speech_recognition(id_num);

	
	return 0;
}










/*************************串口相关函数*****************************/
/* 设置窗口参数:9600速率 */
void init_tty(int fd)
{    
	//声明设置串口的结构体
	struct termios termios_new;
	//先清空该结构体
	bzero( &termios_new, sizeof(termios_new));
	//	cfmakeraw()设置终端属性，就是设置termios结构中的各个参数。
	cfmakeraw(&termios_new);
	//设置波特率
	//termios_new.c_cflag=(B9600);
	cfsetispeed(&termios_new, B9600);
	cfsetospeed(&termios_new, B9600);
	//CLOCAL和CREAD分别用于本地连接和接受使能，因此，首先要通过位掩码的方式激活这两个选项。    
	termios_new.c_cflag |= CLOCAL | CREAD;
	//通过掩码设置数据位为8位
	termios_new.c_cflag &= ~CSIZE;
	termios_new.c_cflag |= CS8; 
	//设置无奇偶校验
	termios_new.c_cflag &= ~PARENB;
	//一位停止位
	termios_new.c_cflag &= ~CSTOPB;
	tcflush(fd,TCIFLUSH);
	// 可设置接收字符和等待时间，无特殊要求可以将其设置为0
	termios_new.c_cc[VTIME] = 10;
	termios_new.c_cc[VMIN] = 1;
	// 用于清空输入/输出缓冲区
	tcflush (fd, TCIFLUSH);
	//完成配置后，可以使用以下函数激活串口设置
	if(tcsetattr(fd,TCSANOW,&termios_new) )
		printf("Setting the serial1 failed!\n");
}
void uart_send_data(int fd,int id_num)
{
	switch(id_num)
	{
		case 1:Write(fd,"open windows",20);
			break;
		case 2:Write(fd,"open door",20);
			break;
		case 3:Write(fd,"open led",20);
			break;
		case 4:Write(fd,"close windows",20);
			break;	
		case 5:Write(fd,"close door",20);
			break;
		case 6:Write(fd,"close led",20);
			break;
		default:
			break;	
	}
}

/**************************UDP通信相关**********************************/

void send_data_to_8266(int id_num)
{
	int sockfd;
	/*客户程序开始建立sockfd描述符*/
	if((sockfd = socket(AF_INET,SOCK_DGRAM,0)) ==-1)
	{
		printf("socket error\n");
		exit(1);
	}
	
	struct sockaddr_in r_addr;
	bzero(&r_addr,sizeof(struct sockaddr_in));	/*将结构体里数据全部置0*/
	r_addr.sin_family = AF_INET;				/*结构体成员赋初值*/
	r_addr.sin_addr.s_addr = inet_addr("255.255.255.255");//广播发送信息到这个网段
	r_addr.sin_port = htons(10086);

	int on=1;
	setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&on,sizeof(on));
	//设置socket为可广播模式。

	switch(id_num)
	{
		case 1:sendto(sockfd,"open windows",20,0,(struct sockaddr *)&r_addr,sizeof(struct sockaddr_in));
			printf("open windows\n");
			break;
		case 2:sendto(sockfd,"open door",20,0,(struct sockaddr *)&r_addr,sizeof(struct sockaddr_in));
			printf("open door\n");
			break;
		case 3:sendto(sockfd,"open led",20,0,(struct sockaddr *)&r_addr,sizeof(struct sockaddr_in));
			printf("open led\n");
			break;
		case 4:sendto(sockfd,"close windows",20,0,(struct sockaddr *)&r_addr,sizeof(struct sockaddr_in));
			printf("close windows\n");
			break;	
		case 5:sendto(sockfd,"close door",20,0,(struct sockaddr *)&r_addr,sizeof(struct sockaddr_in));
			printf("close door\n");
			break;
		case 6:sendto(sockfd,"close led",20,0,(struct sockaddr *)&r_addr,sizeof(struct sockaddr_in));
			printf("close led\n");
			break;
		default:
			break;	
	}

}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
