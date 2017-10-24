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
protected:
	string type;
	string text;
	int line;
};