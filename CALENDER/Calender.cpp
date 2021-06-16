#include <iostream>
#include <windows.h>
using namespace std;
	//PROGRAM TO FIND DAY BY USING DATE/MONTH/YEAR
int main()
{
int day,date,month,year,y1,y2;
	cout<<"\t\t\t**************************************************************"<<endl
		<<"\t\t\t********PROGRAM TO FIND DAY BY USING DATE/MONTH/YEAR**********"<<endl
		<<"\t\t\t**************************************************************"<<endl;
	cout<<"\n\n\t\t\tNOTE:***ENTER INPUNT IN NUMBER i.e 19/06/2002***\n";
	int loop=1;
	while(loop==1)
	{
		cout<<"\nENTER DATE"<<endl;
		cin>>date;
		system("cls");
		cout<<"ENTER MONTH"<<endl;
		cin>>month;
		system("cls");
		cout<<"ENTER YEAR"<<endl;
		cin>>year;
		system("cls");
		cout<<date<<'/'<<month<<'/'<<year<<endl;
		if(month==1 || month==2)
		{	
				year-=1;
		}
		y1=year/100;
		y2=year%100;
		if(month>2)
		{
			month-=2;
		}
		else
		{
			month+=10;
		}
		day=date+ ((13*month-1)/5) +y2+ (y2/4)+(y1/4)-(2*y1);
		if (day<0)
		{
			day= day%7;
			day+=7;
		}
		else
		{
			day=day%7;
		}
		switch(day)
		{
			case 0:
				cout<<"SUNDAY";
				break;
			case 1:
				cout<<"MONDAY";
				break;
			case 2:
				cout<<"TUESDAY";
				break;
			case 3:
				cout<<"WEDNESDAY";
				break;
			case 4:
				cout<<"THURSDAY";
				break;
			case 5:
				cout<<"FRIDAY";
				break;
			case 6:
				cout<<"SATURDAY";
				break;
			default:
				cout<<"SOMETHING WENT WRONG";
		}
		cout<<"\nPRESS 1 TO TO CONTINUE\t PRESS ANY OTHER KEY TO EXIT"<<endl;
		cin>>loop;
	}	
}
