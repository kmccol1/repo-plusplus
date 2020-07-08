//****************************************************************************************************
//
//		File:					sim3q3s.cpp
//
//		This file contains the simulation application program.
//
//		Other files required
//			1. Customer.h - Customer header file
//			2. Server.h - Server header file
//			3. Queue.h - Doubly-linked queue implementation
//		
//
//****************************************************************************************************

#include <fstream>
#include <iostream>
#include "Customer.h"
#include "Server.h"
#include "Queue.h"
using namespace std;

//****************************************************************************************************

int fillCustomerArray( Customer arr [ ] );
int findMinQ ( Queue < Customer > lines [ ] );
void processCustomers(Customer arr [ ] , Queue < Customer > lines [ ] , const int time, const int totalCust ,  int & currentCust , ofstream & trace);
void processServers(Server servers  [ ] , Queue < Customer > lines [ ]  , const int time , ofstream & trace );
bool isAllDone(Queue < Customer > lines [ ]  , Server servers [ ] , const int totalCust , const int currentCust );

//****************************************************************************************************

int main()
{
	Customer custArray [100];
	Queue < Customer > custQueue [3]; 
	Server servers [3];	

	int currentCust = 0,
		totalCust = -1,
		time = -1;

	ofstream trace ("trace.txt" );

	totalCust = fillCustomerArray(custArray);

	cout << "TotalCust: " << totalCust << endl;
	cout << "CurrentCust: " << currentCust << endl;

	while ( !isAllDone(custQueue , servers , totalCust , currentCust ) )
	{
		time += 1;
		trace << "\nt = " << time << endl;
		cout << "Before:" << currentCust << endl;

		processCustomers(custArray, custQueue, time , totalCust , currentCust , trace);
		cout << "After:" << currentCust << endl;
		processServers(servers, custQueue , time , trace);		
	}

	cout << "All customers processed in " << time << " minutes." << endl;

	trace.close();

	return 0;
}

//****************************************************************************************************

int fillCustomerArray( Customer arr [ ] )
{
	Customer temp;
	ifstream fin;
	int totalCust = 0;

	fin.open("C:\Users\Kyle\Desktop\ASSIGNMENT13\customerList.txt");
	if (fin.is_open())
	{

		while (totalCust < 49)
		{
			fin >> temp.id;
			fin >> temp.arrivalTime;
			fin >> temp.serviceTime;

			arr[totalCust] = temp;

			cout << "TotalCust: " << totalCust << endl;
			totalCust++;
		}
	}
	else
		cout << "Not open" << endl;

	fin.close();

	return totalCust;
}

//****************************************************************************************************

int findMinQ ( Queue < Customer > lines [ ] )
{
	int minQ = 0;
	int qSize[3];

	for (int i = 0; i < 3; i++)
	{
		qSize[i] = lines[i].getNumValues();
	}

	if ( qSize[1] < qSize[2] )
		minQ = 1;
	if ( qSize [ 2 ] < qSize [0] )
		minQ = 2;

	return minQ;
}

//****************************************************************************************************

//currenntCust == 100 after 1 loop wtf
void processCustomers(Customer arr [ ] , Queue < Customer > lines [ ] , const int time , const int totalCust , int & currentCust , ofstream & trace )
{
	int minQ;

	while ( (currentCust < totalCust) && ( ( arr[currentCust].arrivalTime ) == time) ) 
	{

		//ALL HAVE ARRIVAL TIME == 0
		cout << "Arrival Time: " << arr[currentCust].arrivalTime << endl;
		minQ = findMinQ ( lines );

		if ( lines[ minQ ].enqueue( arr[currentCust] ) )
		{
			trace << "cust-id #" << arr[currentCust].id << " added to Q" << minQ <<  endl;
			cout << "Call:" << currentCust << endl;
			currentCust += 1;
		}
		else
			trace << "Queue empty";
	}

}

//****************************************************************************************************

void processServers(Server servers [ ] , Queue < Customer > lines [ ] , const int time , ofstream & trace)
{
	const int NUM_SERVERS = 3;
	
	Customer temp;

	for (int i = 0; i < NUM_SERVERS; i++)
	{
		
		if ( (!servers[i].busy) || ( time >= servers[i].endTime ) )
		{
			if ( lines[i].dequeue(temp) )
			{
				servers[i].custID = temp.id;
				servers[i].endTime = time + temp.serviceTime;
				servers[i].busy = true;

				trace << "S" << i << " start serving cust-id #" << servers[i].custID << ", service length = " << temp.serviceTime
					  << ", service ends at t = " << servers[i].endTime << endl;
			}
			else
			{
				servers[i].busy = false;
				trace << "S" << i << " not busy" << endl;
			}		
		}
		else
			trace << "S" << i << " serving cust-id #" << servers[i].custID << " until t = " << servers[i].endTime << endl;
	}
}

//****************************************************************************************************

bool isAllDone ( Queue < Customer > lines [ ] , Server servers [ ] ,  const int currentCust , const int totalCust ) 
{
	return ( (lines[0].isEmpty() ) && ( lines[1].isEmpty()) && ( lines[2].isEmpty()) && (currentCust == totalCust) && (!servers[0].busy) && (!servers[1].busy) && (!servers[2].busy));
}

//****************************************************************************************************

/*

All customers processed in 58 minutes.


*/