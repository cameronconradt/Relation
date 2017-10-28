#pragma once
#include "Table.h"
#include "SelectionKey.h"
#include "ColumnNamePair.h"
#include <vector>
class Relation
{
public:
	Relation();
	~Relation();
	Table select(set<SelectionKey> selectionKeys);
	Table project(set<int> columnsToKeep);
	Table rename(set<ColumnNamePair> newNames);
protected:
	vector<Table> mytables;
};

