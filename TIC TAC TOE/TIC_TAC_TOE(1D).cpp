//                                        	BY TALHA YUNUS
//									     		2020497
//								CS103 LAB PROJECT (1D array implementation)


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <windows.h>


using namespace std;

//function prototypes

void selectOption(char*);

int toss(string*);

void gui(char*, string*, char*, int);

void getInput( char*,string*, char*, int&);

bool checkWin(char*, string*, char*, int);

bool checkDraw(char*, int);

bool newGame(char*, int);

void celebratonOnWin();



int main()
{
	//initialization 
	
	bool check_Win = true , check_Draw=true , new_Game=true , Toss=true;
	
	string name[3] = {"PLAYER 1" , "PC"};

	char option[3] = { 'X','O' };
	
	const int size1 = 10;

	int size = size1 - 1 , turn;
	
	//declaration of 1D array
	char array[size1] = {'1','2','3','4','5','6','7','8','9'};
	
	srand(time(0));

	while (new_Game)
	{

		if (Toss == true)
		{
			//There will be a toss in the start of game
			
			selectOption(option);
			turn = toss(name);
			Toss = false;
		}
		
		system("cls");
		
		gui(array, name, option, size);
		
		getInput(array, name, option, turn);
		
		check_Win = checkWin(array, name, option, size);
		
		if(check_Win==true)
			check_Draw = checkDraw(array, size);
		
		if (check_Win==false || check_Draw==false)
		{
			//if player wants to play again
			
			new_Game = newGame(array, size);
			
			if (new_Game == true)
				Toss = true;
		}
	}
}


void selectOption(char* option)//player will have a choice to select his character i.e(X,O)
{
	int select=0;
	
	cout << "\n\n";
	cout << "\t|-------------------------------------------------------------------|\n";
	cout << "\t|                         TIC TAC TOE                               |\n";
	cout << "\t|-------------------------------------------------------------------|\n";
	cout << "\nWHICH CHARACTER YOU WANT TO CHOOSE FOR YOURSELF FROM THE FOLLOWING:\n\n"
		<< "  1.  'X'\n\n"
		<< "  2.  'O'\n\n";
	cout << "\t\tENTER 1 TO SELECT 'X'\tOR\tENTER 2 TO SELECT 'O':  \n\n";
	
	while (select != 1 && select != 2)
	{
		cin >> select;
	
		cin.clear();
		cin.ignore(1000, '\n');
		
		if (select != 1 && select != 2)
			cout << "\n\nWRONG INPUT !!!\n\n\tTRY AGAIN\t";
	}

	if (select == 2)
	{
		option[0] = 'O';
		option[1] = 'X';
	}

	for(int i=0; i<2; i++)
	{
		system("cls");
		cout << "\n\n\t\tYOU HAVE SELECTED ( " << option[0] << " )\n\n";
	
	
		cout<<"\nLOADING  ";
		for(int j=0; j<3; j++)
		{
			Sleep(400);
			cout<<" . ";
		}
	}
	system("cls");
}



int toss(string* name)//In the start of game there will be a toss to decide the first turn
{
	srand(time(0));
	
	int i;
	
	i = (rand() % 2) + 1;
	
	for(int i=0; i<3; i++)
	{
		system("cls");
		
		cout << "\n\n";
		cout << "\t|-------------------------------------------------------------------|\n";
		cout << "\t|                         TIC TAC TOE                               |\n";
		cout << "\t|-------------------------------------------------------------------|\n";
		cout << "\n\n\tGET READY FOR TOSS"
			 << "\n\nPLEASE WAIT A MOMENT  ";
			 
		for(int j=0; j<3; j++)
		{
			Sleep(300);
			cout<<" . ";
		}
	}
	
	cout<<".\n\n\n";
	
	cout << "\n\t" << name[i - 1] << " has won the toss\n\n";
	cout << "\t" << name[i-1]<<" WILL MAKE HIS FIRST MOVE\n\n\n";
	
	system("pause");
	system("cls");
	
	return i;
}



void gui(char* array, string* name, char* option, int size)//gui=graphical user interface
{
	//output a good looking interface to make the game interactice
	cout << "\n";
	cout << "\t|-------------------------------------------------------------------|\n";
	cout << "\t|                         TIC TAC TOE                               |\n";
	cout << "\t|-------------------------------------------------------------------|\n";
	cout << "\t|                                                                   |\n";
	cout << "\t|       " << name[0] << " ( "<<option[0]<<" )\t\tVS\t\t" << name[1] 
		 << " ( "<<option[1]<<" )            |\n";
	cout << "\t|                                                                   |\n";
	cout << "\t|-------------------------------------------------------------------|\n";
	cout << "\t|                                                                   |\n";
	cout << "\t|                                                                   |\n";
	for (int i = 0; i < size; i+=3)
	{
		cout << "\t|\t\t" << array[i] << "\t|\t" << array[i+1] << "\t|\t" << array[i+2] 
			 << "\t            |\n";
	
		if(i!=6)
			cout << "\t|\t ---------------|---------------|---------------            |\n";
	}
	cout << "\t|                                                                   |\n";
	cout << "\t|                                                                   |\n";
	cout << "\t|-------------------------------------------------------------------|\n";
}



void getInput(char* array,string* name, char* option, int& turn)//get input from player 
																//and random input from PC
{
	int choice;
	bool check = true;
	
	srand(time(0));
	
	cout << "\n\n";
	
	while (check)
	{
		if (turn == 1)
		{
			cout << "\n\t" << name[0] << "\'s TURN: ";
			cin >> choice;
			
			cin.clear();
			cin.ignore(1000, '\n');

			choice--;
	
			if (array[choice] != 'X' && array[choice] != 'O' && (choice>=0 && choice<=8))
			{
				array[choice] = option[0];
				check = false;
			}
	
			else
				cout << "\n\tWrong input\t\tTRY AGAIN\n\n";
			
		}
	
		else if (turn == 2)
		{
			choice = rand() % 9;
	
			if (array[choice] != 'X' && array[choice] != 'O')
			{
				cout << "\n\t" << name[1] << "\'s TURN: ";
				cout << "\n\n\n\tPC IS TAKING SOME TIME TO DECIDE ITS MOVE  ";
				
				for(int i=0; i<6; i++)
				{
					Sleep(300);
					cout<<" . ";
				}
				cout<<"\n\n";
	
				cout << "\n\n\t\tPC ENTERED " << choice+1 << "\n\n\n";
	
				array[choice] = option[1];
				check = false;
	
				Sleep(1400);
			}
		}
	}
	
	if(turn==1)
		turn++;
	
	else if(turn==2)
		turn--;
}

void celebrationOnWin()
{
	system("cls");
	cout<<"\n\nCONGRATS YOU WON !!!\n\n";
	for (int i=0; i<30; i++)
	{
		for(int j=0; j<14; j++)
		{
			cout<<"\t*";
		}
		cout << endl;
		Sleep(15);
	}
	cout<<"\n";
	cout<<"\n";
	system("pause");
}


bool checkWin(char* array, string* name, char* option, int size) //will check if the game is won by anyone
{
	int win = 0;
	
	char P1 = option[0], PC = option[1];
	
	for (int i = 0; i < size; i+=3)
	{
		if (array[i] == P1 && array[i + 1] == P1 && array[i + 2] == P1)
		{
			win= 1;
			break;
		}
	
		else if (array[i] == PC && array[i + 1] == PC && array[i + 2] == PC)
		{
			win= 2;
			break;
		}
	}
	
	if (win == 0)
	{
	
		for (int i = 0; i < size / 3; i++)
		{
			if (array[i] == P1 && array[i + 3] == P1 && array[i + 6] == P1)
			{
				win = 1;
				break;
			}
	
			else if (array[i] == PC && array[i + 3] == PC && array[i + 6] == PC)
			{
				win = 2;
				break;
			}
		}
	}
	if (win == 0)
	{
		if (array[0] == P1 && array[4] == P1 && array[8] == P1)
			win = 1;
	
		else if (array[0] == PC && array[4] == PC && array[8] == PC)
			win = 2;
	
		else if (array[2] == P1 && array[4] == P1 && array[6] == P1)
			win = 1;
	
		else if (array[2] == PC && array[4] == PC && array[6] == PC)
			win = 2;
	}
	
	if (win != 0)
	{
		if (win == 1)
		{
			cout << "\n\n\t\t\t" << name[0] << " WON !!!\n\n";
			Sleep(1000);
			celebrationOnWin();
		}
		else
		{
			cout << "\n\n\t\t\t" << name[1] << " WON !!!\n\n";
			system("pause");
		}
	
		return false;
	}
	
	else
		return true;
}



bool checkDraw(char* array, int size) //if all the spaces are occupied it will declare a draw
{
	for (int i = 0; i < size; i++)
	{
		if ((array[i] != 'X') && (array[i] != 'O'))
			return true;
	}
	
	cout << "\n\n\t\t\tMATCH DRAWN !!!\n\n";
	system("pause");
	
	return false;
}



bool newGame(char* array, int size)//if player wants to play again this function will start a new game
{
	int choice;
	
	cout << "\n\n\t\tENTER 1 to play again\t\tENTER ANY OTHER KEY TO EXIT: \n\n";
	cin >> choice;

	cin.clear();
	cin.ignore(1000, '\n');

	if (choice == 1)
	{
		array[0] = '1'; array[1] = '2'; array[2] = '3';
		array[3] = '4'; array[4] = '5'; array[5] = '6';
		array[6] = '7'; array[7] = '8'; array[8] = '9';

		cout << "\n\n\tWAIT... WHILE WE ARE STARTING A NEW GAME ";
	
		for(int i=0; i<4; i++)
		{
			Sleep(1000);
			cout<<" . ";
		}
		cout<<".\n\n\n";
	
		system("cls");
	
		return true;
	}
	
	else
		return false;
}


