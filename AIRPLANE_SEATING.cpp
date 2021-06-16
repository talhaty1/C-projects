#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//function prototypes

void set_seat(bool array[2][5],int selectRow , int selectColumn , char ticket_type);

int check(bool array[2][5]);

void show(bool array[2][5]);


int main()
{
	char ticket_type;
	
	//declare 2d array 
	int row = 2,column = 5;
	bool *array;
	array = new bool[2][5];
	
	int selectRow , selectColumn;
	
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<5; j++)
		{
			array[i][j]=false;
		}
	}
	
	
	while(check(array))
	{
		show(array);
		
		cout<<"\nenter your ticket type: (b/e) ";
		cin>>ticket_type;
		
		cout<<"enter selectRow: ";
		cin>>selectRow;
		
		cout<<"enter selectColumn: ";
		cin>>selectColumn;
		
		set_seat(array , selectRow , selectColumn ,ticket_type);
		
		//if user enters integer in ticket_type then to avoid infinte loop 
		cin.clear();
		cin.ignore(1000,'\n');
		
		//this will pause and then clear the screen
		system("pause");
		system("cls");
	}
}

//book the seat which is entered by user
void set_seat(bool array[2][5] , int selectRow , int selectColumn , char ticket_type)
{
	if(array[selectRow-1][selectColumn-1]==true)
	{
	
		if((ticket_type=='B' || ticket_type=='b') && selectRow==1)
			array[selectRow-1][selectColumn-1]=true;
	
		else if((ticket_type=='E' || ticket_type=='e') && selectRow==2)
			array[selectRow-1][selectColumn-1]=true;
		
		
		//if ticket type does not match the input selectRow and selectColumn
		else
			cout<<"CHECK YOUR TICKET TYPE AGAIN \n";
	}
	
	//if the seat is already booked
	else
		cout<<"seat already booked"<<endl;
}


//if all seats are occupied 
int check(bool array[])
{
	
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(array[i][j]==true)
				return 1;
		}
	}
	
	return 0;
}

//show available seats
void show(bool array[2][5])
{
	for(int i=0; i<2; i++)
	{
		
		cout<<"1st ROW IS FOR BUISNESS CLASS AND 2nd IS FOR ECONOMY CLASS\n";
		cout<<"selectRow "<<i+1<<'\t';
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<5; j++)
			{
				if(array[i][j]==true)
				{
					cout<<"   BOOKED   ";
				}
				else{
					cout<<"   EMPTY    ";
				}
			}
			cout<<'\n';
		}
	
		cout<<"\n";
	}
}