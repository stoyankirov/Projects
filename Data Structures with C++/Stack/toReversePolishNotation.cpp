#include "pch.h"
#include<stack>
#include<string.h>
#include <iostream>
using namespace std;
int weight(const char s)
{	
	switch (s) {
		case '+': return 2; break;
		case '-': return 2; break;
		case '*': return 1; break;
		case '/': return 1; break;
		case '^': return 0; break;
	}
}
void translate(char* s, char* ns)
{
	stack<char> help;
	int i = 0, j = -1, n = strlen(s);
	help.push('(');
	char x;
	while (i < n)
	{
		if (s[i] >= '0'&&s[i] <= '9' || s[i] >= 'a'&&s[i] <= 'z')
		{
			j++;
			ns[j] = s[i];
		}
		else if (s[i] == '(') 
		{
			help.push('(');
		}
		else if (s[i] == ')')
		{
			help.pop(x);
			while (x != '(')
			{
				j++;
				ns[j] = x;
				help.pop(x);
			}
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
		{
			help.pop(x);
			while (x != '('&&t(x) <= weight(s[i]))
			{
				j++;
				ns[j] = x;
				help.pop(x);
			}
			help.push(x);
			help.push(s[i]);
		}
		i++;
	}
	help.pop(x);
	while (x != '(')
	{
		j++;
		ns[j] = x;
		help.pop(x);
	}
	j++;
	ns[j] = '\0';
}
int main()
{

}

