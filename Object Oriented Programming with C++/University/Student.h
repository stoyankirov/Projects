#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "Person.h"

class Student :public Person
{
	public:
		Student(const char* name = "", const char* date = "", int facnum = 0, double grade = 0);
		double getGrade() const;
		void print() const;

	private:
		int _facnum;
		double _grade;
};

#endif // STUDENT_H_INCLUDED
