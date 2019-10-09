#pragma once
class PrintEdition
{
	public:
		PrintEdition(const char* title, int yearOfPublishing, double price);
		PrintEdition(const PrintEdition& other);
		PrintEdition& operator=(const PrintEdition& other);
		~PrintEdition();

		const char* getTitle() const;
		int getYearOfPublishing() const;
		double getPrice() const;

		void setTitle(const char* title);
		void setYearOfPublishing(int yearOfPublishing);
		void setPrice(double price);

		void print() const;
	private:

		void copyEdition(const PrintEdition& other);
		void deleteEdition();

		char* _title;
		int _yearOfPublishing;
		double _price;
};

