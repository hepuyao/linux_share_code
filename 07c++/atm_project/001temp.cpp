#include <iostream>
#include <list>
using namespace std;
class Student
{
	public:
		Student();
		void record(Student &stu2);
		string name;
		int number;
		list <string> mylist;
		int list_number;
		
};
Student:: Student()
{
	name="jack";
	number=1234;
}

void Student::record(Student &stu2)
{
	mylist.push_back(stu2.name);
	list_number++;
}
void Student::print()
{}
int main()
{
	Student stu01;
	stu01.record(stu01);
	Student stu02;
	stu02.record(stu01);
	
	list <string>::iterator iter;
	for(iter=mylist.begin;iter!=mylist.end();iter++)
	{cout<<*iter<<" ";}

}
