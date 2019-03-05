/*
智能仓储串口通讯调试
*/

#include <stdio.h>      /*标准输入输出定义*/
#include <stdlib.h>     /*标准函数库定义*/
#include <unistd.h>     /*Unix 标准函数定义*/
#include <sys/types.h>  
#include <sys/stat.h>   
#include <fcntl.h>      /*文件控制定义*/
#include <termios.h>    /*PPSIX 终端控制定义*/
#include <errno.h>      /*错误号定义*/
#include <string.h> 
#include <strings.h> 

#define  USRT_DEV  "/dev/ttySAC1"

int main(int argc, char **argv)
{
    int fd;
    int ret;
	char wbuf[128];
	char rbuf[128];
	
   	//fd = open(USRT_DEV, O_RDWR|O_NOCTTY|O_NDELAY);
   	fd = open(USRT_DEV, O_RDWR);
	if(fd < 0)
	{
		perror("open uart fail!(hpy)\n");
		return -1;
	}
	
	if(fcntl(fd,F_SETFL,0) < 0)
	{
		perror("fcntl F_SETFL(hpy)\n");
	
	}
	
	struct  termios oldtio,options;
 	if(tcgetattr(fd,&oldtio) != 0) 
    {  
		perror("SetupSerial faile(hpy)\n");  
      	return -1;  
    }  
    bzero(&options, sizeof(options));  
    options.c_cflag  |=  CLOCAL | CREAD; //用于本地链接和接收使能，通过位掩码的方式激活 
    options.c_cflag  &= ~CSIZE; //字符长度掩码。取值为：CS5，CS6，CS7或CS8 
    
	cfsetispeed(&options,B115200);     /*设置为9600Bps*/
	cfsetospeed(&options,B115200);
	
	options.c_cflag |= CS8;      /*设置数据位数*/
	
	options.c_cflag &= ~PARENB;    /*设置无奇偶校验*/
	
	options.c_cflag &= ~CSTOPB;  /* 设置停止位1*/
	
	tcflush(fd,TCIFLUSH);       /* 改变在所有写入 fd 引用的对象的输出都被传输后生效，所有已接受但未读入的输入都在改变发生前丢弃*/
	options.c_cc[VTIME] = 0;     /* 非cannoical模式读时的延时*/   
	options.c_cc[VMIN] = 0; 
	if (tcsetattr(fd,TCSANOW,&options) != 0)  /* 改变立即发生 */  
	{ 
	    perror("SetupSerial 3[hpy]");   
	    return -1;  
	} 
	printf("SET  SAC1 success!!(hpy)\n");
	
	while(1)
	{
	
		memset(wbuf,0,128);
		fgets(wbuf,128,stdin);
		ret = write(fd,wbuf,strlen(wbuf));
		
		memset(rbuf,0,128);
		ret = read(fd,rbuf,128);
		if(ret < 0)
		{ 
			perror("read uart fail![hpy]\n");
			return -1;
		}
		printf("buf = %s\n",rbuf);			
	}

	close(fd);
	return 0;
}







