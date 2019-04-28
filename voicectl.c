#include "common.h"
#include <unistd.h>
#define REC_CMD  "arecord -d3 -c1 -r16000 -traw -fS16_LE cmd.pcm"
#define PCM_FILE "./cmd.pcm"

int music_flag = 0;
int fd_led = 0;
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
		return fd;
	}
	
}

//int main(int argc, char const *argv[]) // ./wav2pcm ubuntu-IP
int mian_record()
{
	int id_num=0,num;
	/*if(argc != 2)
	{
		printf("Usage: %s <ubuntu-IP>\n", argv[0]);
		exit(0);
	}*/
	
	//由命令行传入一个对方的IP 等效于socket+bind+listen+accept
	int sockfd = init_sock("192.168.6.134"); 

	fd_led = init_led();
	
	while(1)
	{
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
			continue;
			//return -1;
		}
			
		
		//将字符串的id转化成为整形的id
		id_num=atoi((char *)id);
		
		printf("id: %d\n",id_num);
		
		speech_recognition(id_num);

	}
	close(sockfd);
	
	return 0;
}


