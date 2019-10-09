#include "pch.h"
#include "PrintEdition.h"
#include "assert.h"
#include "string.h"
#include "iostream"

using namespace std;


PrintEdition::PrintEdition(const char* title, int yearOfPublishing, double price) :_yearOfPublishing(yearOfPublishing)
{
	setTitle(title);
	setPrice(price);
}
PrintEdition::PrintEdition(const PrintEdition& other)
{
	copyEdition(other);
}
PrintEdition& PrintEdition::operator=(const PrintEdition& other)
{
	if (this != &other)
	{
		deleteEdition();
		copyEdition(other);
	}
	return *this;
}
PrintEdition::~PrintEdition()
{
	deleteEdition();
}
const char* PrintEdition::getTitle() const
{
	return _title;
}
int PrintEdition::getYearOfPublishing() const
{
	return _yearOfPublishing;
}
double PrintEdition::getPrice() const
{
	return _price;
}
void PrintEdition::setTitle(const char* title)
{
	assert(title != NULL);
	delete _title;
	_title = new char[strlen(title) + 1];
	assert(_title != NULL);
	strcpy(_title, title);
}
void PrintEdition::setYearOfPublishing(int yearOfPublishing)
{
	assert(yearOfPublishing >= 0);
	_yearOfPublishing = yearOfPublishing;
}
void PrintEdition::setPrice(double price)
{
	assert(price >= 0);
	_price = price;
}
void PrintEdition::print() const
{
	cout << "Title: " << _title << endl << "Year of publishing: " << _yearOfPublishing << endl << "Price: " << _price << endl;
}
void PrintEdition::copyEdition(const PrintEdition& other)
{
	setTitle(other._title);
	setYearOfPublishing(other._yearOfPublishing);
	setPrice(other._price);
}
void PrintEdition::deleteEdition()
{
	delete[] _title;
	_title = NULL;
}
