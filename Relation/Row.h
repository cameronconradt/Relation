#pragma once
#include "String.h"
#include "ColColKey.h"
#include "ColValueKey.h"
#include <list>
class Row
{
public:
	Row(list<String> invalues);
	~Row();
	bool satisfies(ColColKey colColKey);
	bool satisfies(ColValueKey colValueKey);
protected:
	list<String> values;
};

