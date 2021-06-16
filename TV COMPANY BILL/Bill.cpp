#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int acc_no,total_ch,connection;
	double bill,total_con_price;
	char acc_code;
	cout<<setprecision(2)<<fixed;
	cout<<"WELCOME TO CABLE COMPANY BILLING"<<endl
		<<"enter your Account Number: ";
	cin>>acc_no;
	cout<<"enter 'b' or 'B' for buisness service\n"
		<<"enter 'r' or 'R' for residential service"<<endl;
	cin>>acc_code;
	if(acc_code=='r' || acc_code=='R')
	{
		cout<<"Enter the number of premium channels you have subscribed to : ";
		cin>>total_ch;
		bill=4.50+20.50+(7.50*total_ch);
	}
	else 
		if(acc_code=='b' || acc_code=='B')
		{
			cout<<"Enter the number of premium channels you have subscribed to :";
			cin>>total_ch;
			cout<<"enter total connections: ";
			cin>>connection;
			if (connection<=10 && connection>0)
			{
				total_con_price=75.00*connection;
			}
			else
				if(connection>10)
				{
					connection-=10;
					total_con_price=(5.00*connection)+(10*75.00);	
				}
			bill=total_con_price+15.00+(50*total_ch);
		}else
			cout<<"wrong input";
	cout<<left<<setw(40)<<"ACCOUNT NUMBER"<<setfill('*')<<acc_no<<endl;
	cout<<left<<setw(40)<<"TOTAL BILLL"<<bill<<endl;
	return 0;
}
