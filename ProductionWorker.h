//****************************************************************************************************
//
//              File:                                   ProductionWorker.h
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
//              This file contains the child class declaration, inherits from Employee.
//
//              Other files required:
//                      1. Driver.cpp - application program driver class.
//                      2. Employee.h - Parent class declaration.
//                      3. ProductionWorker.cpp - child class implementation.
//						4. Employee.cpp - parent class implementation.
//		 
//		
//****************************************************************************************************

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

//****************************************************************************************************

#include "Employee.h"

//****************************************************************************************************

class ProductionWorker : public Employee
{
	private:
		int hours;
		double payRate;

	public:
		ProductionWorker ( );
		ProductionWorker ( int hours , double rate );

		void setHours ( int hours );
		void setPayRate ( double rate );

		int getHours ( );
		double getPayRate ( );

		void displayAttributes ( ) override;
};

//****************************************************************************************************

#endif