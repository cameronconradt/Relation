#include "Header.h"



Header::Header(set<String> incolumnNames)
{
	columnNames = incolumnNames;
}


Header::~Header()
{
}

set<String> Header::getcolnames()
{
	return columnNames;
}

void Header::removeAllOtherColumnsBut(set<int> columnsToKeep)
{
	int currentcol = 0;
	for (auto i = columnNames.begin(); i != columnNames.end(); i++)
	{
		for (auto j : columnsToKeep)
		{
			if (currentcol == j)
				break;
			else
			{
				columnNames.erase(i);
				currentcol++;
			}
		}
	}
}