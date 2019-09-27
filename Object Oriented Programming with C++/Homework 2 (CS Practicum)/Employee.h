#pragma once
class Employee
{
	public:
		Employee(const char* name,int practise);
		Employee(const Employee& other);
		Employee& operator=(const Employee& other);

		void setName(const char* name);
		void setPractise(int practise);

		const char* getName() const;
		int getPractise() const;

		virtual int getSalary() const;
		virtual Employee* clone() const { return new Employee(*this); };
		virtual ~Employee();
	private:
		void copyEmployee(const Employee& other);
		void deleteEmployee();
		char* _name;
		int _practise;
};

