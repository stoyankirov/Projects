#pragma once
#include "Programmer.h"
#include "Sales.h"

class Manager:public Programmer,public Sales
{
	public:
		Manager(const char* name, int practise, int numOfPrograms, int numOfSales,const char* nickname,int numOfWins);
		Manager(const Manager& other);
		Manager& operator=(const Manager& other);

		void setNickname(const char* nickname);
		void setNumOfWins(int numOfWins);

		const char* getNickname() const;
		int getNumOfWins() const;

		virtual int getSalary() const;
		virtual Employee* clone() const { return new Manager(*this); };

		~Manager();
	private:
		void copyOwn(const Manager& other);
		void deleteOwn();
		char* _nickname;
		int _numOfWins;
};

