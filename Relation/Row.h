#pragma once
#include "String.h"
#include "ColColKey.h"
#include "ColValueKey.h"
#include <set>
#include <list>
class Row
{
public:
	Row(list<String> invalues);
	Row(Row* inrow);
	~Row();
	bool satisfies(ColColKey colColKey);
	bool satisfies(ColValueKey colValueKey);
	void removeAllOtherColumnsBut(set<int> columnsToKeep);
	list<String> getvalues();
protected:
	list<String> values;
};

