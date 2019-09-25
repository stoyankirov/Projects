#pragma once
#include "Employee.h"

class Sales:virtual public Employee
{
	public:
		Sales(const char* name, int practise,int numOfSales);
		virtual int getSalary() const;
		virtual Employee* clone() const { return new Sales(*this); };
	private:
		int _numOfSales;
};

