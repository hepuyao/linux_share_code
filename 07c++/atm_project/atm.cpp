9/*
C/C++实训项目 

模拟银行储蓄系统（ATM）

实现如下功能:

1. 开户    2. 存款  3. 取款  4. 转账  5. 查询交易明细  6.销户  7. 修改密码

该系统的用户有2种类型： 普通用户 和 管理员(admin  管理密码为  123456)

普通用户具有:    登录  存款  取款  转账  查询  修改密码的功能
管理员用户具： 除了具有普通用户功能外，还具有开户和销户功能

要求使用C++ 实现，自己设计好需要用到的类和对象。
一般来讲，该系统要用到2个类(用户类  和 银行类,仔细设计这2个类的方法和成员)
可以使用 STL 模板中的  list 或 vector来管理银行的用户。

系统能保存储户信息到文件，重新运行程序后，能从文件读取用户信息到系统，这样重新启动后，储户
信息还在。



每个用户的账户包括以下信息:
姓名    银行卡号     身份ID      收入      支出     余额      操作日期      备注


*/

#include <iostream>
#include <fstream>//输入输出文件
#include <iomanip>
#include <list>

using namespace std;
//数据存放区
		int i;
		int j;
		int j_in;
		int secect_ad_us;
		char select;
		int admin_key;
		int admin_key_in;
		int user_key;
		int user_key_in;


class Holder
{
	public:
		Holder();//构造函数
		void account();//开户
		void print_atm();//打印
		void depo_money();//存款
		void withdrawal();//取款
		void cancellation();//销户
		void record(Holder &holder02);//记录
		void check();//检查账户信息
		


		
		string name;//用户姓名
		int bank_number;//账户
		string id_number;
		int balance;//余额
		int income;//收入
		int expend;//支出
		int admin_key;//管理员密码
		int user_key;//用户密码
		string node;//添加备注消息
		list <Holder> node_list;//定义一个list容器来保存用户的数据
		list <Holder>::iterator iter;//定义一个迭代器
		int nodelist_num;//保存用户账单数目
		

};

Holder:: Holder()
{
	name="NULL";
	bank_number=0;
	balance=0;	
}
//开户
void Holder:: account()
{
	
	cout<<"02请输入您的姓名"<<endl;
	string name2;
	cin>>name2;
	name=name2;
	
	cout<<"请输入银行账号"<<endl;
	int bank_number1;
	cin>>bank_number1;
	bank_number=bank_number1;

	cout<<"请输入您的账户密码"<<endl;
	cin>>user_key;

	cout<<"请输入备注消息"<<endl;
	cin>>node;
	
	cout<<"姓名："<<name<<"   银行账号："<<bank_number;
	cout<<"  余额："<<balance <<"账户密码"<<user_key<<endl;
}
//打印凭条
void Holder:: print_atm()
{                                                                
	cout<<"姓名："<<name<<"   银行账号："<<bank_number;
	cout<<"  余额："<<balance <<"账户密码"<<user_key<<endl;
}
//存款
void  Holder:: depo_money()
{
	cout<<"请输入您的密码"<<endl;
	cin>>user_key_in;
	if(user_key_in==user_key)
	{
		cout<<"请输入您想要存款的额度"<<endl;
		int deposit_mny1;
		cin>>deposit_mny1;

		cout<<"请输入备注"<<endl;
		cin>>node;
		balance=balance+deposit_mny1;
	 }
	else
		{cout<<"密码错误"<<endl;}
}
//取款
void Holder:: withdrawal()
{
	cout<<"请输入您想要提款的额度"<<endl;
	int withdrawal_money1;
	cin>>withdrawal_money1;
	balance=balance-withdrawal_money1;
}
//销户
void Holder:: cancellation()
{
	name="NULL";
	bank_number=0;
	balance=0;
}    
//记录
void Holder::record(Holder &holder02)
{
	node_list.push_back(holder02.node);
	nodelist_num++;
}
//查询
void Holder::check()
{
	cout<<"姓名："<<name<<"   银行账号："<<bank_number;
	cout<<"  余额："<<balance <<"账户密码"<<user_key<<endl<<endl;
	
	/*
	for(iter=node_list.begin();iter!=node_list.end();iter++)
	{
		cout<<*iter<<endl;
		iter++;
	}
*/
	iter=node_list.begin();
	cout<<*iter<<endl;

}


int main()
{
	cout<<"1.开户(管理员权限) 2.存款  3.取款  4.转账  5.查询交易明细  6.销户（管理员权限）  7.修改密码 8.退出"<<endl;
	cout<<"请输入您想要进行的操作"<<endl;
	
	Holder holder_2[100000];
	while(i!=8)
	{
		cin>>i;
		
		//开户
		if(i==1)
		{
			cout<<"请输入管理员密码"<<endl;
			cin>>admin_key_in;
			if(admin_key_in==234)
			{
				cout<<"请输入开户账号"<<endl;
				cin>>j;
				holder_2[j].print_atm();
				holder_2[j].account();
				holder_2[j].record(holder_2[j]);
			}
			else
			{
				cout<<"密码错误"<<endl;
			}

		}
			
			//存款
			if(i==2)
			{
				cout<<"请输入您的账号"<<endl;
				cin>>j;
			
				holder_2[j].print_atm();
				holder_2[j].depo_money();
				holder_2[j].print_atm();
				holder_2[j].record(holder_2[j]);
				
			}

			//取款
			if(i==3)
			{
				cout<<"请输入您的账号"<<endl;
				cin>>j;
				holder_2[j].print_atm();
				holder_2[j].withdrawal();
				holder_2[j].print_atm();
			}
			
			
			if(i==5)
			{
				cout<<"请输入您的账号"<<endl;
				cin>>j;
				holder_2[j].check();
			
			}
				
			
			
			//销户
			if(i==6)
			{
				cout<<"请输入您想要注销的用户"<<endl;
				cin>>j;
				holder_2[j].cancellation();
				
			}
		
		cout<<"1. 开户    2. 存款  3. 取款  4. 转账  5. 查询交易明细  6.销户  7. 修改密码"<<endl;
		cout<<"请输入您的选择"<<endl;
	}

	
	return 0;
}

