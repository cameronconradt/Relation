#include "Table.h"



Table::Table(String inname, Header inheader)
{
	name = inname;
	header = inheader;
	rows.addRow(Row row);
}


Table::~Table()
{

}
