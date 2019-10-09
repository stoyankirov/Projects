#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED

#include "Person.h"
#include "Student.h"
#include<iostream>

class Professor :virtual public Person
{
	public:
		Professor(const char* name = "", const char* date = "", const char* subject = "", const Student* arr = NULL, int arrNum = 0);
		Professor(const Professor& other);
		Professor& operator=(const Professor& other);

		void setSubject(const char* subject);
		void setArr(const Student* arr, int arrNum);

		const char* getSubject() const;
		int getNumStudents() const;

		void print() const;

		Student findHighestGrades() const;

		~Professor();

	protected:
		void printOwn() const;
	private:
		char* _subject;
		Student* _arr;
		int _arrNum;
};

#endif // PROFESSOR_H_INCLUDED
