#include "Table.h"



Table::Table(String inname, Header inheader)
{
	name = inname;
	header = inheader;
}

Table::Table(Header inheader)
{

}


Table::~Table()
{

}

Table* Table::select(set<SelectionKey> selectionKeys)
{
	Table* result = new Table(new Header(header));
	for (auto i : rows)
	{
		bool satisfied = true;
		for (auto j : selectionKeys)
		{
			satisfied = i->satisfies(j);
			if (!satisfied)
				break;
		}
		if (satisfied)
			result->rows.insert(i);
	}
	return result;
}

Table* Table::project(set<int> columnsToKeep)
{
	Table* result = new Table(new Header(header));
	result->header.removeAllOtherColumnsBut(columnsToKeep);
}

Table* Table::rename(set<ColumnNamePair> newNames)
{

}