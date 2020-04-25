
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
