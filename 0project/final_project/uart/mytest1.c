/*
智能仓储串口通讯调试
*/


#include "mo.h"
#include "head.h"

#define  USRT_DEV  "/dev/ttyUSB0"

message_t m0cmd_send;
int rd_len = 0; //记录已经读取了多少个字节
int msg_len =36; //需要读取多少个字节
int len = 0; //本次读了多少个字节
char read_buf[36];


#if(0)
int serial_init(int fd)
{

	  struct  termios oldtio,options;
	  if(tcgetattr(fd,&oldtio) != 0) 
	  {  
		  perror("SetupSerial faile\n");  
		  return -1;  
	  }  
	//	bzero(&options, sizeof(options)); 
	  options=oldtio;
	  cfmakeraw(&options);
	  options.c_cflag  |=  CLOCAL | CREAD; //用于本地链接和接收使能，通过位掩码的方式激活 
	  options.c_cflag  &= ~CSIZE; //字符长度掩码。取值为：CS5，CS6，CS7或CS8 
	  
	  cfsetispeed(&options,B115200);	 /*设置为9600Bps*/
	  cfsetospeed(&options,B115200);
	  
	  options.c_cflag |= CS8;	   /*设置数据位数*/
	  
	  options.c_cflag &= ~PARENB;	 /*设置无奇偶校验*/
	  
	  options.c_cflag &= ~CSTOPB;  /* 设置停止位1*/
	  
	  
	  options.c_cc[VTIME] = 0;	   /* 非cannoical模式读时的延时*/	
	  options.c_cc[VMIN] = 1; 
	  tcflush(fd,TCIFLUSH); 	  /* 改变在所有写入 fd 引用的对象的输出都被传输后生效，所有已接受但未读入的输入都在改变发生前丢弃*/
	  if (tcsetattr(fd,TCSANOW,&options) != 0)	/* 改变立即发生 */  
	  { 
		  perror("SetupSerial 3");	 
		  return -1;  
	  } 
	  printf("SET  SAC1 success!!\n");
}

int read_msg(int fd)
{
	memset(read_buf,0,36);

	do 
	{
		len = read(fd,&read_buf[rd_len],1);
		rd_len += len;
		if(len <= 0)
		{
			return 0;
		}
		if(rd_len==msg_len)
		{
			printf("%02x\n",read_buf[rd_len-1]);
		}
		else
		{
			printf("%02x ",read_buf[rd_len-1]);
		}
	}while(rd_len < msg_len);


}


void ONSpeakerComd(int fd)
{
	
	memset(&m0cmd_send,0,sizeof(message_t));
	m0cmd_send.tag = command_tag_t;
	m0cmd_send.slave_address = 1;
	m0cmd_send.data_length = 36;
	m0cmd_send.data.command.operate_id = on_speaker;
	write(fd,&m0cmd_send,36);

}
void OFFSpeakerComd(int fd)
{	
	memset(&m0cmd_send,0,sizeof(message_t));
	m0cmd_send.tag = command_tag_t;
	m0cmd_send.slave_address = 1;
	m0cmd_send.data_length = 36;
	m0cmd_send.data.command.operate_id = off_speaker;
	write(fd,&m0cmd_send,36);
}
void ONLed1Comd(int fd)
{
	memset(&m0cmd_send,0,sizeof(message_t));
	m0cmd_send.tag = command_tag_t;
	m0cmd_send.slave_address = 1;
	m0cmd_send.data_length = 36;
	m0cmd_send.data.command.operate_id = on_led1;
	write(fd,&m0cmd_send,36);
}
void OFFLed1Comd(int fd)
{
	memset(&m0cmd_send,0,sizeof(message_t));
	m0cmd_send.tag = command_tag_t;
	m0cmd_send.slave_address = 1;
	m0cmd_send.data_length = 36;
	m0cmd_send.data.command.operate_id = off_led1;
	write(fd,&m0cmd_send,36);

}
void ONFanComd(int fd)
{
	memset(&m0cmd_send,0,sizeof(message_t));
	m0cmd_send.tag = command_tag_t;
	m0cmd_send.slave_address = 1;
	m0cmd_send.data_length = 36;
	m0cmd_send.data.command.operate_id = on_fan;
	write(fd,&m0cmd_send,36);

}
void OFFFanComd(int fd)
{
	memset(&m0cmd_send,0,sizeof(message_t));
	m0cmd_send.tag = command_tag_t;
	m0cmd_send.slave_address = 1;
	m0cmd_send.data_length = 36;
	m0cmd_send.data.command.operate_id = off_fan;
	write(fd,&m0cmd_send,36);
}
void ONSEVENLedComd(int fd)
{
	memset(&m0cmd_send,0,sizeof(message_t));
	m0cmd_send.tag = command_tag_t;
	m0cmd_send.slave_address = 1;
	m0cmd_send.data_length = 36;
	m0cmd_send.data.command.operate_id = on_seven_led;
	write(fd,&m0cmd_send,36);
}
void OFFSEVENLedComd(int fd)
{
	
	memset(&m0cmd_send,0,sizeof(message_t));
	m0cmd_send.tag = command_tag_t;
	m0cmd_send.slave_address = 1;
	m0cmd_send.data_length = 36;
	m0cmd_send.data.command.operate_id = off_seven_led;
	write(fd,&m0cmd_send,36);

}
#endif

int main(int argc, char **argv)
{
    int fd;	
   	fd = open(USRT_DEV, O_RDWR|O_NOCTTY|O_NDELAY);
	if(fd < 0)
	{
		perror("open uart fail!\n");
		return -1;
	}
	
	if(fcntl(fd,F_SETFL,0) < 0)
	{
		perror("fcntl F_SETFL\n");
	
	}
	
	 struct  termios oldtio,options;
	 if(tcgetattr(fd,&oldtio) != 0) 
	  {  
		  perror("SetupSerial faile\n");  
		  return -1;  
	  }  
	//	bzero(&options, sizeof(options)); 
	  options=oldtio;
	  cfmakeraw(&options);
	  options.c_cflag  |=  CLOCAL | CREAD; //用于本地链接和接收使能，通过位掩码的方式激活 
	  options.c_cflag  &= ~CSIZE; //字符长度掩码。取值为：CS5，CS6，CS7或CS8 
	  
	  cfsetispeed(&options,B115200);	 /*设置为9600Bps*/
	  cfsetospeed(&options,B115200);
	  
	  options.c_cflag |= CS8;	   /*设置数据位数*/
	  
	  options.c_cflag &= ~PARENB;	 /*设置无奇偶校验*/
	  
	  options.c_cflag &= ~CSTOPB;  /* 设置停止位1*/
	  
	  
	  options.c_cc[VTIME] = 0;	   /* 非cannoical模式读时的延时*/	

	  options.c_cc[VMIN] = 1; 
	  tcflush(fd,TCIFLUSH); 	  /* 改变在所有写入 fd 引用的对象的输出都被传输后生效，所有已接受但未读入的输入都在改变发生前丢弃*/
	  if (tcsetattr(fd,TCSANOW,&options) != 0)	/* 改变立即发生 */  
	  { 
		  perror("SetupSerial 3");	 
		  return -1;  
	  } 
	  printf("SET  SAC1 success!!\n");


	
	int fd_sock;
	char buf[36];
	int ret;
	
	fd_sock= socket(AF_INET,SOCK_STREAM,0);
	if(fd_sock < 0)
	sys_error("socket failed");
	
	struct sockaddr_in ser;
	ser.sin_family = AF_INET;
	ser.sin_port = htons(PORT);
	ser.sin_addr.s_addr = inet_addr("192.168.1.147");
	//ser.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if(bind(fd_sock,(struct sockaddr *)&ser,sizeof(ser)) < 0)
	sys_error("bind fialed");
	
	if(listen(fd_sock,5) < 0)
		sys_error("listen failed");

	int maxfd=-1,newfd=-1,tmp=-1;
	fd_set r_set;//定义一个读集合
	
	
	while(1)
		{
			FD_ZERO(&r_set);
			FD_SET(fd,&r_set);//将USB0加入到读集合中
			FD_SET(fd_sock,&r_set);//将套接字加入到读集合中
			
			if(fd>fd_sock)
			{
				maxfd = fd;
			}
			else
			{
				maxfd=fd_sock;
			}
			if(maxfd < newfd)
			{
				FD_SET(newfd,&r_set);	//将新连接的客户端文件描述符加入到读集合中
				maxfd = newfd;
			}
	
			if((tmp = select(maxfd+1,&r_set,NULL,NULL,NULL)) < 0)
				sys_error("select failed");
	
			else if(tmp > 0)
			{

				if(FD_ISSET(fd,&r_set))//判断USB是否有响应
				{
				QGZ:	rd_len=0;
					memset(read_buf,0,36);
					do 
					{
						len = read(fd,&read_buf[rd_len],1);
						rd_len += len;
						if(len <= 0)
						{
							return 0;
						}
						if(rd_len==msg_len)
						{
							printf("%02x\n",read_buf[rd_len-1]);
						}
						else
						{
							if(read_buf[0]==0xbb)
							{
								printf("%02x ",read_buf[rd_len-1]);
							}
							else
							{
								goto QGZ;
							}
						}
					}while(rd_len < msg_len);
				}
				
			 //判断socket是否响应
				if(FD_ISSET(fd_sock,&r_set))
				{
					if((newfd=accept(fd_sock,NULL,NULL)) < 0)
						sys_error("accept failed");
	
					printf("new client accepted\n");
				}
				//二次判断，判断客户端是否有数据
				if(FD_ISSET(newfd,&r_set))
				{
					int ret;
					ret = read(newfd,buf,36);
					if(ret < 0)
						sys_error("read failed");
					else if(ret == 0)
					{
						FD_CLR(newfd,&r_set); 
						newfd = -1;
						close(newfd);
					}
					else
					{
						//printf("data from client ^_^  %s",buf);
							
						switch(buf[0])
						{
							case 'a':
							memset(&m0cmd_send,0,sizeof(message_t));
							m0cmd_send.tag = command_tag_t;
							m0cmd_send.slave_address = 1;
							m0cmd_send.data_length = 36;
							m0cmd_send.data.command.operate_id = on_fan;
							write(fd,&m0cmd_send,36);
							printf("on_fan\n");
							break;
							
							case 'A':
							memset(&m0cmd_send,0,sizeof(message_t));
							m0cmd_send.tag = command_tag_t;
							m0cmd_send.slave_address = 1;
							m0cmd_send.data_length = 36;
							m0cmd_send.data.command.operate_id = off_fan;
							write(fd,&m0cmd_send,36);
						//	printf("off_fan\n");
							break;
							
							case 'b':
							memset(&m0cmd_send,0,sizeof(message_t));
							m0cmd_send.tag = command_tag_t;
							m0cmd_send.slave_address = 1;
							m0cmd_send.data_length = 36;
							m0cmd_send.data.command.operate_id = on_seven_led;
							write(fd,&m0cmd_send,36);
						//	printf("on_seven_led\n");
							break;
										
							case 'B':
							memset(&m0cmd_send,0,sizeof(message_t));
							m0cmd_send.tag = command_tag_t;
							m0cmd_send.slave_address = 1;
							m0cmd_send.data_length = 36;
							m0cmd_send.data.command.operate_id = off_seven_led;
							write(fd,&m0cmd_send,36);
						//	printf("off_seven_led\n");
							break;

							case 'c':
							memset(&m0cmd_send,0,sizeof(message_t));
							m0cmd_send.tag = command_tag_t;
							m0cmd_send.slave_address = 1;
							m0cmd_send.data_length = 36;
							m0cmd_send.data.command.operate_id = on_speaker;
							write(fd,&m0cmd_send,36);
							break;
							
							case 'C':
							memset(&m0cmd_send,0,sizeof(message_t));
							m0cmd_send.tag = command_tag_t;
							m0cmd_send.slave_address = 1;
							m0cmd_send.data_length = 36;
							m0cmd_send.data.command.operate_id = off_speaker;
							write(fd,&m0cmd_send,36);
							break;
							
							case 'd':
							memset(&m0cmd_send,0,sizeof(message_t));
							m0cmd_send.tag = command_tag_t;
							m0cmd_send.slave_address = 1;
							m0cmd_send.data_length = 36;
							m0cmd_send.data.command.operate_id = on_led1;
							write(fd,&m0cmd_send,36);
							break;
							
							case 'D':
							memset(&m0cmd_send,0,sizeof(message_t));
							m0cmd_send.tag = command_tag_t;
							m0cmd_send.slave_address = 1;
							m0cmd_send.data_length = 36;
							m0cmd_send.data.command.operate_id = off_led1;
							write(fd,&m0cmd_send,36);
							break;
							default:
							break;
								
						}
					}
				}
				
			}
		}
	close (fd_sock);
	close (newfd);
	close (fd);
	return 0;
}







