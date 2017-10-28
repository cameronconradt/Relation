#pragma once
class SelectionKey
{
public:
	SelectionKey();
	~SelectionKey();
	virtual bool type() = 0;
};

