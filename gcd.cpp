#include <iostream>
#include <fstream>
using namespace std;

//****************************************************************************************************

int findGCD(int a, int b);
void display(int a, int b, int gcd);

//****************************************************************************************************

int main()
{
	int num1,
		num2,
		gcd;

	fstream fin ("gcdfile.txt");

	while (fin >> num1 >> num2)
	{
		gcd = findGCD(num1, num2);
		display(num1, num2, gcd);
		cout << endl;
	}

	cout << "Good bye" << endl;
	return 0;
}

//****************************************************************************************************

int findGCD(int a, int b)
{
	int result;

	if ((a % b) != 0)
		result = findGCD(b, (a % b));
	else
		result = b;

	return result;
}

//****************************************************************************************************

void display(int a, int b, int gcd)
{
	cout << "GCD of " << a << " and " << b << " is " << gcd << endl;
}

//****************************************************************************************************

/*




*/
