#include "pch.h"
#include "Professor.h"
#include<iostream>
#include<cassert>
#include<string.h>
using namespace std;

Professor::Professor(const char* name, const char* date, const char* subject, const Student* arr, int arrNum) :Person(name, date), _subject(NULL)
{
	setSubject(subject);
	setArr(arr, arrNum);
}
Professor::Professor(const Professor& other) : Person(other), _subject(NULL)
{
	setSubject(other._subject);
	setArr(other._arr, other._arrNum);
}
Professor& Professor::operator=(const Professor& other)
{
	if (this != &other)
	{
		Person::operator =(other);
		setSubject(other._subject);
		setArr(other._arr, other._arrNum);
	}
	return *this;
}
void Professor::setSubject(const char* subject)
{
	assert(subject != NULL);
	delete[] _subject;
	_subject = new char[strlen(subject) + 1];
	assert(_subject != NULL);
	strcpy(_subject, subject);
}
void Professor::setArr(const Student* arr, int arrNum)
{
	delete[] _arr;
	_arrNum = arrNum;
	_arr = new Student[_arrNum];

	for (int i = 0; i < _arrNum; i++)
		_arr[i] = arr[i];
}
const char* Professor::getSubject() const
{
	return _subject;
}
int Professor::getNumStudents() const
{
	return _arrNum;
}
void Professor::printOwn() const
{
	cout << "Subject: " << _subject << endl;
	for (int i = 0; i < _arrNum; i++)
		_arr[i].print();
}
void Professor::print() const
{
	Person::print();
	printOwn();
}
Student Professor::findHighestGrades() const
{
	int max = 0;
	for (int i = 1; i < _arrNum; i++)
		if (_arr[i].getGrade() > _arr[max].getGrade()) max = i;
	return _arr[max];
}
Professor::~Professor()
{
	delete[] _subject;
	delete[] _arr;
	_arr = NULL;
}
