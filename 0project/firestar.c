#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <errno.h> //错误处理函数的头文件
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <time.h>
#include <math.h>

void srand(unsigned int seed);
time_t time(time_t *t);
	
typedef struct point
{
	int x,y;
}TS_POINT;

typedef struct coor
{
	int x,y;
}COOR;

int coorx_box[10][10];
int coory_box[10][10];
char game_box[10][10];
int lcd_fd;
int *plcd;
int tmpe[]={-1,0,1};
/*
	功能：lcd 的初始化
	参数 无
	返回值 无
	lcd 初始化主要做 
		打开屏幕 
		映射
*/
void lcd_init()
{
	lcd_fd = open("/dev/fb0",O_RDWR);
	if(lcd_fd <0)
	{
		perror("open lcd error");
		return ;
	}
	plcd = (int*)mmap(NULL,800*480*4,PROT_WRITE|PROT_READ,MAP_SHARED,lcd_fd,0);
	if(plcd == NULL)
	{
		perror("mmap error");
		return ;
	}
}

/*
	解除初始化
	解映射和关闭屏幕
*/
void lcd_uninit()
{
	munmap(plcd,800*480*4);
	close(lcd_fd);
}

/*
屏幕画点函数
参数： i表示行 取值为(0-479)
		j表示列 取值为(0-799)
		color表示该点要显示的颜色
*/
                            
void draw_point( int i,int j,int color)
{
	*(plcd + i*800+j) = color;
}

/*
	画块的函数
	参数 i起点行坐标
		j起点纵坐标
		x块的长度
		y为块的宽度
		color 块的颜色
*/
void draw_block(int i,int j,int x,int y,int w, int h, int color)
{
	int a,b;
	for(a = i;a< i +y ;a++) //a 为行坐标
	{
		for(b = j;b<j+x;b++)
		{
			draw_point(a,b,color);
		}
	}
}

int show_pic(const char* pathname,int x,int y)
{
	int pic_fd = open(pathname,O_RDWR);
	if(pic_fd < 0)
	{
		perror("open pic error");
		return -1;
	}
	
	char pic_head[54] = {0};
	int ret = read(pic_fd,pic_head,54);
	if(ret < 54)
	{
		perror("read pic head error");
		return -1;
	}
	int len =  pic_head[21]<<24 | pic_head[20] << 16 | pic_head[19]<<8 |pic_head[18];//宽
	int kuan = pic_head[25]<<24 | pic_head[24] << 16 | pic_head[23]<<8 |pic_head[22];//高
	int depath = pic_head[29]<<8 |pic_head[28];//深度 
	//printf(" len = %d,kuan = %d,depath = %d\n",len,kuan,depath);
	
	char *buf;
	buf	= (char *)malloc(len*kuan*depath);
	if(buf == NULL)
	{
		perror("malloc buf error");
		return -1;
	}
	read(pic_fd,buf,len*kuan*depath);
	
	/*显示 */
	int i,j,a,r,g,b,color;
	int k=0;
	for(i = 0;i <kuan ;i++) 
	{
		for(j = 0;j<len;j++) 
		{
			a = 0x00;
			b = buf[k+0];
			g = buf[k+1];
			r = buf[k+2];
			k+=3;
			color = a<<24|r<<16|g<<8|b;
			draw_point(y+kuan-1-i,j+x,color);
		}
	}
	free(buf);
	close(pic_fd);
}

//星星展示
void show_star()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			switch(game_box[i][j])
			{
				case 1:
				show_pic("blue.bmp",360+i*40,399-j*40);
				coorx_box[i][j]=360+i*40;
				coory_box[i][j]=399-j*40;
				break;
				case 2:
				show_pic("red.bmp",360+i*40,399-j*40);
				coorx_box[i][j]=360+i*40;
				coory_box[i][j]=399-j*40;
				break;
				case 3:
				show_pic("purple.bmp",360+i*40,399-j*40);
				coorx_box[i][j]=360+i*40;
				coory_box[i][j]=399-j*40;
				break;
				case 4:
				show_pic("orange.bmp",360+i*40,399-j*40);
				coorx_box[i][j]=360+i*40;
				coory_box[i][j]=399-j*40;
				break;
				case 5:
				show_pic("green.bmp",360+i*40,399-j*40);
				coorx_box[i][j]=360+i*40;
				coory_box[i][j]=399-j*40;
				break;
			}
			
		usleep(1000);	
		}
	}
}

//触摸屏初始化
TS_POINT ts_init()
{
	TS_POINT start={-1,-1},stop = {-1,-1};
	//第一步：打开触摸屏 
	int ts_fd = open("/dev/input/event0",O_RDWR);
	if(ts_fd < 0 )
	{
		perror("open input lcd error");
		return;
	}
	//第二步：读取数据 
	
	struct input_event data;
	int   temp_x,temp_y;
	temp_x = temp_y = -1;
	while(1)
	{
		read(ts_fd,&data,sizeof(data));
		if(data.type == EV_ABS)
		{
			if(data.code == ABS_X)
			{
				temp_x = data.value;
			}
			else if(data.code == ABS_Y)
			{
				temp_y = data.value;
			}
			else if(data.code == ABS_PRESSURE)//压力事件
			{
				if(data.value >0)//起始坐标
				{
					if(start.x == -1 && start.y ==-1)
					{
						start.x = temp_x;
						start.y = temp_y;						
					}
				}
				else if(data.value == 0)//终点坐标
				{
					stop.x = temp_x;
					stop.y = temp_y;
					break;
				}
			}
		}
		
	}
	return start;
}

//确定坐标
COOR flag(int x,int y)
{
	int i,j;
	COOR p;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if((x>coorx_box[i][j]&&x<coorx_box[i][j]+40)&&(y>coory_box[i][j]&&y<coory_box[i][j]+40))
			{
				printf("[%d][%d]\n",i,j);
				p.x=i;
				p.y=j;
				return p;
			}	
		}
	}	
}


//消灭星星
int flag1 = 0;
void DFS(int x,int y,int tmp)
{
	int i,j;
	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 3;j++)
		{
			
			if(((x+tmpe[i])>=0&&(x+tmpe[i])<10)&&((y+tmpe[j])>=0&&(y+tmpe[j])<10))
			{ 
				if((abs(tmpe[i]) == abs(tmpe[j]))||(j==1&&i==1)||(game_box[x+tmpe[i]][y+tmpe[j]]==0))
				{
					continue;
				}
				//printf("i = %d,j = %d\n",i,j);
				if(game_box[x+tmpe[i]][y+tmpe[j]] == tmp)
				{
					
					game_box[x+tmpe[i]][y+tmpe[j]]=0;
					flag1++;
					//show_pic("back.bmp",coorx_box[x+tmpe[i]][y+tmpe[j]],coory_box[x+tmpe[i]][y+tm//pe[j]]);
					DFS((x+tmpe[i]),(y+tmpe[j]),tmp);		
				}
			}
		}
	}
	if(flag1 != 0)
	{
		game_box[x][y] = 0;
	}
}


//星星下落
void down()
{
	int x,i,j;
	for(x = 0;x<10;x++)
	{
		for(i = 9;i>0;i--)   
		{
			if(game_box[i][x] == 0)
			{
				for(j = i-1;j>=0;j--)
				{
					if(game_box[j][x]!=0)
					{	
						game_box[i][x] = game_box[j][x];
						game_box[j][x] =0;
						break;
					}
				}
			}
		}
	}	
}


//星星左移
void left()
{
	int x,i,j,tmp;
	
	for(x = 0;x<10;x++)
	{
		if(game_box[9][x]==0)
		{
			for(i = 9;i>=0;i--)   
			{
				tmp = x;
				for(j = x+1;j<10;j++)
				{	
					game_box[i][tmp] = game_box[i][j];
					game_box[i][j] = 0;	
					tmp++;
				}	
			}
		}	
	}	
}

//星星消除
void delete()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j = 0;j<10;j++)
		{
			printf("%d ",game_box[i][j]);
			if(game_box[i][j]==0)
			{
				show_pic("back.bmp",coorx_box[i][j],coory_box[i][j]);
			}	
		}
		printf("\n");
	}
}

int main(int argc,char **argv)
{
	lcd_init();
	while(1)
	{
		show_pic("background1.bmp",0,0);
		show_pic("begin.bmp",220,100);
		srand((unsigned int)time(NULL));//随机数种子
		TS_POINT s;
		COOR t;
		//星星随机化
		int i,j,tmp;
		for(i=0;i<10;i++)
		{
			for(j = 0;j<10;j++)
			{
				game_box[i][j] = rand()%5+1; //=>1 2 3 4 5
				printf("%d ",game_box[i][j]);
			}
			printf("\n");
		}
		show_star();
	
		while(1)
		{
			s = ts_init();
			printf("x=%d y=%d\n",s.x,s.y);
			if((s.x>360&&s.x<760)&&(s.y>39&&s.y<439))
			{
				t = flag(s.x,s.y);	
				printf("t.x=%d t.y=%d\n",t.x,t.y);
				tmp = game_box[t.x][t.y];
				if(flag1>=1)
				{
					flag1=0;
				}
				DFS(t.x,t.y,tmp);
				
				delete();//消除星星
				down();//星星下落
				//show_pic("background1.bmp",0,0);
				show_star();//显示下落调整以后星星
				
				delete();
				left();//判断有无左移
				delete();
				//show_pic("background1.bmp",0,0);
				show_star();
				
			}
			if((s.x>220&&s.x<290)&&(s.y>100&&s.y<350))
				break;
		}
	}
	
	lcd_uninit();
	return 0;
	
}

