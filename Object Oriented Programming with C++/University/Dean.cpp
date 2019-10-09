#include "pch.h"
#include "Dean.h"
#include<iostream>
using namespace std;

Dean::Dean(const char* name, const char* date, const char* position,
	double salary, const char* subject, const Student* arr, int arrNum) :
	Person(name, date), Employee(name, date, position, salary), Professor(name, date, subject, arr, arrNum)
{}
Dean::Dean(const Dean& other) : Person(other), Employee(other), Professor(other)
{}
Dean& Dean::operator=(const Dean& other)
{
	if (this != &other)
	{
		Employee::operator=(other);
		Professor::operator=(other);
	}
	return *this;
}
void Dean::print() const
{
	Person::print();
	Professor::printOwn();
	Employee::printOwn();
}
Dean::~Dean()
{}
