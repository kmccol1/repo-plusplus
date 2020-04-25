//****************************************************************************************************
//
//              File:                                   Driver.cpp
//		
//              Student:                                Kyle McColgan
//
//              Assignment:                             Assignment #6
//
//              Course Name:                            Principles of Programming Languages
// 
//              Course Number:                          COSC 3810 - 01
//
//              Due:                                    April 22nd, 2020
//
//
//              This file contains the driver class using inherited class.
//
//              Other files required:
//                      1. ProductionWorker.h - Child class declaration
//                      2. Employee.h - Parent class declaration
//                      3. ProductionWorker.cpp - child class implementation
//						4. Employee.cpp - parent class implementation
//		 
//		
//****************************************************************************************************

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