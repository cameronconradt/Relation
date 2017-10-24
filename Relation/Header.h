#pragma once
#include "String.h"
#include <set>
class Header
{
public:
	Header(set<String> incolumnNames);
	~Header();
protected:
	set<String> columnNames;
};

