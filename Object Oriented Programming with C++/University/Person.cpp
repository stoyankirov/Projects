#include "pch.h"
#include<iostream>
#include<string.h>
#include<cassert>
#include "Person.h"

using namespace std;

Person::Person(const char* name, const char* date) :_name(NULL)
{
	setName(name);
	setDate(date);
}
Person::Person(const Person& other) :Person(other._name, other._date)
{}
Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		setName(other._name);
		setDate(other._date);
	}
	return *this;
}
void Person::setName(const char* name)
{
	assert(name != NULL);
	delete[] _name;
	_name = new char[strlen(name) + 1];
	assert(_name != NULL);
	strcpy(_name, name);
}
void Person::setDate(const char* date)
{
	strcpy(_date, date);
}
const char* Person::getName() const
{
	return _name;
}
const char* Person::getDate() const
{
	return _date;
}
void Person::print() const
{
	cout << "Name: " << _name << endl
		<< "Date: " << _date << endl;
}
Person::~Person()
{
	delete[] _name;
	_name = NULL;
}

