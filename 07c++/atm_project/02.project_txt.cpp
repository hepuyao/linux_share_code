/*
定义不要定义在循环里面，因为那样会定义很多次

在该项目中，必须注意到的一点是
每一个用户对象都必须将自己的数据存入一组数据中
在C语言中一般是使用结构体
但是在c++中一般不用结构体
利用map更加方便
*/

#include<iostream>
#include <map>
#define N 3
using namespace std;

class User
{
	public:
	    User()
	    {a=0;node="NULL";}
		User(int a1,string node1)
		{a=a1;node=node1;}
		void init(int a1,string node1)
		{a=a1;node=node1;}
		int a;
		string node;

};




int main()
{	
	
		int number1;
		string node1;
		string name;
		User user[N];
		map<string,User> map1;
		map<string,User>::iterator iter;
		for(int i=0;i<N;i++)
		{
			cout<<"请输入号码"<<endl;
			cin>>number1;
			cout<<"请输入备注"<<endl;
			cin>>node1;
			cout<<"请输入联系人姓名"<<endl;
			cin>>name;
			user[i].init(number1,node1);
			
			map1.insert(pair<string,User>(name,user[i]));
			
			iter=map1.find(name);
			
			cout<<iter->first<<endl;
			cout<<iter->second.a<<endl;
			cout<<iter->second.node<<endl;
		}
			
	

	map<string,User>::iterator iter1;
	iter1=map1.find("救护车");
	cout<<iter1->first<<endl;
	cout<<iter1->second.a<<endl;
	cout<<iter1->second.node<<endl;


	return 0;
}




