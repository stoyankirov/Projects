#include "pch.h
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool correctBrackets(const string& expr)
{
	stack<char> temp;
	for (char a : expr)
	{
		switch (a) 
		{
			case ')':
				if (!temp.empty() && temp.top() == '(')
				{
					temp.pop();
				}
				else
				{
					return false;
				}
			case '(':
				temp.push(')');
				break;
			case ']':
				if (!temp.empty() && temp.top() == '[')
				{
					temp.pop();
				}
				else
				{
					return false;
				}
			case '[' :
				temp.push('[');
				break;

		}
	}
	if (temp.empty()) return true;
}
int main() 
{
	string input;
	cin >> input;
	cout << boolalpha << correctBrackets(input) << endl;
}