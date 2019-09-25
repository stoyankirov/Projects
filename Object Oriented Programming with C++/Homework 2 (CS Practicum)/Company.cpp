#include "stdafx.h"
#include "Company.h"


Company::Company(const EmployeePtr *arr, int num) :_arr(NULL), _num(0)
{
	_num = num;
	_arr = new EmployeePtr[_num];
	for (int i = 0; i < _num; i++)
		_arr[i] = arr[i]->clone();
}
Company::Company(const Company& other):_arr(NULL),_num(0)
{
	copyCompany(other);
}
Company& Company::operator=(const Company& other)
{
	if (this != &other)
	{
		deleteCompany();
		copyCompany(other);
	}
	return *this;
}
Company::~Company()
{
	deleteCompany();
}
void Company::copyCompany(const Company& other)
{
	_num = other._num;
	_arr = new EmployeePtr[_num];
	for (int i = 0; i < _num; i++)
		_arr[i] = other._arr[i]->clone();
}
void Company::deleteCompany()
{
	for (int i = 0; i < _num; i++)
		delete _arr[i];
	delete[] _arr;
}
void Company::addEmployee(const Employee& other)
{
	_arr[_num] = other.clone();
	_num++;

}
void Company::removeSales(int maxSalary)
{
	for (int i = 0; i < _num; i++)
	{
		Employee* employee = dynamic_cast<Employee*>(_arr[i]);
		if (employee != NULL)
		{
			if (employee->getSalary() > maxSalary)
			{
				delete employee;

				for (int j = i; j < _num - 1; j++)
				{
					_arr[j] = _arr[j + 1];
				}
				_arr[_num - 1] = NULL;
				_num--;
			}
		}
	}
}
void Company::removeProgrammer(int maxSalary)
{
	for (int i = 0; i < _num; i++)
	{
		Programmer* programmer = dynamic_cast<Programmer*>(_arr[i]);
		if (programmer != NULL)
		{
			if (programmer->getSalary() > maxSalary)
			{
				delete programmer;

				for (int j = i; j < _num - 1; j++)
				{
					_arr[j] = _arr[j + 1];
				}
				_arr[_num - 1] = NULL;
				_num--;
			}
		}
	}
}
void Company::removeManager(int maxSalary)
{
	for (int i = 0; i < _num; i++)
	{
		Manager* manager = dynamic_cast<Manager*>(_arr[i]);
		if (manager != NULL)
		{
			if (manager->getSalary() > maxSalary)
			{
				delete manager;

				for (int j = i; j < _num - 1; j++)
				{
					_arr[j] = _arr[j + 1];
				}
				_arr[_num - 1] = NULL;
				_num--;
			}
		}
	}
}
void Company::removeEmployee(int maxSalary)
{
	for (int i = 0; i < _num; i++)
	{
		Employee* employee = dynamic_cast<Employee*>(_arr[i]);
		if (employee != NULL)
		{
			if (employee->getSalary() > maxSalary)
			{
				delete employee;

				for (int j = i; j < _num - 1; j++)
				{
					_arr[j] = _arr[j + 1];
				}
				_arr[_num - 1] = NULL;
				_num--;
			}
		}
	}
}