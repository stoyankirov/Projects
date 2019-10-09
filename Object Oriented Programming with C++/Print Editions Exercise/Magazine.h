#pragma once
#include "PrintEdition.h"

class Magazine:virtual public PrintEdition
{	
	public:
		enum Periodicity
		{
			YEARLY,
			MONTHLY,
			WEEKLY,
			DAILY
		};

	public:
		Magazine(const char* title, int yearOfPublishing, double price, const Periodicity period);
	
		Periodicity getPeriod() const;
		const char* getPeriodicityAsText() const;

		void setPeriod(const Periodicity period);

		void print() const;

	protected: 
		void printOwn() const;

	private:
		Periodicity _period;

		const char* periodicityAsText[4] = { "Yearly","Monthly","Weekly","Daily" };
};


