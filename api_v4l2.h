/*************************************************
 File name : api_v4l2.h
 Create date : 2014-07-01 19:42
 Modified date : 2014-07-01 19:42
 Author : heqingde
 Email : hqd173@163.com
 
 ***********************************************/
#ifndef API_V4L2_H_
#define API_V4L2_H_

#define VIDEO_WIDTH  640
#define VIDEO_HEIGHT 480
#define MAX_CAM_RES 32 //camres res
#define BUFFER_COUNT 4 //buffer zone
#define FPS 30
#define MAX_CAM_RES 32

#define exit_error(s)\
	do{\
		printf("%s is error\n",s);\
		return (-1);\
		}while(0)


/*********************************
*  NAME:VideoBuffer  struct
*  Function: Describe buffer V4L2 driver assigns and maps
*  Member:  start: point of buffer
*  length: total length of buffer
**********************************/
typedef struct Video_Buffer
{
    void *start;
    int length;
}VideoBuffer;
/*******************************
*  nan=me :fream_buffer
*  Function: save fream
*  member: buf :point of buf
*  length:total length op buf
********************************/
typedef struct Fream_Buffer
{
    unsigned char buf[1843200];
	int length;
}FreamBuffer;

#define STREAM_YUV 1

#include <string>
#include <stdbool.h>
using namespace std;



class ApiV4l2
{
      string camera_dev;//保存设备名称
      int fd;//保存文件描述符
      VideoBuffer framebuf[BUFFER_COUNT];

public:
/*************************************
*		Name:open_device Function
*		Function:open the device
*/
void linux_v4l2_open_device();

/*************************************
*		name:device_init
*		Function:Initial Camera v4l2 
*/
int linux_v4l2_device_init(string dev);

/*************************************
*		name: init_mmap
*		Function: mmap 
*/
int linux_v4l2_init_mmap();

/************************************
*		name:start_capturing
*		Function: starting Capture Options 
*/
int linux_v4l2_start_capturing();

/************************************
*		name:stop_capturing
*		Function: stop Capture Options
*/
int linux_v4l2_stop_capturing();

/************************************
*		name :device_uinit
*		Function:uinit device
*/
int linux_v4l2_device_uinit();
/************************************
*		name :linux_v4l2_get_fream
*		Function:save device_stream data;
*/
int linux_v4l2_get_fream(FreamBuffer *freambuf);

bool yuyv_to_rgb888(unsigned char *yuyvdata, unsigned char *rgbdata, int picw, int pich);

};
#endif /*API_V4L2_H*/
