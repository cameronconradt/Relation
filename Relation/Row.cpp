#include "Row.h"



Row::Row(list<String> invalues)
{
	values = invalues;
}

Row::Row(Row* inrow)
{
	values = inrow->getvalues();
}

Row::~Row()
{
}

bool Row::satisfies(ColColKey colColKey)
{

}

bool Row::satisfies(ColValueKey colValueKey)
{

}

void Row::removeAllOtherColumnsBut(set<int> columnsToKeep)
{
	int currentcol = 0;
	for (auto i = values.begin(); i != values.end(); i++)
	{
		for (auto j : columnsToKeep)
		{
			if (currentcol == j)
				break;
			else
			{
				values.erase(i);
				currentcol++;
			}
		}
	}
}

list<String> Row::getvalues()
{
	return values;
}