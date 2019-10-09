#ifndef DEAN_H_INCLUDED
#define DEAN_H_INCLUDED

#include "Employee.h"
#include "Professor.h"

class Dean :public Employee, public Professor
{
	public:
		Dean(const char* name = "", const char* date = "", const char* position = "", double salary = 0, const char* subject = "", const Student* arr = NULL, int arrNum = 0);
		Dean(const Dean& other);
		Dean& operator=(const Dean& other);

		void print() const;

		~Dean();
};

#endif // DEAN_H_INCLUDED
