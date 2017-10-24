#pragma once
#include "SelectionKey.h"
class ColColKey :
	public SelectionKey
{
public:
	ColColKey(int column1, int column2);
	~ColColKey();
protected:
	int col1;
	int col2;
};

