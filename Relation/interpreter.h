#pragma once
#include "Table.h"
#include "DatalogProgram.h"

class interpreter
{
public:
	interpreter(DatalogProgram* in);
	~interpreter();
	string tostring();
protected:
	DatalogProgram * data;
	vector<Table*> tables;
};

