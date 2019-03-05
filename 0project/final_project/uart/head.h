#ifndef _HEAD_H_
#define _HEAD_H_



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h> 
#include <sys/stat.h>   
#include <fcntl.h>      /*文件控制定义*/
#include <termios.h>    /*PPSIX 终端控制定义*/
#include <errno.h>      /*错误号定义*/
#include <sys/select.h>

#define SIZE 128
#define PORT 6000
#define IP "192.168.1.30"//30是开发板上的ip


inline void sys_error(const char * str)
{
	perror(str );
	exit(1);
}


#endif
