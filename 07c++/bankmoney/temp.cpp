#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	double height;
	ofstream out;
	out.open("03.txt");
	cin>>height;

	out<<height<<endl;
	out.close();
	
}
