#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

void startMenu();

void coffeeMENU();

void allTimecheckInput(int, int);

void dailyCheckInput(int, int&, int&, int&, int& , int);

void showTotalCupsSold(int, int, int, int);

void showTotalAmountSold(int);

void showTotalMoneyMade(double);

void allTimeRecord();

void clearAllTimeRecord();

int main()
{
	bool check=true;
	
	const double smallCupPrice = 1.75, mediumCupPrice = 1.90, largeCupPrice = 2.00;

	const int smallCupVolume = 9, mediumCupVolume = 12, largeCupVolume = 15;

	double totalMoney=0;

	int totalAmountSold=0, totalCupsSold=0, choice=1, choice1=1, totalSmallCups=0, totalMediumCups=0,
		totalLargeCups=0, Quantity=0;
	
	while (check)
	{
		totalAmountSold = (totalSmallCups * smallCupVolume) + (totalMediumCups * mediumCupVolume) + (totalLargeCups * largeCupVolume);

		totalMoney = (totalSmallCups * smallCupPrice) + (totalMediumCups * mediumCupPrice) + (totalLargeCups * largeCupPrice);

		cout << "\n\n";
		cout << "\n-----------------------------------------------------------------------------------------------------------\n";
		cout << "\t\t\tWELCOME TO JASON COFFEE SHOP";
		cout << "\n-----------------------------------------------------------------------------------------------------------\n";
		
		startMenu();
		
		cin >> choice;
		cin.clear();
		cin.ignore(1000,'\n');
		
		system("CLS");
		
		if (choice == 1)
		{
			do
			{
				coffeeMENU();
				cin >> choice1;
				cin.clear();
				cin.ignore(1000,'\n');

				if (choice1 > 0 && choice1 < 4)
				{
					cout<<"\nHOW MUCH DO YOU WANT: ";
					cin>>Quantity;
					if(Quantity>0)
					{
				
						dailyCheckInput(choice1, totalSmallCups, totalMediumCups, totalLargeCups, totalCupsSold, Quantity);

						allTimecheckInput(choice1, Quantity);

						cout << "\n\nORDER PLACED.....\n\n\n";
					}
					else
						cout<<"\n\nORDER NOT PLACED \nQUANTITY CAN'T BE NEGATIVE OR 0;\n\n";

					
				}

				else if (choice1 == -1)
					break;

				else
				{
					cout << "WRONG INPUT\n";
				}
					
				system("pause");
				system("cls");

			} while (check);
		}

		else if (choice == 2)
		{
			showTotalCupsSold(totalSmallCups, totalMediumCups, totalLargeCups, totalCupsSold);
		}

		else if (choice == 3)
		{
			showTotalAmountSold(totalAmountSold);
		}

		else if (choice == 4)
		{
			showTotalMoneyMade(totalMoney);
		}

		else if (choice == 5)
		{
			allTimeRecord();
		}

		else if (choice == 6)
		{
			clearAllTimeRecord();
		}

		else if (choice == -1)
			return 0;

		else
		{
			cout << "\nWRONG INPUT\n";
		}
		
		cout<<"\n\n";
		system("pause");
		system("cls");
	}
	
}

void startMenu()
{
	cout << "\n\n";

	cout<< "   1.  Buy coffee in any size and in any number of cups\n\n"
		<< "   2.  show the total number of cups of each size sold today\n\n"
		<< "   3.  show the total amount of coffee sold today\n\n"
		<< "   4.  show the total money made today\n\n"
		<< "   5.  show all time record\n\n"
		<< "   6.  clear all time record\n\n";

	cout << "\n\n\nENTER THE S.no OF OPTION YOU WANT TO CHOOSE:"
		<< "\n\nENTER \"-1\" TO EXIT THE PROGRAM\n\n\t";
}

void coffeeMENU()
{
	cout<< "\n-----------------------------------------------------------------------------------------------------------\n";
	cout<< "\t\tHERE IS OUR MENU";
	cout<< "\n-----------------------------------------------------------------------------------------------------------\n";
	cout<< "\n\n";
	cout<< "----------------------------------------------------------\n"
		<< " S.no   |        SIZE         |    PRICE   |  VOLUME      |\n"
		<< "----------------------------------------------------------\n"
		<< "\n  1.    |   SMALL SIZE CUP    |    1.75$   |    9oz       |\n\n"
		<< "\n  2.    |   MEDIUM SIZE CUP   |    1.90$   |    12oz      |\n\n"
		<< "\n  3.    |   LARGE SIZE CUP    |    2.00$   |    15oz      |\n\n"
		<< "----------------------------------------------------------\n";

	cout << "\nENTER THE S.no of the item you want to buy\n\n";
	cout << "IF YOU WANT TO GO BACK ENTER \"-1\": \n\n";
}

void dailyCheckInput(int choice, int& totalSmallCups, int& totalMediumCups, int& totalLargeCups, int& totalCupsSold, int Quantity)
{
	totalCupsSold*=Quantity;
	
	if (choice == 1)
	{
		if(totalSmallCups==0)
		{
			totalSmallCups++;
		}
		totalSmallCups*=Quantity;
	}
	
	else if (choice == 2)
	{
		if(totalMediumCups==0)
		{
			totalMediumCups++;
		}
		totalMediumCups*=Quantity;
	}
	
	else
	{
		if(totalLargeCups==0)
		{
			totalLargeCups++;
		}
		totalLargeCups*=Quantity;
	}
}

void allTimecheckInput(int choice, int Quantity)
{
	ofstream input;
	input.open("ALL.DATA", ios::app);
	
	if (choice == 1)
	{
		for(int i=0; i<Quantity; i++)
		{
			input << 's';
			input << '\n';
		}
	}
	
	else if (choice == 2)
	{
		for(int i=0; i<Quantity; i++)
		{
			input << 'm';
			input << '\n';
		}
	}
	
	else
	{
		for(int i=0; i<Quantity; i++)
		{
			input << 'l';
			input << '\n';
		}
	}
	input.close();
}

void showTotalCupsSold(int totalSmallCups, int totalMediumCups, int totalLargeCups, int totalCupsSold)
{
	cout << "\n\n\t\tTOTAL SMALL CUPS SOLD TODAY:       " << totalSmallCups;
	cout << "\n\n\t\tTOTAL MEDIUM CUPS SOLD TODAY:      " << totalMediumCups;
	cout << "\n\n\t\tTOTAL LARGE CUPS SOLD TODAY:       " << totalLargeCups;
	cout << "\n\n\n\t\t*TOTAL CUPS SOLD TODAY:            " << totalCupsSold;
}

void showTotalAmountSold(int totalAmountSold)
{
	cout << "\n\n\t\tTOTAL AMOUNT OF COFFEE SOLD TODAY: " << totalAmountSold << " OZ\n";
}

void showTotalMoneyMade(double totalMoney)
{
	cout << "\n\n\t\tTOTAL MONEY MADE TODAY: " << totalMoney << "\n";
}

void allTimeRecord()
{
	const double smallCupPrice = 1.75, mediumCupPrice = 1.90, largeCupPrice = 2.00;
	
	const int smallCupVolume = 9, mediumCupVolume = 12, largeCupVolume = 15;
	
	double totalMoney = 0;
	
	int totalAmountSold = 0, totalCupsSold = 0, choice = 1, choice1 = 1, totalSmallCups = 0, totalMediumCups = 0, totalLargeCups = 0;
	
	char a;
	
	ifstream read;
	read.open("ALL.DATA");
	
	while (!(read.eof()))
	{
		read >> a;
	
		if (a == 's')
			totalSmallCups++;
		
		else if (a == 'm')
			totalMediumCups++;
		
		else if (a == 'l')
			totalLargeCups++;
	}
	
	totalCupsSold = totalSmallCups + totalMediumCups + totalLargeCups;
	
	totalAmountSold = (totalSmallCups * smallCupVolume) + (totalMediumCups * mediumCupVolume) + (totalLargeCups * largeCupVolume);
	
	totalMoney = (totalSmallCups * smallCupPrice) + (totalMediumCups * mediumCupPrice) + (totalLargeCups * largeCupPrice);

	read.close();

	cout << "\n-----------------------------------------------------------------------------------------------------------\n";
	cout << "\n\t\t\t\tALL TIME RECORD";
	cout << "\n-----------------------------------------------------------------------------------------------------------\n";
	cout << "\n\n\t\tTOTAL SMALL CUPS SOLD ALL TIME:           " << totalSmallCups;
	cout << "\n\n\t\tTOTAL MEDIUM CUPS SOLD ALL TIME:          " << totalMediumCups;
	cout << "\n\n\t\tTOTAL LARGE CUPS SOLD ALL TIME:           " << totalLargeCups;
	cout << "\n\n\t\tTOTAL CUPS SOLD ALL TIME:                 " <<totalCupsSold;
	cout << "\n\n\t\tTOTAL MONEY MADE ALL TIME:                " << totalMoney;
	cout << "\n\n\t\tTOTAL AMOUNT OF COFFEE SOLD ALL TIME:     " << totalAmountSold << " OZ (VOLUME)\n";
}

void clearAllTimeRecord()
{
	ofstream data;
	
	data.open("ALL.DATA");
	
	data.close();
	
	cout << "\n\n\t\t\tDATA CLEARED.....";
}
