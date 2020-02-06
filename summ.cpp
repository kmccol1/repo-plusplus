#include <iostream>
using namespace std;

//****************************************************************************************************

int calcSummation ( int num );
void displaySum ( int num , int sum );

//****************************************************************************************************

int main()
{
	int numInput;
	int sum;
	char flag = 'y';

	while ( toupper( flag ) == 'Y' )
	{
		do
		{
			cout << "Please enter a non-negative integer: " << endl;
			cin >> numInput;
		} 
		while (numInput < 0);

		sum = calcSummation ( numInput );
		displaySum( numInput, sum );
		cout << "Continue? (y/n): " << endl;
		cin >> flag;
		cout << endl;
	}

	cout << "Good bye" << endl;

	return 0;
}

//****************************************************************************************************

int calcSummation ( int num )
{
	int result;

	if ( num > -1 )
		result = num + calcSummation ( num - 1 );
	else
		result = 0;

	return result;
}

//****************************************************************************************************

void displaySum ( int num , int sum )
{
	cout << "summation " << num << " = " << sum << endl;
}

//****************************************************************************************************

/*

Please enter a non-negative integer:
100
summation 100 = 5050
Continue? (y/n):
y

Please enter a non-negative integer:
5
summation 5 = 15
Continue? (y/n):
Y

Please enter a non-negative integer:
0
summation 0 = 0
Continue? (y/n):
y

Please enter a non-negative integer:
-5
Please enter a non-negative integer:
4
summation 4 = 10
Continue? (y/n):
n

Good bye


*/
