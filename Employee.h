//****************************************************************************************************
//
//              File:                                   Employee.h
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
//              This file contains the parent class declaration.
//
//              Other files required:
//                      1. ProductionWorker.h - Child class declaration.
//                      2. Driver.cpp - application program driver class.
//                      3. ProductionWorker.cpp - child class implementation.
//						4. Employee.cpp - parent class implementation.
//		 
//		
//****************************************************************************************************

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

//****************************************************************************************************

class Employee
{
	private:
		char empName[81];
		char empNum[10];
		int hireDate;

	public:
		Employee ( );
		Employee ( char name [ 81 ] , char empNum [ 10 ] , int date );

		void setEmpName ( char empName [ 81 ] );
		void setEmpNum ( char empNum [ 10 ] );
		void setHireDate ( int year );

		char * getEmpName ( );
		char * getEmpNum ( );
		int getHireDate ( );

		virtual void displayAttributes ( );
};

//****************************************************************************************************

#endif
