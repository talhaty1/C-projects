#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

void create_account();
void show_account(string x);

int main()
{
	string info;
	int choice;
	cout<<"enter 1 or 2"<<endl;
	cout<<"1. save email and password"
		<<"\n2. show password of saved email"<<endl;
		cin>>choice;
	
	switch(choice)
	{
		case 1:
			create_account();
			break;
		case 2:
			cout<<"enter your email"<<endl;
			cin>>info;
			show_account(info);
			break;
		default:
			cout<<"invalid input"<<endl;
	}
	system("pause");	
	return 0;
}

void create_account()
{
	string email[2];
	
	ofstream account;
	account.open("info",ios::app);
	
	cout<<"enter your email"<<endl;
	cin>>email[0];
	account<<endl<<email[0]<<" ";
	
	cout<<"enter your password"<<endl;
	cin>>email[1];
	account<<email[1];
	
	account.close();
}


void show_account(string x)
{
	string email[2],email1;
	
	ifstream account;
	account.open("info");
	
	while(!account.eof())
	{
		account>>email1;
		
		if (email1 == x)
		{
	 		email[0]=email1;
	 		account>>email1;
	 		email[1]=email1;
	 		cout<<"EMAIL: "<<email[0]<<"  PASSWORD: "<<email[1]<<endl;
		}
	
	}
	account.close();
}
