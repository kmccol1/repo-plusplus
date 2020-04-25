//****************************************************************************************************
//
//              File:                                   Employee.cpp
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
//              This file contains the parent class implementations.
//
//              Other files required:
//                      1. ProductionWorker.h - Child class declaration.
//                      2. Employee.h - Parent class declaration.
//                      3. ProductionWorker.cpp - child class implementation.
//						4. Driver.cpp - application program driver class.
//		 
//		
//****************************************************************************************************

#include <iostream>
using namespace std;
#include "Employee.h"

//****************************************************************************************************

Employee :: Employee ( )
{
	strcpy_s ( this -> empName , 4 , "***" );
	strcpy_s ( this -> empNum , 4 , "***" );
	this -> hireDate = 1900;
}

//****************************************************************************************************

Employee :: Employee( char empName [ 81 ] , char empNum [ 10 ] , int date )
{
	strcpy_s ( this -> empName , 81 , empName );
	strcpy_s ( this -> empNum , 10 , empNum );
	this -> hireDate = date;
}

//****************************************************************************************************

void Employee :: setEmpName(char empName[81])
{
	strcpy_s ( this -> empName , 81 , empName );
}

//****************************************************************************************************

void Employee :: setEmpNum ( char empNum [ 10 ] )
{
	strcpy_s ( this -> empNum , 10 , empNum );
}

//****************************************************************************************************

void Employee :: setHireDate ( int year )
{
	this -> hireDate = year;
}

//****************************************************************************************************

char * Employee :: getEmpName ( )
{
	return this -> empName;
}

//****************************************************************************************************

char * Employee :: getEmpNum ( )
{
	return this -> empNum;
}

//****************************************************************************************************

int Employee :: getHireDate ( )
{
	return this -> hireDate;
}

//****************************************************************************************************

void Employee :: displayAttributes ( )
{
	cout << this -> empName << this -> empNum << this -> hireDate << endl;
}

//****************************************************************************************************

