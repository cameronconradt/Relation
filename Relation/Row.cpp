#include "Row.h"



Row::Row(vector<String> invalues)
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

bool Row::satisfies(ColColKey* colColKey)
{
	if (values[colColKey->getcol1()].tostring() == values[colColKey->getcol2()].tostring())
		return true;
	else
		return false;
}

bool Row::satisfies(ColValueKey* colValueKey)
{
	if (values[colValueKey->getcol()].tostring() == colValueKey->getval().tostring())
		return true;
	else
		return false;
}

void Row::removeAllOtherColumnsBut(set<int> columnsToKeep)
{
	for (std::set<int>::reverse_iterator i = columnsToKeep.rbegin(); i != columnsToKeep.rend(); i++)
	{
		for (int j = 0; j < values.size() - 1; j++)
		{
			if (j + 1 == *i)
			{
				values.erase(values.begin() + j);
			}
		}
	}

	/*int currentcol = 0;
	for (int i = 0; i < values.size(); i++)
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
	}*/
}

vector<String> Row::getvalues() const
{
	return values;
}