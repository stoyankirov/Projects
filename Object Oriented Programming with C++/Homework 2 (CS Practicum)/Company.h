#pragma once
#include "Employee.h"
#include "Sales.h"
#include "Programmer.h"
#include "Manager.h"

typedef Employee* EmployeePtr;

class Company
{
	public:
		Company(const EmployeePtr *arr, int num);
		Company(const Company& other);
		Company& operator=(const Company& other);
		~Company();

		void addEmployee(const Employee& other);
		void removeSales(int maxSalary);
		void removeProgrammer(int maxSalary);
		void removeManager(int maxSalary);
		void removeEmployee(int maxSalary);
	private:
		void copyCompany(const Company& other);
		void deleteCompany();
		EmployeePtr * _arr;
		int _num;
};

