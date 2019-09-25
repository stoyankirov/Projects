#include "stdafx.h"
#include <cassert>
#include "Programmer.h"


Programmer::Programmer(const char* name, int practise, int numOfPrograms) :Employee(name, practise)
{
	assert(numOfPrograms >= 0);
	_numOfPrograms = numOfPrograms;
}
int Programmer::getSalary() const
{
	return _numOfPrograms + 200;
}