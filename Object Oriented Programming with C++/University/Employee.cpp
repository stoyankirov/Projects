#include "pch.h"
#include<iostream>
#include<cassert>
#include<string.h>
#include "Employee.h"
using namespace std;

Employee::Employee(const char* name, const char* date, const char* position, double salary) :Person(name, date), _position(NULL)
{
	setPosition(position);
	setSalary(salary);
}
Employee::Employee(const Employee& other) :Person(other), _position(NULL)
{
	setPosition(other._position);
	setSalary(other._salary);
}
Employee& Employee::operator=(const Employee& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		setPosition(other._position);
		setSalary(other._salary);
	}
	return *this;
}
void Employee::setPosition(const char* position)
{
	assert(position != NULL);
	delete[] _position;
	_position = new char[strlen(position) + 1];
	assert(_position != NULL);
	strcpy(_position, position);
}
void Employee::setSalary(double salary)
{
	assert(salary > 0);
	_salary = salary;
}
const char* Employee::getPosition() const
{
	return _position;
}
double Employee::getSalary() const
{
	return _salary;
}
void Employee::printOwn() const
{
	cout << "Position: " << _position << endl
		<< "Salary: " << _salary << endl;
}
void Employee::print() const
{
	Person::print();
	printOwn();
}
Employee::~Employee()
{
	delete[] _position;
}

