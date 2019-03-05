/*

模仿董事长
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
using namespace std;


class Holder
{
	public:
		Holder();
		void welcome();
		void printf();

		string name;
		int bank_number;
		int balance;
};
Holder:: Holder()
{
	name="null";
	bank_number=0;
	balance=0;
}

void Holder:: welcome()
{
	cout<<"1.存款  2.取款  3.转账  4.查询交易明细  5.修改密码"<<endl;
}
void Holder:: printf():public Holder
{
	cout<<name<<bank_number<<balance;
}
class Bank
{
	public:
		void welcome_adm();
		void account();
};
void Bank::welcome_adm()
{
	cout<<"1.开户  2.销户 3.登陆"<<endl;
	int i;
	cin>>i;
	if(i==1)
	{
		account();
	}
	if(i==3)
	{
		login();
	}
}
void Bank::account()
{
	int j;
	Holder Holder[j];
	Holder[j].printf();
	cout<<"please insert your name"<<endl;
	cin>>Holder[j].name;
	Holder[j].printf();
}
void Bank::login()
{
	int i;
	cout<<"1.存款  2.取款  3.转账"<<endl;
	for(i==1)
	{
		cout<<"please insert how much you want to insert"<<endl;
		int insert
		cin>>
	}
}

int main()
{
	Bank user;
	user.welcome_adm();
	
}

