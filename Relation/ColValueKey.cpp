#include "ColValueKey.h"



ColValueKey::ColValueKey(int column, String value)
{
	col = column;
	val = value;
}


ColValueKey::~ColValueKey()
{
}

bool ColValueKey::type()
{
	return true;
}