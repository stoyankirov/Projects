#pragma once
#include "PrintEdition.h"

class Book:virtual public PrintEdition
{
	public:
		Book(const char* title, int yearOfPublishing, double price, const char* author);
		Book(const Book& other);
		Book& operator=(const Book& other);
		~Book();

		void setAuthor(const char* author);

		const char* getAuthor() const;
	
		void print() const;

	protected:
		void printOwn() const;

	private:
		char* _author;
};

