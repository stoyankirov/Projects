#include "stdafx.h"
#include <cassert>
#include "Programmer.h"


Programmer::Programmer(const char* name, int practise, int numOfPrograms) :Employee(name, practise)
{
	assert(numOfPrograms >= 0);
	setNumOfPrograms(numOfPrograms);
}
int Programmer::getSalary() const
{
	return _numOfPrograms + 200;
}
void Programmer::setNumOfPrograms(int num)
{
	_numOfPrograms = num;
}
int Programmer::getNumOfPrograms() const
{
	return _numOfPrograms;
}
