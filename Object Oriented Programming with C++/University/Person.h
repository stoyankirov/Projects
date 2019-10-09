#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

const int DATE_LEN = 9;
class Person
{
	public:
		Person(const char* name = "", const char* date = "");
		Person(const Person& other);
		Person& operator=(const Person& other);

		void setName(const char* name);
		void setDate(const char* date);

		const char* getName() const;
		const char* getDate() const;

		void print() const;

		~Person();

	protected:
		char* _name;
		char _date[DATE_LEN];
};

#endif // PERSON_H_INCLUDED
