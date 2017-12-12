#include "DatalogProgram.h"



DatalogProgram::DatalogProgram(Lexicon* Lex)
{
	schemes = new Schemes(Lex);
	queries = new Queries(Lex);
	rules = new Rules(Lex);
	facts = new Facts(Lex);
}


DatalogProgram::~DatalogProgram()
{
	//delete schemes;
	//delete facts;
	//delete rules;
	//delete queries;
}
string DatalogProgram::tostring()
{
	return schemes->tostring()  +
		facts->tostring()  +
		rules->tostring()  +
		queries->tostring() +
		facts->tostringDomain();

}
