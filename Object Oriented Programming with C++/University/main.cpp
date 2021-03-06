#include "pch.h"
#include<iostream>
#include "Student.h"
#include "Employee.h"
#include "Professor.h"
#include "Dean.h"

using namespace std;

void bestStudent(const Professor& professor)
{
	cout << "Best student: " << endl;
	professor.findHighestGrades().print();
}

bool isInArray(const Professor* arr, int arrNum, const Dean searched)
{
	for (int i = 0; i < arrNum; i++)
		if (strcmp(searched.getName(), arr[i].getName()) == 0 && strcmp(searched.getDate(), arr[i].getDate()) == 0 &&
			strcmp(searched.getSubject(), arr[i].getSubject()) == 0) return true;
	return false;
}

int main()
{
	Student Ivan("Ivan", "01011881", 81620, 5.38);
	Ivan.print();
	cout << "==============================================" << endl;

	Employee Atanas("Atanas", "23121998", "WEB Developer", 3800);
	Atanas.print();
	cout << "==============================================" << endl;

	Student first("Stoyan", "07021998", 81610, 5.5);
	Student second("Georgi", "25031998", 81555, 5.3);
	Student third("Maria", "30011998", 81608, 5.0);

	cout << "==============================================" << endl;

	Student arr[3];

	arr[0] = first;
	arr[1] = second;
	arr[2] = third;

	cout << "==============================================" << endl;

	Professor Magda("Todorova", "30101945", "OOP", arr, 3);

	cout << "==============================================" << endl;

	Magda.print();

	cout << "==============================================" << endl;

	bestStudent(Magda);

	cout << "==============================================" << endl;

	Dean Parvanov("Parvanov", "01021960", "Dean", 2000, "DIS");

	cout << "==============================================" << endl;

	Parvanov.print();

	cout << "==============================================" << endl;

	return 0;
}
