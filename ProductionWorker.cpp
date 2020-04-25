//****************************************************************************************************
//
//              File:                                   ProductionWorker.cpp
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
//              This file contains the child class implementations.
//
//              Other files required:
//                      1. ProductionWorker.h - Child class declaration.
//                      2. Employee.h - Parent class declaration.
//                      3. Driver.cpp - application driver program.
//						4. Employee.cpp - parent class implementation.
//		 
//		
//****************************************************************************************************

#include <iostream>
using namespace std;
#include "ProductionWorker.h"

//****************************************************************************************************

ProductionWorker :: ProductionWorker ( ) : Employee :: Employee ( )
{
	this -> hours = 40;
	this -> payRate = 9.5;
}

//****************************************************************************************************

ProductionWorker :: ProductionWorker ( int hours , double rate ) : Employee :: Employee ( )
{
	this -> hours = hours;
	this -> payRate = rate;
}

//****************************************************************************************************

void ProductionWorker :: setHours ( int hours )
{
	this -> hours = hours;
}

//****************************************************************************************************

void ProductionWorker :: setPayRate ( double rate )
{
	this -> payRate = rate;
}

//****************************************************************************************************

int ProductionWorker :: getHours ( )
{
	return this -> hours;
}

//****************************************************************************************************

double ProductionWorker :: getPayRate ( )
{
	return this -> payRate;
}

//****************************************************************************************************

void ProductionWorker :: displayAttributes ( )
{
	double totalPay;
	totalPay = this -> hours * this -> payRate;
	cout << this -> getEmpName ( ) << "\t" << this -> getEmpNum ( ) 
		 << "\t" << this -> getHireDate ( ) << "\t" << totalPay << endl;
}

//****************************************************************************************************