//                NOTE:   Country_and_City_names.txt   file must be in the same folder 
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <windows.h>
using namespace std;

class hangTheMan
{
    int mistakes, wordLength;
    string name_;
    char *nameToGuess, *tempNameGuessed, spaceCharacter;

public:
    hangTheMan();
    int checkWin();
    void game();
};
//-----------------------------------------------------------------------------------------------------
int main()
{
    hangTheMan abc;
    abc.game();
}
//-----------------------------------------------------------------------------------------------------
hangTheMan::hangTheMan()
:  mistakes(0), spaceCharacter(' '), wordLength(0)
{
    int random = 0, totalListNames = 0;
    srand(time(0));
    ifstream read;
    read.open("Country_and_City_names.txt");
    while(!read.eof())
    {
        read.ignore(1000, '\n');
        totalListNames++;
    }
    read.clear();
    read.seekg(0, ios::beg);
    random = rand() % totalListNames;
    int i = 0;
    while (!read.eof())
    {
        if (i == random)
        {
            getline(read, name_);
            wordLength = name_.length();
            break;
        }
        else
        {
            read.ignore(1000, '\n');
            i++;
        }
    }
    read.close();
}

void hangTheMan::game()
{
    char input;
    bool checkInput = false, repeat;
    int end = 0;
    tempNameGuessed = new char[wordLength];
    nameToGuess = new char[wordLength];
	char charatersTried[26]= {' '};
	int turns=0;
	char humanBody[4][5] =  {{' ','(',' ',')'}, {' ','/','|','\\'}, {' ',' ','|',' '}, {' ','/',' ','\\'}} ;
	char tempHumanBody[4][5] = {{' ',' ',' ',' '}, {' ',' ',' ',' '}, {' ',' ',' ',' '}, {' ',' ',' ',' '}};	
    for (int i = 0; i < wordLength; i++)
    {
        nameToGuess[i] = name_[i];
        tempNameGuessed[i] = '_';
        if(nameToGuess[i]==spaceCharacter)
        {
        	tempNameGuessed[i]=spaceCharacter;
        }
    }
    while (!end)
    {
    	checkInput = false;
       	repeat = false;    
        system("CLS");
		cout<<"------------------------------------------------------------------\n";
		cout<<"               -----   ----      --     ----    -     -           \n";
		cout<<"               -    -  -        -  -    -   -    -   -            \n";
		cout<<"               -  - -  ---     - -- -   -    -    - -             \n";
		cout<<"               -   -   -      -      -  -   -      -              \n";
		cout<<"               -    -  -----  -      -  ----       -              \n";
		cout<<"------------------------------------------------------------------\n\n";
		for(int i=0; i<4; i++)
		{
			for (int j=0; j<5; j++)
			{
				cout<<tempHumanBody[i][j];
			}
			cout<<"\t\t-->\t\t";
			for (int j=0; j<5; j++)
			{
				cout<<humanBody[i][j];
			}
			cout<<endl;
		}
		cout<<"------------------------------------------------------------------\n";
	    cout << "\n\nGUESS THE NAME OF CITY/COUNTRY\n\t YOU HAVE TOTAL 8 TRIES:\n\n\t\t";
	    for (int i = 0; i < wordLength; i++)
        {
            cout << ' ' << tempNameGuessed[i];
        }
		cout<<"\t\t\t\tTRIES LEFT: * "<<8-mistakes
			<<"\n\n\t\t\t\t\t\t\tAlphabets you have tried SO FAR:\n\t\t\t\t\t\t\t";
		for(int i=0; i<=turns; i++)
		{
			cout<<charatersTried[i]<<' ';
		}
		cout<<"\n\n";
        cout<<"\n\nEnter your character(lower-case only): ";
        cin >> input;
        for(int i =0; i<=turns; i++)
        {
        	if(input == charatersTried[i])
        	{
        		repeat = true;
        		break;
        	}
        }
        if (repeat == true)
    	{
    		cout<<"YOU HAVE ALREADY ENTERED THIS ALPHBET \n\n";
    		system("pause");
    		continue;
    	}
    	else
    	{
    		charatersTried[turns] = input;
    		turns++;
    	}
        for (int i = 0; i < wordLength; i++)
        {
            if (input == nameToGuess[i])
            {
                tempNameGuessed[i] = input;
                checkInput = true;
            }
        }
        if (checkInput == true)
            cout << "CORRECT: ";
        else
        {
            cout << "WRONG: ";
            bool z = true;
            for(int i=0; i<4; i++)
            {
            	for(int j=0; j<5; j++)
            	{
            		if(tempHumanBody[i][j] != humanBody[i][j] && z == true)
            		{
            			tempHumanBody[i][j] = humanBody[i][j];
            			z=false;
            			break;
            		}
            	}
            }
            mistakes++;
        }
        end = checkWin();
    }

    if(end==2)
    {
    	cout<<"\nCONGRATS YOU WON ! \n";
    }
    else if(end==1)
    {
    	cout<<"\nYOU LOST ! \n";
    }
    cout << "\n\ncorrect answer: " << name_<<"\n\n";
    system("pause");
}

int hangTheMan::checkWin()
{
    bool check = true;
    if (mistakes >= 8)
    {
        return 1;
    }
    for (int i = 0; i < wordLength; i++)
    {
        if (tempNameGuessed[i] != nameToGuess[i])
        {
            check = false;
            return 0;
        }
    }
    if (check == true)
        return 2;
}