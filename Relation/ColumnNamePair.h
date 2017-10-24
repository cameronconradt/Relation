#pragma once
#include "String.h"
class ColumnNamePair
{
public:
	ColumnNamePair(int column, String inname);
	~ColumnNamePair();
protected:
	int col;
	String name;
};

