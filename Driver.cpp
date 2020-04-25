
#include <iostream>
using namespace std;
#include "Employee.h"
#include "ProductionWorker.h"

//****************************************************************************************************

int main ( )
{
	const int TEAM_SIZE = 5;
	ProductionWorker * workers = new ProductionWorker [ TEAM_SIZE ];

	double totalPay = 0;

	for ( int i = 0; i < TEAM_SIZE; i++ )
	{
		workers[i].setHours(workers[i].getHours() + 5);
		workers[i].setPayRate(workers[i].getPayRate() * 1.25);
	}

	for (int i = 0; i < TEAM_SIZE; i++)
	{
		totalPay += (workers[i].getHours() * workers[i].getPayRate());
		cout << endl;
		workers[i].displayAttributes();
		cout << endl;
	}

	cout << "Total pay is: $" << totalPay << endl;

	delete [ ] workers;
	workers = nullptr;

	return 0;
}

//****************************************************************************************************

/*

***     ***     1900    534.375


***     ***     1900    534.375


***     ***     1900    534.375


***     ***     1900    534.375


***     ***     1900    534.375

Total pay is: $2671.88
*/
