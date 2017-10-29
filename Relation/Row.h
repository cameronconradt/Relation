#include "String.h"
#include "ColColKey.h"
#include "ColValueKey.h"
#include <set>
#include <vector>
class Row
{
public:
	Row(vector<String> invalues);
	Row(Row* inrow);
	~Row();
	bool satisfies(ColColKey* colColKey);
	bool satisfies(ColValueKey* colValueKey);
	void removeAllOtherColumnsBut(set<int> columnsToKeep);
	vector<String> getvalues();
protected:
	vector<String> values;
};

