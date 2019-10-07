#include "stdafx.h"
#include "string.h"
#include <cassert>
#include "Manager.h"


Manager::Manager(const char* name, int practise, int numOfPrograms, int numOfSales, const char* nickname, int numOfWins) :
		 Employee(name, practise),
		 Programmer(name, practise, numOfPrograms),
		 Sales(name, practise, numOfSales),
		 _nickname(NULL)
{
	setNickname(nickname);
	setNumOfWins(numOfWins);
}
Manager::Manager(const Manager& other):Employee(other),Programmer(other),Sales(other),_nickname(NULL)
{
	copyOwn(other);
}
Manager& Manager::operator=(const Manager& other)
{
	if (this != &other)
	{
		Programmer::operator=(other);
		Sales::operator=(other);
		deleteOwn();
		copyOwn(other);
	}
	return *this;
}
void Manager::setNickname(const char* nickname)
{
	assert(nickname != NULL);
	delete[] _nickname;
	_nickname = new char[strlen(nickname) + 1];
	assert(_nickname != NULL);
	strcpy(_nickname, nickname);
}
void Manager::setNumOfWins(int numOfWins)
{
	assert(numOfWins >= 0);
	_numOfWins = numOfWins;
}
const char* Manager::getNickname() const
{
	return _nickname;
}
int Manager::getNumOfWins() const
{
	return _numOfWins;
}
int Manager::getSalary() const
{
	return _numOfWins * 3 + 1000;
}
Manager::~Manager()
{
	deleteOwn();
}
void Manager::copyOwn(const Manager& other)
{
	setNickname(other._nickname);
	setNumOfWins(other._numOfWins);
}
void Manager::deleteOwn()
{
	delete[] _nickname;
}
