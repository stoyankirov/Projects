#include "pch.h"
#include "Comics.h"


Comics::Comics(const char* title, unsigned year, double price, const char* author, Periodicity period) :PrintEdition(title, year, price), Book(title, year, price, author), Magazine(title, year, price, period)
{}

void Comics::print() const
{
	PrintEdition::print();
	Book::printOwn();
	Magazine::printOwn();
}
