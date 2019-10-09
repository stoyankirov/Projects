#include "pch.h"
#include "Magazine.h"
#include "assert.h"
#include<iostream>

using namespace std;

Magazine::Magazine(const char* title, int yearOfPublishing, double price, const Periodicity period):PrintEdition(title, yearOfPublishing, price)
{
	setPeriod(period);
}
Magazine::Periodicity Magazine::getPeriod() const
{
	return _period;
}
const char* Magazine::getPeriodicityAsText() const
{
	return periodicityAsText[_period];
}
void Magazine::setPeriod(const Periodicity period)
{
	assert(period >= Periodicity::YEARLY && period <= DAILY);
	_period = period;
}
void Magazine::printOwn() const
{
	cout << "Periodicity: " << getPeriodicityAsText() << endl;
}
void Magazine::print() const
{
	PrintEdition::print();
	printOwn();
}

		
