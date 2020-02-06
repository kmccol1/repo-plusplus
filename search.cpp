#include <iostream>
using namespace std;

bool binSearch ( int list [] , int size , int searchKey , int & numCompares )
{
	bool result = false;

	numCompares = 0;
	
	int min = 0,
		max = size+1,
		middle;

	while( (min < max ))
	{
		middle = (min+max)/2; 

		if ( list[middle] >= searchKey )
			max = middle;
		else
			min = middle + 1;
		
		numCompares ++;
	}

	if ( list[max] == searchKey )
		result = true;

	return result;
}

bool ordSearch ( int list[] , int size , int searchKey , int & numCompares)
{
	bool result = false;

	numCompares = 0;

	int count = 0;
	while ( ( count < size ) && ( list[count] < searchKey ) )
	{
		count += 1;
		numCompares += 1;
	}

	if ( (count < size) && ( list[count] == searchKey ) )
		result = true;

	return result;
}

int main()
{


	int list [10] = {1,2,3,4,5,6,7,8,9,10};
	int size = 10;
	int searchKey = 5;
	int numCompares = 0;

	cout << binSearch ( list , size , searchKey , numCompares ) << endl;

	cout << "Compares: " << numCompares << endl;
	return 0;
}
