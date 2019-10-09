#pragma once
#include "Book.h"
#include "Magazine.h"

class Comics: public Book, public Magazine
{
	public:
		Comics(const char* title, unsigned year, double price, const char* author, Periodicity period);
		
		void print() const;
};

