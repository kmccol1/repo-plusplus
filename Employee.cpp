
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

