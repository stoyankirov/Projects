#include "stdafx.h"
#include <cassert>
#include "Sales.h"


Sales::Sales(const char* name, int practise, int numOfSales) :Employee(name, practise)
{
	assert(numOfSales >= 0);
	_numOfSales = numOfSales;
}
int Sales::getSalary() const
{
	return _numOfSales * 3 + 100;
}
