
#include<iostream>
#include <map>
using namespace std;

class User
{
	public:
		User(int a1,string node1)
		{a=a1;node=node1;}
		int a;
		string node;

};
int main()
{	

	User user01(119,"在火灾发生的时候拨打");
	User user02(120,"当您继续医疗救助的时候及时拨打");
	User user03(110,"当您遇到危险的时候立即拨打");
	map<string,User> map01;
	map01.insert(pair<string,User>("火警",user01));
	map01.insert(pair<string,User>("救护车",user02));
	map01.insert(pair<string,User>("匪警",user03));



	map<string,User>::iterator iter;
	iter=map01.find("救护车");
	cout<<iter->first<<endl;
	cout<<iter->second.a<<endl;
	cout<<iter->second.node<<endl;


	return 0;
}

