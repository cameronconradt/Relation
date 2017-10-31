#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Token
{
public:
	Token(string intype, string intext, int inputline);
	~Token();
	string gettype();
	string gettext();
	string getline();
	bool operator<(const Token rh)
	{
		if (this->text < rh.text)
		{
			return true;
		}
		return false;
	}
protected:
	string type;
	string text;
	int line;
};