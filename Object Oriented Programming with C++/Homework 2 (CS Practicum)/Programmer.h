#pragma once
#include "Employee.h"

class Programmer:virtual public Employee
{
public:
	Programmer(const char* name, int practise,int numOfPrograms);
	virtual int getSalary() const;
	virtual Employee* clone() const { return new Programmer(*this); };
private:
	int _numOfPrograms;
	
};

