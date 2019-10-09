#include "pch.h"
#include<iostream>
#include "Student.h"
using namespace std;

Student::Student(const char* name, const char* date, int facnum, double grade)
	:Person(name, date)
{
	_facnum = facnum;
	if (grade >= 2 && grade <= 6) _grade = grade;
	else _grade = 0;
}
double Student::getGrade() const
{
	return _grade;
}
void Student::print() const
{
	Person::print();
	cout << "Faculty number: " << _facnum << endl
		<< "Grade: " << _grade << endl;
}

