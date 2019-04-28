/*************************************************
 File name : api_v4l2.c
 Create date : 2014-07-02 23:56
 Modified date : 2014-07-02 23:56
 Author : heqingde
 Email : hqd173@163.com
 
 ***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>           
#include <fcntl.h>            
#include <unistd.h>
#include <errno.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#include <pthread.h>

#include <asm/types.h>        
#include <linux/videodev2.h>

#include "api_v4l2.h"


//open device
void ApiV4l2::linux_v4l2_open_device ()
{
        struct stat st; 
        if (-1 == stat (camera_dev.c_str(), &st)) {
                fprintf (stderr, "Cannot identify '%s': %d, %s\n",
                         camera_dev.c_str(), errno, strerror (errno));
                exit (EXIT_FAILURE);
        }

        if (!S_ISCHR (st.st_mode)) {
                fprintf (stderr, "%s is no device\n", camera_dev.c_str());
                exit (EXIT_FAILURE);
        }

        fd = open (camera_dev.c_str(), O_RDWR /* required */ | O_NONBLOCK, 0);

        if (-1 == fd) {
                fprintf (stderr, "Cannot open '%s': %d, %s\n",
                         camera_dev.c_str(), errno, strerror (errno));
                exit (-1);
        }
}

int ApiV4l2::linux_v4l2_device_init(string dev)
{
	struct v4l2_capability cap;
	struct v4l2_format fmt;
	struct v4l2_streamparm *setfps;
	int ret = 0;
	char fmtstr[8];
	struct v4l2_queryctrl queryctrl;//l亮度信息
	struct v4l2_control control;//设置
	
    camera_dev = dev;
	
	//open the device
	linux_v4l2_open_device ();
	
	// 获取驱动信息
	ret = ioctl(fd, VIDIOC_QUERYCAP, &cap);
    if (ret < 0) {
        printf("VIDIOC_QUERYCAP failed (%d)\n", ret);
        return ret;
    }
    // Print capability infomations
    printf("Capability Informations:\n");
    printf(" driver: %s\n", cap.driver);
    printf(" card: %s\n", cap.card);
    printf(" bus_info: %s\n", cap.bus_info);
    printf(" version: %08X\n", cap.version);
    printf(" capabilities: %08X\n", cap.capabilities);

    // 获取视频格式
    memset(&fmt, 0, sizeof(struct v4l2_format));
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ret = ioctl(fd, VIDIOC_G_FMT, &fmt);
    if (ret < 0) {
        printf("***********************************\nVIDIOC_G_FMT failed (%d)\n", ret);
        return ret;
    }
    printf("Stream Format Informations:\n");
    printf(" type: %d\n", fmt.type);
    printf(" width: %d", fmt.fmt.pix.width);
    printf(" height: %d\n", fmt.fmt.pix.height);

    /*cisco  is not set format*/
#if STREAM_YUV
    // 设置视频格式
    fmt.type                = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width       = VIDEO_WIDTH;
    fmt.fmt.pix.height      = VIDEO_HEIGHT;
#if 1
    fmt.fmt.pix.width       = 640;
    fmt.fmt.pix.height      = 480;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;
#endif
    fmt.fmt.pix.field       = V4L2_FIELD_INTERLACED;
    ret = ioctl(fd, VIDIOC_S_FMT, &fmt);
    if (ret < 0)
    {
        printf("VIDIOC_S_FMT failed (%d)\n", ret);
           return ret;
    }


    // 获取视频格式
    ret = ioctl(fd, VIDIOC_G_FMT, &fmt);
    if (ret < 0) {
        printf("VIDIOC_G_FMT failed (%d)\n", ret);
        return ret;
    }
    // Print Stream Format
    printf("Stream Format Informations:\n");
    printf(" type: %d\n", fmt.type);
    printf(" width: %d     ", fmt.fmt.pix.width);
    printf(" height: %d\n", fmt.fmt.pix.height);

    memset(fmtstr, 0, 8);
    memcpy(fmtstr, &fmt.fmt.pix.pixelformat, 4);
    printf(" pixelformat: %s\n", fmtstr);
    printf(" field: %d\n", fmt.fmt.pix.field);
    printf(" bytesperline: %d\n", fmt.fmt.pix.bytesperline);
    printf(" sizeimage: %d\n", fmt.fmt.pix.sizeimage);
    printf(" colorspace: %d\n", fmt.fmt.pix.colorspace);
    printf(" priv: %d\n", fmt.fmt.pix.priv);
    printf(" raw_date: %s\n", fmt.fmt.raw_data);

#endif
#if 1
	//set frame number
    setfps=(struct v4l2_streamparm *) malloc(sizeof(struct v4l2_streamparm));
    if(setfps == NULL)
    {
        printf("malloc is error\n");
        return -1;
					
    }
    memset(setfps, 0, sizeof(struct v4l2_streamparm));
    setfps->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    //获取采集针频率信息
    ret = ioctl(fd, VIDIOC_G_PARM, setfps);
    if(ret == 0)
    {
        printf("\n  Frame rate:   %u/%u\n",
        setfps->parm.capture.timeperframe.denominator,
        setfps->parm.capture.timeperframe.numerator
        );
    }
    if (setfps->parm.capture.timeperframe.numerator == 1
	        && setfps->parm.capture.timeperframe.denominator == FPS)
    {
        printf("ok ,fps is aready the value we want \n"); /* OK ,fps is aready the value we want */
    }
    else
    {
        /* set framerate */
        setfps->parm.capture.timeperframe.numerator=1;
        setfps->parm.capture.timeperframe.denominator=FPS; //
        ret = ioctl(fd, VIDIOC_S_PARM, setfps);
        if(ret == -1)
        {
            perror("Unable to set frame rate");
            return ret;
        }
		ret = ioctl(fd, VIDIOC_G_PARM, setfps);
        if(ret == 0)
        {
            if (setfps->parm.capture.timeperframe.numerator != 1 ||setfps->parm.capture.timeperframe.denominator != FPS )
            {
                printf("\n  Frame rate:   %u/%u fps (requested frame rate %u fps is "
	                       "not supported by device)\n",
	                       setfps->parm.capture.timeperframe.denominator,
	                       setfps->parm.capture.timeperframe.numerator,
	                       FPS);
            }
            else
            {
                printf("\n  Frame rate:   %d fps\n", FPS);
            }
        }
        else
        {
            perror("Unable to read out current frame rate");
            return -1;
        }
    }
    free(setfps);
    printf("\nUSB CAM's output mode: %d \n", setfps->parm.output.outputmode);

	//亮度
    memset (&queryctrl, 0, sizeof (queryctrl));
    queryctrl.id = V4L2_CID_BRIGHTNESS;
    ret = ioctl (fd, VIDIOC_QUERYCTRL, &queryctrl);
    if(ret == -1)
    {
            if (queryctrl.flags & V4L2_CTRL_FLAG_DISABLED)
            {
                    printf("flag is error\n");
                    return -1;
            }
    }
    control.id = V4L2_CID_BRIGHTNESS;
    control.value = 200;
    ret = ioctl (fd, VIDIOC_S_CTRL, &control);
    if(-1 == ret)
    {
            printf("set brightness is error \n");
    }
#endif
	
    return 0;
}

int ApiV4l2::linux_v4l2_init_mmap()
{
	struct v4l2_requestbuffers reqbuf;
	struct v4l2_buffer buf;

	int ret = 0;
    // 请求分配内存
    printf("1111*************************\nrequesbuffers\n");
	reqbuf.count = BUFFER_COUNT;
	reqbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	reqbuf.memory = V4L2_MEMORY_MMAP;
	ret = ioctl(fd , VIDIOC_REQBUFS, &reqbuf);//分配内存
    if (4 == errno)
    {
        fprintf (stderr, "%s does not support "
                                 "memory mapping\n", camera_dev.c_str());
        return  (-1);
    }
    if (reqbuf.count < 2)
    {
        fprintf (stderr, "Insufficient buffer memory on %s\n",
                         camera_dev.c_str());
        return (EXIT_FAILURE);
    }
    unsigned int i = 0;
    for (i = 0; i < reqbuf.count; i++)
    {
        memset(&buf, 0, sizeof(struct v4l2_buffer));
        buf.index = i;
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        ret = ioctl(fd , VIDIOC_QUERYBUF, &buf);
        if(ret 	< 0)
		{
            printf("VIDIOC_QUERYBUF (%d) failed (%d)\n", i, ret);
            return ret;
        }

        // mmap buffer
        framebuf[i].length = buf.length;
        framebuf[i].start = (char *) mmap(NULL, buf.length, PROT_READ|PROT_WRITE, MAP_SHARED, fd, buf.m.offset);
        if (framebuf[i].start == MAP_FAILED) {
            printf("mmap (%d) failed: %s\n", i, strerror(errno));
            return -1;
        }
        // Queen buffer
        ret = ioctl(fd , VIDIOC_QBUF, &buf);
        if (ret < 0)
        {
            printf("VIDIOC_QBUF (%d) failed (%d)\n", i, ret);
            return -1;
        }
    }
    return 0;
}
int ApiV4l2::linux_v4l2_get_fream(FreamBuffer *freambuf_t)
{
	struct timeval tv;
	struct v4l2_buffer buf;
	fd_set fds; 
	int ret = 0;
	
	buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	buf.memory = V4L2_MEMORY_MMAP;
	
	//printf("starting transfer data...\nget anything char end zhe transfer...\n");
	FD_ZERO (&fds);
	FD_SET (fd, &fds);
	tv.tv_sec = 2 ;
	tv.tv_usec = 0;
			  
	ret = select (fd + 1, &fds, NULL, NULL, &tv);
    if (-1 == ret)
    {
        if (EINTR == errno)
            return 1;
    }
    if (0 == ret)
    {
        fprintf (stderr, "select timeout\n");
        return (-1);
    }
	//printf("starting transfer data...\nget anything char end zhe transfer...\n");
	 ret = ioctl(fd, VIDIOC_DQBUF, &buf);
	 if (ret < 0)
		{
			printf("VIDIOC_DQBUF failed (%d)\n", ret);
			return(-1);
		}
#if 1
	 memcpy(freambuf_t->buf, (char *)framebuf[buf.index].start, buf.bytesused);
//printf("buff %d,bytesused %d\n",buf.length,buf.bytesused);
	 freambuf_t->length = buf.bytesused;
	//printf("%d, %d \n",freambuf_t->length,  buf.bytesused);
#else
	memcpy(freambuf_t->buf, (char *)framebuf[buf.index].start, buf.length);
	 freambuf_t->length = buf.length;
#endif
		    //Re-queen buffer
	 ret = ioctl(fd, VIDIOC_QBUF, &buf);
			
	if (ret < 0) 
	{
		printf("VIDIOC_QBUF .................failed (%d)\n", ret);
		return (-1);
	}
	return 0;	
}

int ApiV4l2::linux_v4l2_start_capturing()
{
	
    enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	int ret = 0;

	ret =linux_v4l2_init_mmap();
	if(ret != 0)
        exit_error("mmap");

	//start capturing
    ret = ioctl(fd, VIDIOC_STREAMON, &type);
    if (ret < 0)
	{
	      printf("VIDIOC_STREAMON failed (%d)\n", ret);
	      return ret;
    }
    printf("staring is ok\n");
	return 0;
}

int ApiV4l2::linux_v4l2_stop_capturing()
{
	int ret = 0;
	int i=0;
	//停止视频的采集
	enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	 for (i=0; i<BUFFER_COUNT ; i++) 
	    {
	        munmap(framebuf[i].start, framebuf[i].length);
	    }
	ret = ioctl (fd, VIDIOC_STREAMOFF, &type);
	if (ret < 0) 
	{
        printf("VIDIOC_STREAMON failed (%d)\n", ret);
        return ret;
        }
	
   	return 0;
}

int ApiV4l2::linux_v4l2_device_uinit()
{

	close(fd);
	printf("Camera test Done.\n");
	return 0;
}

/**********************************************
*把yuyv数据转换为rgb格式
*picw为采集图片的宽,pich为高
***********************************************/
bool ApiV4l2::yuyv_to_rgb888(unsigned char *yuyvdata, unsigned char *rgbdata, int picw, int pich)
{
    int i, j;
    unsigned char y1,y2,u,v;
    int r1,g1,b1,r2,g2,b2;

    //确保所转的数据或要保存的地址有效
    if(yuyvdata == NULL || rgbdata == NULL)
    {
        return false;
    }

    int tmpw = picw/2;
    for(i=0; i<pich; i++)
    {
        for(j=0; j<tmpw; j++)
        {
            //获取每个像素yuyv数据
            y1 = *(yuyvdata + (i*tmpw+j)*4);
            u  = *(yuyvdata + (i*tmpw+j)*4+1);
            y2 = *(yuyvdata + (i*tmpw+j)*4+2);
            v  = *(yuyvdata + (i*tmpw+j)*4+3);

            //把yuyv数据转换为rgb数据
            r1 = y1 + 1.042*(v-128);
            g1 = y1 - 0.34414*(u-128);
            b1 = y1 + 1.772*(u-128);

            r2 = y2 + 1.042*(v-128);
            g2 = y2 - 0.34414*(u-128);
            b2 = y2 + 1.772*(u-128);

            if(r1 > 255) r1=255;
            else if(r1 < 0) r1 = 0;

            if(g1 > 255) g1=255;
            else if(g1 < 0) g1 = 0;

            if(b1 > 255) b1=255;
            else if(b1 < 0) b1 = 0;

            if(r2 > 255) r2=255;
            else if(r2 < 0) r2 = 0;

            if(g2 > 255) g2=255;
            else if(g2 < 0) g2 = 0;

            if(b2 > 255) b2=255;
            else if(b2 < 0) b2 = 0;

            //把rgb值保存于rgb空间 数据为反向
            rgbdata[((pich-1-i)*tmpw+j)*6]     = (unsigned char)b1;
            rgbdata[((pich-1-i)*tmpw+j)*6 + 1] = (unsigned char)g1;
            rgbdata[((pich-1-i)*tmpw+j)*6 + 2] = (unsigned char)r1;
            rgbdata[((pich-1-i)*tmpw+j)*6 + 3] = (unsigned char)b2;
            rgbdata[((pich-1-i)*tmpw+j)*6 + 4] = (unsigned char)g2;
            rgbdata[((pich-1-i)*tmpw+j)*6 + 5] = (unsigned char)r2;
        }
    }
    return true;
}


