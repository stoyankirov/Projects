#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Person.h"

class Employee :virtual public Person
{
	public:
		Employee(const char* name = "", const char* date = "", const char* position = "", double salary = 0);
		Employee(const Employee& other);
		Employee& operator=(const Employee& other);

		void setPosition(const char* position);
		void setSalary(double salary);

		const char* getPosition() const;
		double getSalary() const;

		void print() const;

		~Employee();

	protected:
		void printOwn() const;

	private:
		char* _position;
		double _salary;
};

#endif // EMPLOYEE_H_INCLUDED
