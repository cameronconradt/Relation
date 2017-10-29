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

bool test1(Table* table);
void addtovector(vector<vector<String>> &vec, String str1, String str2);

int main()
{
	vector<Table*> solutions;
	String* a = new String( new Token("STRING", "a", 1));
	String* b = new String(new Token("STRING", "b", 1));
	set<String> columnNames;
	columnNames.insert(*a);
	columnNames.insert(*b);
	Header header(columnNames);
	Table* mytable = new Table(*a, header);
	vector<vector<String>> rows;
	addtovector(rows, *a, *a);
	addtovector(rows, *b, *b);
	addtovector(rows, *a, *b);
	addtovector(rows, *b, *a);
	for (int i = 0; i < rows.size(); i++)
		mytable->addRow(rows[i]);
	return 0;
}
void addtovector(vector<vector<String>> &vec, String str1, String str2)
{
	vector<String> row;
	row.push_back(str1);
	row.push_back(str2);
	vec.push_back(row);
}
bool test1(Table* table)
{
	ColColKey* sel = new ColColKey(0, 1);
	set<SelectionKey*> myset;
	myset.insert(sel);
	Table* result = table->select(myset);
	if (result->getRows().size() == 2)
	{
		cout << "Test 1 Success";
		return true;
	}
}
bool test2(Table* table)
{
	set<int> columnstokeep;
	columnstokeep.insert(0);
	String* a = new String(new Token("STRING", "a", 1));
	table->project(columnstokeep);
	auto i = table->getHeader().getcolnames().begin();
	if(i.tostring() == a->tostring())
}