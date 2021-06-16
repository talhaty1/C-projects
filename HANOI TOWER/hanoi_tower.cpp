#include <iostream>
using namespace std;

void tower(int , char , char , char );

int main()
{
	char a='A',b='B',c='C';
	int n;
	cout<<"\aRULES:\n1. we can only move one disk at a time\n";
	cout<<"2. Smallest disk must be placed at the bottom and largest at the top\n";
	cout<<"3. we start counting the disks from smallest to largest\n";
	cout<<"4. All disks are placed at position 'A' and we have to move them to position 'C'\n\n\n";
	cout<<"\tI will show you the steps to move each disk at a time from  tower'A' to tower'C'\n\n";
	cout<<"\t\t\t\tA\t\tB\t\tC\n\n\n";
	cout<<"Enter number of disks on tower A: ";
	
	cin>>n;
	cout<<'\n';
	tower(n , a , b , c);
}

void tower(int n , char a , char b , char c)
{
	if (n==1)
	{
		cout<<"\t\tMove disk "<<n<<" from "<<a<<" to "<<c<<'\n';
	}
	else
	{
		tower(n-1,a,c,b);
		cout<<"\t\tMove disk "<<n<<" from "<<a<<" to "<<c<<'\n';
		tower(n-1,b,a,c);
	}
}
