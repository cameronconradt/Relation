#include "Table.h"



Table::Table(String inname, Header inheader)
{
	name = inname;
	header = inheader;
}

Table::Table(Header inheader)
{
	header = inheader;
}

Table::Table(Table* intable)
{
	name = getName();
	header = getHeader();
	rows = getRows();
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
	for (auto i : rows)
	{
		Row* newRow = new Row(i);
		newRow->removeAllOtherColumnsBut(columnsToKeep);
		result->rows.insert(newRow);
	}
	return result;
}

Table* Table::rename(set<ColumnNamePair> newNames)
{
	Table* result = new Table(this);
	for (auto i : newNames)
	{
		result->header.rename(i.getColumn(), i.getName());
	}
}

String Table::getName()
{
	return name;
}

Header Table::getHeader()
{
	return header;
}

set<Row*> Table::getRows()
{
	return rows;
}