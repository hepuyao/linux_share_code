#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义双向链表结点
typedef struct student
{	
	int score;
	char *name;
	
	struct student *prev,*next;
}stu;

//双向链表的初始化  用头节点
stu *init_link(void )
{
	stu *head=(stu *)malloc(sizeof(stu));
	head->next=head;
	head->prev=head;
	
	return head;
}


//头插一个数据
stu *Input(stu *head)
{
	
	printf("请输入本人姓名,性别与成绩\n");
	int numb;
	char *p=NULL;
	p=(char *)malloc(100 * sizeof(char));
	int i;
		
		
	scanf("%s%d",p,&numb);
	
	stu *node =(stu *)malloc(sizeof(stu));
	node->name =(char *)malloc(10);
	node->score=numb;
	strcpy(node->name,p);
	
	
	node->next=head->next;
	node->prev=head;
	head->next->prev=node;
	head->next=node;

	return head;
	
}


//删除
stu *Delate(stu *head,int elem)
{

	printf("请输入想要删除的分数\n");
	
	scanf("%d",&elem);
	stu *temp=head;
	while(temp!=NULL)
		{
			if(temp->score==elem)
				{
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;

					free(temp);
					return head;
				}
			temp=temp->next;
		}
}

void display(stu *head)
{
	stu *temp=head->next;
	while(temp!=head)
	{
		printf("%s                     %d\n",temp->name,temp->score);
		temp=temp->next;
	}
	printf("\n");
	
}

void main()
{	
	
	printf("*********************************\n");
	printf("*    功能表                     *\n");
	printf("* 一：输入学生信息              *\n");
	printf("* 二：删除学生信息              *\n");
	printf("* 三：修改学生信息              *\n");
	printf("* 四：查询学生信息              *\n");
	printf("* 五：成绩按照从高到低排序      *\n");
	printf("* * * * * * * * * * * * * * * * *\n");
		
	printf("请输入您的选择 \n退出请按0\n");
	
	

	stu *head=init_link();
/*	
	Input(head,60,"baoyige");
	Input(head,70,"zuolingfeng");
	Input(head,80,"chenxiunig");
	Input(head,10,"hepuyao");
	display(head);
	del_link(head,80,"chenxiunig");
	display(head);
*/	
	

		int n=-1;
		//int num;
		//char *s;
		
			scanf("%d",&n);
			
			//Input(head);
			//Input (head,80,"baoyighe");
		
			
				switch (n)
				{	
					case 0:break;
					case 1:Input(head);
					//case 2:Delate();
					//case 3:Inquiry();
					//case 4:Revise();
					//case 5:Reorder();
					
				}
				printf("*******************************************************************\n");
				printf("姓名        性别       成绩         出生年 月 日      个人兴趣爱好\n");
				display(head);
				printf("请继续您的选择 \n退出请按0\n");
		
				scanf("%d",&n);
			
				switch (n)
				{	
					case 0:break;
					case 1:Input(head);
					case 2:Delate();
					//case 3:Inquiry();
					//case 4:Revise();
					//case 5:Reorder();
					
				}
				printf("*******************************************************************\n");
				printf("姓名        性别       成绩         出生年 月 日      个人兴趣爱好\n");
				display(head);
				printf("请继续您的选择 \n退出请按0\n");

				
				scanf("%d",&n);
							
				switch (n)
				{	
					case 0:break;
					case 1:Input(head);
					//case 2:Delate();
					//case 3:Inquiry();
					//case 4:Revise();
					//case 5:Reorder();
									
				}
					printf("*******************************************************************\n");
					printf("姓名		  性别	   成绩		  出生年 月 日 	 个人兴趣爱好\n");
					display(head);
					printf("请继续您的选择 \n退出请按0\n");



				scanf("%d",&n);
				
				switch (n)
								{	
									case 0:break;
									case 1:Input(head);
									case 2:Delate(head,90);
									//case 3:Inquiry();
									//case 4:Revise();
									//case 5:Reorder();
													
								}
									printf("*******************************************************************\n");
									printf("姓名		  性别	   成绩		  出生年 月 日 	 个人兴趣爱好\n");
									display(head);
									printf("请继续您的选择 \n退出请按0\n");
}


