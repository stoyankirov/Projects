#include "pch.h"
#include<string>
#include<stack>
#include<sstream>
#include <iostream>
using namespace std;

string decompress(const string& input)
{
	istringstream str(input);
	stack<int> numbers;
	stack<string> words;

	int number;
	char letter;

	ostringstream currentWord("", ios::app | ios::out);
	string toAdd;

	while (!str.eof())
	{
		int peek = str.peek();
		if (peek >= '0'&&peek <= '9')
		{	
			words.push(currentWord.str());
			currentWord.str("");
			str >> number;
			numbers.push(number);
		}
		else if (peek == '(')
		{
			str.ignore();
		}
		else if (peek == ')')
		{
			str.ignore();
			number = numbers.top();
			numbers.pop();
			toAdd = currentWord.str();
			for (int i = 1; i < number; i++)
			{
				currentWord << toAdd;
			}
			toAdd = currentWord.str();
			currentWord.str(words.top());
			words.pop();
			currentWord << toAdd;
		}
		else if (peek >= 'a'&&peek <= 'z' || peek >= 'A'&&peek <= 'Z')
		{
			str >> letter;
			currentWord << letter;
		}
	}
	while (!numbers.empty())
	{
		number = numbers.top();
		numbers.pop();
		toAdd = currentWord.str();
		for (int i = 1; i < number; i++)
		{
			currentWord << toAdd;
		}
		toAdd = currentWord.str();
		currentWord.str(words.top());
		words.pop();
		currentWord << toAdd;
	}
	return currentWord.str();
}

int main(int argc, char const *argv[])
{
	std::string input = "3(a4(b))";
	std::cout << decompress(input) << std::endl;

	while (std::cin >> input)
	{
		std::cout << decompress(input) << std::endl;
	}

	return 0;
}