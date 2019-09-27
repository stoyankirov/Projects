#include "stdafx.h"
#include <cassert>
#include "Sales.h"


Sales::Sales(const char* name, int practise, int numOfSales) :Employee(name, practise)
{
	assert(numOfSales >= 0);
	setNumOfSales(numOfSales);
}
int Sales::getSalary() const
{
	return _numOfSales * 3 + 100;
}
void Sales::setNumOfSales(int num)
{
	_numOfSales = num;
}
int Sales::getNumOfSales() const
{
	return _numOfSales;
}
