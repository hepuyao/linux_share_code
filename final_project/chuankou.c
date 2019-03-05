#include<stdio.h>      
#include<stdlib.h>     
#include<unistd.h>     /*Unix 标准函数定义*/  
#include<sys/types.h>   
#include<sys/stat.h>     
#include<fcntl.h>      /*文件控制定义*/  
#include<termios.h>    /*PPSIX 终端控制定义*/  
#include<errno.h>      /*错误号定义*/  
#include<string.h>  

#define DEV_NAME  "/dev/ttyUSB0"

/************************************************
UART_Set 设置串口的数据
baudrate表示波特率
databit表示数据位
parity表示奇偶位
stopbit表示停止位
***********************************************/
int UART_Set(int fd,int baudrate,int databit,int parity,int stopbit)
{
	struct termios newtio,oldtio;  
    if(tcgetattr(fd,&oldtio) != 0) 
    {  
		perror("SetupSerial faile\n");  
      	return -1;  
    }  
    bzero(&newtio, sizeof(newtio));  
    newtio.c_cflag  |=  CLOCAL | CREAD; //CLOCAL:忽略modem控制线  CREAD：打开接受者  
    newtio.c_cflag  &= ~CSIZE; //字符长度掩码。取值为：CS5，CS6，CS7或CS8  
  
    switch(databit)  
    {  
   		case 7:  
       		newtio.c_cflag |= CS7;  
        	break; 
     
    	case 8:  
       		newtio.c_cflag |= CS8;  
     		break;  
     }  
     
	switch(parity)  
     {  
		case 'O':  
    		newtio.c_cflag |= PARENB; //允许输出产生奇偶信息以及输入到奇偶校验  
        	newtio.c_cflag |= PARODD;  //输入和输出是奇及校验  
        	newtio.c_iflag |= (INPCK | ISTRIP); // INPACK:启用输入奇偶检测；ISTRIP：去掉第八位  
        	break;
          
    	case 'E':  
        	newtio.c_iflag |= (INPCK | ISTRIP);  
      	    newtio.c_cflag |= PARENB;  
        	newtio.c_cflag &= ~PARODD;  
         	break;
          
    	case 'N':   
        	newtio.c_cflag &= ~PARENB;  
        	break;  
     }  
  
    switch(baudrate)  
    {  
		case 2400:  
			cfsetispeed(&newtio, B2400);  
    		cfsetospeed(&newtio, B2400);  
   			break;
   			    
    	case 4800:  
      		cfsetispeed(&newtio, B4800);  
      		cfsetospeed(&newtio, B4800);  
      		break;
        
		case 9600:  
      		cfsetispeed(&newtio, B9600);  
      		cfsetospeed(&newtio, B9600);  
      		break;
      		  
		case 115200:  
      		cfsetispeed(&newtio, B115200);  
      		cfsetospeed(&newtio, B115200);  
    		break;
    		  
		case 460800:  
      		cfsetispeed(&newtio, B460800);  
      		cfsetospeed(&newtio, B460800);  
      		break;
      		  
    	default:  
      		cfsetispeed(&newtio, B9600);  
        	cfsetospeed(&newtio, B9600);  
      		break;  
     }  
  
	if(stopbit == 1) 
	 	newtio.c_cflag &=  ~CSTOPB; //CSTOPB:设置两个停止位，而不是一个 
    else if (stopbit == 2)  
		newtio.c_cflag |=  CSTOPB;  
       
    newtio.c_cc[VTIME]  = 0; //VTIME:非cannoical模式读时的延时，以十分之一秒位单位  
    newtio.c_cc[VMIN] = 0; //VMIN:非canonical模式读到最小字符数  
    tcflush(fd,TCIFLUSH); // 改变在所有写入 fd 引用的对象的输出都被传输后生效，所有已接受但未读入的输入都在改变发生前丢弃。  
    if((tcsetattr(fd,TCSANOW,&newtio))!=0) //TCSANOW:改变立即发生  
    {  
     	perror("com set error");  
     	return -1;  
    }  
    printf("set done!\n\r");  
    return 0; 
}


int main(int argc,char *argv[])
{
	int fd1,len,ret,reg_val;
	char buf[100] = "helloworld!";
	char buf1[100];
	fd1 = open(DEV_NAME,O_RDWR|O_NOCTTY|O_NDELAY);
	if(fd1 < 0)
	{
		perror("open uart fail!\n");
		return -1;
	}
	reg_val = UART_Set(fd1, 9600, 8, 'N', 1);  
    if (reg_val == -1)
    {
    	perror("UART_Set fail!\n");
    	return -1;
    }  
    printf("SET  SAC0 success!!\n");
      
    printf("enter the loop!!\n");  
	while(1)
	{
		memset(buf1,0,sizeof(buf1));
		len = write(fd1,buf,100);
		if(len < 0)
		{
			perror("write uart fail!\n");
			return -1;
		}

		ret = read(fd1,buf1,100);
		if(ret < 0)
                {
			perror("read uart fail!\n");
			return -1;
		}
		printf("buf = %s\n",buf1);
		sleep(1);
	}
	close(fd1);
	return 0;
}

























































