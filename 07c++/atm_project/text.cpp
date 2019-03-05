/*
实现将数据写入文件的功能

*/
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
	public:
		Student();
		void show_information();
		string name;
		int age;
		string code;
};

Student::Student()
{
	name="jack";
	age=20;

}

void  Student::show_information()
{
	ofstream fout;
	fout.open("./0001225.txt");
	cout<<"name: "<<name<<"   age: "<<age<<endl;
	fout<<"name:"<<name<<"--age:"<<age<<endl;
	fout.close();
	ifstream fin;
	fin.open("./0001225.txt");
	fin>>code;
	cout<<code<<endl;
	fin.close();
	
}


int main()
{
	Student  stu01;
	stu01.show_information();
	
}
