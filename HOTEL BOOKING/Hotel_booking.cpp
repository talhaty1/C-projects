#include <iostream>
using namespace std;
int main()
{
	const int units=50;
	double rent,increase_rent,maintenance;
	double max_profit1,max_profit2;
	cout<<"ENTER RENT WHEN ALL UNITS ARE OCCUPIED: ";
	cin>> rent;
	cout<<"The increase in rent that results in a vacant unit: ";
	cin>> increase_rent;
	cout<<"ENTER MAINTENANCE PER MONTH: ";
	cin>>maintenance;
	
	max_profit1=rent*units*maintenance;
	max_profit2=(increase_rent+rent)*(units-1)*maintenance;
	if(max_profit1>max_profit2)
	{
		cout<<"dont increase rent: "<<units;
	}
	else
		cout<<"it is better to increase rent: "<<units-1;
}
