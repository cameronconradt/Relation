#include "String.h"



String::String(Token* token)
{
	mytoken = token;
}


String::~String()
{
}
string String::tostring()
{
	return mytoken->gettext();
}
