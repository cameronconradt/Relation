#include "Parameter.h"
#include <string>
class String :
	public Parameter
{
public:
	String(Token* token);
	String();
	~String();
	string tostring();
protected:
	Token* mytoken;
};

