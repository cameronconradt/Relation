#pragma once
#include "String.h"
#include <list>
class Row
{
public:
	Row(list<String> invalues);
	~Row();
protected:
	list<String> values;
};

