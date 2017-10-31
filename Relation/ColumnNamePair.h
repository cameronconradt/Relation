#pragma once
#include "String.h"
class ColumnNamePair
{
public:
	ColumnNamePair(int column, String inname);
	~ColumnNamePair();
	int getColumn();
	String getName();
protected:
	int col;
	String name;
};

