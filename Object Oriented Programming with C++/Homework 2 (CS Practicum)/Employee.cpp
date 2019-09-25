#include "stdafx.h"
#include <string.h>
#include <cassert>
#include "Employee.h"


Employee::Employee(const char* name, int practise) :_name(NULL)
{
	setName(name);
	setPractise(practise);
}
Employee::Employee(const Employee& other):_name(NULL)
{
	copyEmployee(other);
}
Employee& Employee::operator=(const Employee& other)
{
	if (this != &other)
	{
		deleteEmployee();
		copyEmployee(other);
	}
	return *this;
}
void Employee::setName(const char* name)
{
	assert(name);
	delete[] _name;
	_name = new char[strlen(name) + 1];
	assert(_name != NULL);
	strcpy(_name, name);
}
void Employee::setPractise(int practise)
{
	assert(practise >= 0);
	_practise = practise;
}
const char* Employee::getName() const
{
	return _name;
}
int Employee::getPractise() const
{
	return _practise;
}
Employee::~Employee()
{
	deleteEmployee();
}
void Employee::copyEmployee(const Employee& other)
{
	setName(other._name);
	setPractise(other._practise);
}
void Employee::deleteEmployee()
{
	delete[] _name;
	_name = NULL;
}
int Employee::getSalary() const
{
	return _practise * 2 + 500;
}