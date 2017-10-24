#pragma once
#include "String.h"
#include <set>
class Header
{
public:
	Header(set<String> incolumnNames);
	~Header();
	set<String> getcolnames();
	void removeAllOtherColumnsBut(set<int> columnsToKeep);
protected:
	set<String> columnNames;
};

