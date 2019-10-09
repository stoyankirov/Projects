#include "pch.h"
#include "PrintEdition.h"
#include "Book.h"
#include "assert.h"
#include "string.h"
#include<iostream>

using namespace std;
Book::Book(const char* title, int yearOfPublishing, double price, const char* author) :PrintEdition(title, yearOfPublishing, price)
{
	setAuthor(author);
}
Book::Book(const Book& other):PrintEdition(other)
{
	setAuthor(other._author);
}
Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		PrintEdition::operator=(other);
		setAuthor(other._author);
	}
	return *this;
}
Book::~Book()
{
	delete[] _author;
	_author = NULL;
}
void Book::setAuthor(const char* author)
{
	assert(author != NULL);
	delete[] _author;
	_author = new char[strlen(author) + 1];
	assert(_author != NULL);
	strcpy(_author, author);
}
const char* Book::getAuthor() const
{
	return _author;
}
void Book::printOwn() const
{
	cout << "Author: " << _author << endl;
}
void Book::print() const
{
	PrintEdition::print();
	printOwn();
}


