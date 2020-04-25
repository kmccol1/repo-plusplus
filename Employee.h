***************************************************************************************************

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
