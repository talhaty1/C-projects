//			Made BY Talha Yunus
//                  (2020497)(2020408)(2020493)
//if the user enters wrong data type then this will ask the user to correct it
#include <iostream>

void CERR(int &x)
{
	while(!(std::cin>>x))
	{
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		std::cout<<"\n\nWRONG INPUT \tTRY AGAIN";
		std::cout<<"\n\nEnter an Integer: ";

	}
}

void CERR(double &x)
{
	while(!(std::cin>>x))
	{
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		std::cout<<"\n\nWRONG INPUT \tTRY AGAIN";
		std::cout<<"\n\nEnter Double: ";
	}
}

void CERR(float &x)
{
	while(!(std::cin>>x))
	{
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		std::cout<<"\n\nWRONG INPUT \tTRY AGAIN";
		std::cout<<"\n\nEnter Float: ";
	}
}

void CERR(char* x)
{
	while(!(std::cin>>x))
	{
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		std::cout<<"\n\nWRONG INPUT \tTRY AGAIN: ";
		std::cout<<"\n\nEnter String: ";
	}
}

void CERR(char &x)
{
	while(!(std::cin>>x))
	{
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		std::cout<<"\n\nWRONG INPUT \tTRY AGAIN: ";
		std::cout<<"\n\nEnter a Character: ";

	}
}

// void cERR(auto x)
// {
// 	while(!(std::cin>>x))
// 	{	
// 		cout<<"\n\t\tWRONG INPUT !!!   TRY AGAIN\n";
// 		std::cin.clear();
// 		std::cin.ignore(1000,'\n');
// 	}
// }
