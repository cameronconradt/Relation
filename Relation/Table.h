#pragma once
#include "String.h"
#include "Header.h"
#include "Row.h"
#include <set>
class Table
{
public:
	Table(String inname, Header inheader);
	~Table();
protected:
	String name;
	Header header;
	set<Row> rows
};

