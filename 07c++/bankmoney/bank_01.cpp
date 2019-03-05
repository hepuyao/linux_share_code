#include <iostream>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

class loans
{
	public:
		loans(string name2,float brrow_money2,float pay_back_time2,float money_rate2);
		loans(float borrow_money3,float pay_back_time2,float money_rate3);
		
		void output(void);
		void output_2();
		

	private:
		string name;
		float brrow_money;
		float pay_back_time;
		float money_rate;
		float money_rate2;		
};


loans::loans(string name2,float brrow_money2,float pay_back_time2,float money_rate2)
{
	name=name2;
	brrow_money=brrow_money2;
	pay_back_time=pay_back_time2;
	money_rate=money_rate2;	
}

loans::loans(float borrow_money3,float pay_back_time3,float money_rate3)
{
	brrow_money=borrow_money3;
	pay_back_time=pay_back_time3;
	money_rate=money_rate3;
	
}

					/*
					void loans::input(void)
					{
						cout<<"please input the money you borrow"<<endl;
						cin>>brrow_money;
						cout<<"time you send(month)"<<endl;
						cin>>pay_back_time;
						
					}
					*/
void loans::output(void)
{	
	/*
	int i;
	float month_pay;
	money_rate=money_rate/1200;
	for(i=0;i<pay_back_time;i++)
	{
		month_pay=(brrow_money)*(money_rate)*pow((1+money_rate),pay_back_time)/(pow((1+money_rate),pay_back_time)-1);
		//month_pay=(brrow_money);
		cout<<name;
		cout<<" 还款第"<<setw(3)<<i+1<<"期        本期还款"<<month_pay<<"  已还款："<<setw(8)<<month_pay*(i+1);
		cout<<setw(8)<<"         还要还"<<setw(4)<<pay_back_time-i-1<<"期";
		cout<<setw(9)<<"   剩余还款总额"<<month_pay*(pay_back_time-i-1)<<endl;
		
		
		
	}

	*/
	int i=0;
	float month_pay;
	money_rate=money_rate/1200;
	ofstream fout;
	fout.open("06.xlsx");
		for(i=0;i<pay_back_time;i++)
		{
		month_pay=(brrow_money)*(money_rate)*pow((1+money_rate),pay_back_time)/(pow((1+money_rate),pay_back_time)-1);
		//month_pay=(brrow_money);
		
		fout<<name;
		fout<<" 还款第"<<setw(3)<<i+1<<"期        本期还款"<<month_pay<<"  已还款："<<setw(8)<<month_pay*(i+1);
		fout<<setw(8)<<"         还要还"<<setw(4)<<pay_back_time-i-1<<"期";
		fout<<setw(9)<<"   剩余还款总额"<<month_pay*(pay_back_time-i-1)<<endl;
		
		}
		fout.close();
		
}

void loans::output_2()
{
	int i;
	float month_pay;
	float money_payd=0;
	money_rate=money_rate/1200;
	for(i=0;i<pay_back_time;i++)
	{
		
		month_pay=(brrow_money/pay_back_time)+((brrow_money-brrow_money*(i)/pay_back_time)*money_rate);
		money_payd=month_pay+money_payd;
		
		cout<<name;
		cout<<" 还款第"<<setw(3)<<i+1<<"期        本期还款"<<month_pay;
		cout<<"  已还款："<<setw(8)<<money_payd;
		cout<<setw(8)<<"         还要还"<<setw(4)<<pay_back_time-i-1<<"期"<<endl;
		//cout<<setw(9)<<"   剩余还款总额"<<setw(10)<<brrow_money-money_payd<<endl;		
	}
	
}
int main()
{
	//loans loans_01;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$            分期乐贷款平台                                             $$$$$"<<endl;
	cout<<"$$$$$              蚂蚁花呗                                                 $$$$$"<<endl;
	cout<<"$$$$$              京东白条                                                 $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
		
	

	float brrow_money_main;
	float pay_back_time_main;
	float money_rate_main;
	string name_main;
	int mode;
/*
	cout<<"请输入您的姓名"<<endl;
	cin>>name_main;
	cout<<"请输入您的贷款金额"<<endl;
	cin>>brrow_money_main;
	cout<<"请输入您的还款时限（温馨提示：以月为单位）"<<endl;
	cin>>pay_back_time_main;
	
	cout<<"请输入您愿意的还款方式："<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$            1.等额本息                                                 $$$$$"<<endl;
	cout<<"$$$$$            2.等额本金                                                 $$$$$"<<endl;
	cout<<"$$$$$            3.朋友代还                                                 $$$$$"<<endl;
	cout<<"$$$$$            4.蚂蚁花呗                                                 $$$$$"<<endl;
	cout<<"$$$$$            5.京东白条                                                 $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$                                                                       $$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
*/	
	cin>>mode;

	if(mode==1)
	{
		
		
		loans hepuyao("何朴尧"	,120000,120,4.86);
		hepuyao.output();
		/*
		loans loans_02(name_main,brrow_money_main,pay_back_time_main,4.86);
		loans_02.output();
		*/
	}
	
	if(mode==2)
		
	{
			//loans_01(brrow_money_main,pay_back_time_main,money_rate_main);
			//loans_01.output();
		

			/*
			money_rate_main=0.0045;
			loans loans_03(brrow_money_main,pay_back_time_main,money_rate_main);
			loans_03.output_2();
           */
			loans loans_04("陈修宁",120000,120,4.86);
			loans_04.output_2();
			
		}
	
}
