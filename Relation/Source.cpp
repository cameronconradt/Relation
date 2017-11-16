#pragma once
#include "Table.h"
#include "Token.h"
#include "String.h"
#include "SelectionKey.h"
#include "ColumnNamePair.h"
#include "ColColKey.h"
#include "ColValueKey.h"
#include <vector>

using namespace std;

bool test1(Table* table1, Table* table2);
bool test2(Table* table1, Table* table2, int columns);
bool test3(Table* table1, Table* table2, int rows);
bool test4(Table* table);
bool test5(Table* table1, Table* table2);
bool test6(Table* table);
bool test7(Table* table);
bool test8(Table* table1, Table* table2, int columns);
bool test9(Table* table);
bool test10(Table* table1, Table* table2);
void addtovector(vector<vector<String>> &vec, String str1, String str2);

int main()
{
	vector<Table*> tables;
	String* a = new String( new Token("STRING", "a", 1));
	String* b = new String(new Token("STRING", "b", 1));
	String* c = new String(new Token("STRING", "c", 1));
	String* d = new String(new Token("STRING", "d", 1));
	vector<String> columnNames;
	columnNames.push_back(*a);
	columnNames.push_back(*b);
	Header* header = new Header(columnNames);
	Table* mytable = new Table(*a, *header);
	vector<vector<String>> rows;
	addtovector(rows, *a, *a);
	addtovector(rows, *b, *b);
	addtovector(rows, *a, *b);
	addtovector(rows, *b, *a);
	for (int i = 0; i < rows.size(); i++)
		mytable->addRow(rows[i]);
	Table* newtable = new Table(mytable);
	tables.push_back(newtable);
	columnNames.pop_back();
	columnNames.push_back(*c);
	header = new Header(columnNames);
	mytable = new Table(*b, *header);
	for (int i = 0; i < rows.size(); i++)
		mytable->addRow(rows[i]);
	tables.push_back(mytable);
	mytable = new Table(*c, *header);
	tables.push_back(mytable);
	columnNames.pop_back();
	columnNames.pop_back();
	columnNames.push_back(*c);
	columnNames.push_back(*d);
	mytable = new Table(*d, header);
	for (int i = 0; i < rows.size(); i++)
		mytable->addRow(rows[i]);
	tables.push_back(mytable);
	vector<bool> results;
	if (test1(tables[0], tables[1]))
		results.push_back(true);
	else
		results.push_back(false);
	if (test2(tables[0],tables[1],3))
		results.push_back(true);
	else
		results.push_back(false);
	if (test3(tables[0],tables[1],4))
		results.push_back(true);
	else
		results.push_back(false);
	if (test4(tables[2]))
		results.push_back(true);
	else
		results.push_back(false);
	if (test5(tables[0],tables[3]))
		results.push_back(true);
	else
		results.push_back(false);
	if (test6(tables[0]))
		results.push_back(true);
	else
		results.push_back(false);
	if (test7(tables[0]))
		results.push_back(true);
	else
		results.push_back(false);
	if (test8(tables[0],tables[1],2))
		results.push_back(true);
	else
		results.push_back(false);
	if (test9(tables[0]))
		results.push_back(true);
	else
		results.push_back(false);
	if (test10(tables[0],tables[3]))
		results.push_back(true);
	else
		results.push_back(false);
	for (int i = 1; i < 11; i++)
	{
		if (results[i-1])
			cout << "Test " << i << " Succeeded!" << endl;
		else
			cout << "Test " << i << " Failed!" << endl;
	}

	return 0;
}
void addtovector(vector<vector<String>> &vec, String str1, String str2)
{
	vector<String> row;
	row.push_back(str1);
	row.push_back(str2);
	vec.push_back(row);
}
bool test1(Table* table1, Table* table2) // Call Natural Join
{
	table1->naturalJoin(table2);
	return true;
}
bool test2(Table* table1, Table* table2, int columns) // Natural Join test headers
{
	Table* newtable = table1->naturalJoin(table2);
	if (newtable->getHeader().getcolnames().size() == columns)
		return true;
	else
		return false;
}
bool test3(Table* table1, Table* table2, int rows) // Natural Join test rows
{
	Table* newtable = table1->naturalJoin(table2);
	if (newtable->getRows().size() == rows)
		return true;
	else
		return false;
}
bool test4(Table* table) // Natural Join blank tables
{
	if (test2(table, table, 2) && test3(table, table, 0))
		return true;
	else
		return false;
}
bool test5(Table* table1, Table* table2) //  Natural Join unique tables (no shared columns)
{
	if (test2(table1, table2, 4) && test3(table1, table2, 16))
		return true;
	else
		return false;
}
bool test6(Table* table) //Natural Join identical tables
{
	if (test2(table, table, 2) && test3(table, table, 4))
		return true;
	else
		return false;
}
bool test7(Table* table) // Call Union
{
	table->Union(table);
	return true;
}
bool test8(Table* table1, Table* table2, int columns) // Union 1 shared column
{
	Table* newtable = table1->Union(table2);
	if (newtable->getHeader().getcolnames().size() == columns)
		return true;
	else
		return false;
}
bool test9(Table* table) // Union identical tables
{
	if (test8(table, table, 0))
		return true;
	else
		return false;
}
bool test10(Table* table1, Table* table2) //Union No shared columns
{
	if (test8(table1, table2, 4))
		return true;
	else
		return false;
}