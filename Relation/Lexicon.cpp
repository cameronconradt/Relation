#include "Lexicon.h"



Lexicon::Lexicon()
{
	endline = 1;
}


Lexicon::~Lexicon()
{
	for(auto i = tokens.begin(); i != tokens.end(); i++)
	{
		delete *i;
	}
	tokens.clear();
	/*
	for(int i = 0; i < tokens.size(); i++)
	{
		delete tokens[i];
	}*/
}

string Lexicon::tostring()
{
	stringstream output;
	for (int i = 0; i < tokens.size(); i++)
	{
		//(Token_Type,"Value",Line_Number)
		output << "\(" << tokens[i]->gettype() << ",\"" + tokens[i]->gettext() << "\"," + tokens[i]->getline() << ")\n";
	}
	output << "Total Tokens = " << tokens.size();
	output << "\n";
	return output.str();
}
void Lexicon::readin(char in)
{
	chars.push_back(in);
}
void Lexicon::filter()
{
	chars.pop_back();
	if(chars.size() > 2)
		chars.pop_back();
	int startline;
	for (int i = 0; i < chars.size(); i++)
	{
		//cout << chars.size() << endl;
		startline = endline;
		if (isalpha(chars[i]))
		{
			i = id(startline, i);
		}
		else
		{
			switch (chars[i]) {
			case '\n':endline++;
				break;
			case ',': comma(startline);
				break;
			case '.': period(startline);
				break;
			case '?': q_mark(startline);
				break;
			case '(': left_paren(startline);
				break;
			case ')': right_paren(startline);
				break;
			case ':':
				if (chars[i + 1] == '-')
				{
					colon_dash(startline);
					i++;
				}
				else
					colon(startline);
				break;
			case '*': multiply(startline);
				break;
			case '+': add(startline);
				break;
			case '\'':
				i = addstring(startline, i);
				break;
			case '#':
				if (chars[i + 1] == '|')
				{
					i = block_comment(startline, i);
				}
				else
				{
					i = line_comment(startline, i);
				}
				break;
			default: undefined_single(startline, i);
			}
		}
	}
	eof(endline);
}
void Lexicon::comma(int line)
{
	Token* mytoken = new Token("COMMA", ",", line);
	tokens.push_back(mytoken);
}
void Lexicon::period(int line)
{
	Token* mytoken = new Token("PERIOD", ".", line);
	tokens.push_back(mytoken);
}
void Lexicon::q_mark(int line)
{
	Token* mytoken = new Token("Q_MARK", "?", line);
	tokens.push_back(mytoken);
}
void Lexicon::left_paren(int line)
{
	Token* mytoken = new Token("LEFT_PAREN", "(", line);
	tokens.push_back(mytoken);
}
void Lexicon::right_paren(int line)
{
	Token* mytoken = new Token("RIGHT_PAREN", ")", line);
	tokens.push_back(mytoken);
}
void Lexicon::colon(int line)
{
	Token* mytoken = new Token("COLON", ":", line);
	tokens.push_back(mytoken);
}
void Lexicon::colon_dash(int line)
{
	Token* mytoken = new Token("COLON_DASH", ":-", line);
	tokens.push_back(mytoken);
}
void Lexicon::multiply(int line)
{
	Token* mytoken = new Token("MULTIPLY", "*", line);
	tokens.push_back(mytoken);
}
void Lexicon::add(int line)
{
	Token* mytoken = new Token("ADD", "+", line);
	tokens.push_back(mytoken);
}
void Lexicon::undefined_single(int line, int pos)
{
	if (!isspace(chars[pos]))
	{
		stringstream tempss;
		tempss << chars[pos];
		string temp;
		tempss >> temp;
		Token* mytoken = new Token("UNDEFINED", temp, line);
		tokens.push_back(mytoken);
	}
}
void Lexicon::eof(int line)
{
	Token* mytoken = new Token("EOF", "", line);
	tokens.push_back(mytoken);
}
int Lexicon::line_comment(int line, int pos)
{
	int endofline = 0;
	string text = "";
	for (int i = pos; endofline == 0; i++)
	{
		if (chars[i] == '\n')
		{
			endofline = i - 1;
		}
		else
		{
			text += chars[i];
		}
	}
	//Token* mytoken = new Token("COMMENT", text, line);
	//tokens.push_back(mytoken);
	return endofline;
}
int Lexicon::addstring(int line, int pos)
{
	string text = "'";
	int found = 0;
	for (int i = pos + 1; found == 0; i++)
	{
		text += chars[i];
		if (chars[i] == '\'')
		{
			if (chars[i + 1] == '\'')
				i++;
			else
				found = i;
		}
		else if (i == chars.size() - 1)
		{
			endline = line;
			return undefined(line, pos);
		}
		else if (chars[i] == '\n')
		{
			endline++;
		}

	}
	Token* mytoken = new Token("STRING", text, line);
	tokens.push_back(mytoken);
	return found;
}
int Lexicon::block_comment(int line, int pos)
{
	string text = "#|";
	int found = 0;
	for (int i = pos + 2; found == 0; i++)
	{
		text += chars[i];
		if (chars[i - 1] == '|' && chars[i] == '#')
		{
			found = i;
		}
		else if (i == chars.size() - 1)
		{
			endline = line;
			return undefined(line, pos);
		}
		else if (chars[i] == '\n')
		{
			endline++;
		}

	}
	//Token* mytoken = new Token("COMMENT", text, line);
	//tokens.push_back(mytoken);
	return found;
}
int Lexicon::undefined(int line, int pos)
{
	string text = "";
	int found = 0;
	for (int i = pos; found == 0; i++)
	{
		text += chars[i];
		if (chars[i] == '\n')
		{
			endline++;
		}
		if (i == chars.size() - 1)
		{
			found = i;
		}
	}
	Token* mytoken = new Token("UNDEFINED", text, line);
	tokens.push_back(mytoken);
	return found;
}
int Lexicon::schemes(int line, int pos)
{
	string text = "";
	for (int i = pos; i < pos + 7; i++)
	{
		text += chars[i];
	}
	if (text == "Schemes" && !isalnum(chars[pos + 7]))
	{
		Token* mytoken = new Token("SCHEMES", text, line);
		tokens.push_back(mytoken);
		return pos + 6;
	}
	return pos;
}
int Lexicon::facts(int line, int pos)
{
	string text = "";
	for (int i = pos; i < pos + 5; i++)
	{
		text += chars[i];
	}
	if (text == "Facts" && !isalnum(chars[pos + 5]))
	{
		Token* mytoken = new Token("FACTS", text, line);
		tokens.push_back(mytoken);
		return pos + 4;
	}
	return pos;
}
int Lexicon::rules(int line, int pos)
{
	string text = "";
	for (int i = pos; i < pos + 5; i++)
	{
		text += chars[i];
	}
	if (text == "Rules" && !isalnum(chars[pos + 5]))
	{
		Token* mytoken = new Token("RULES", text, line);
		tokens.push_back(mytoken);
		return pos + 4;
	}
	return pos;
}
int Lexicon::queries(int line, int pos)
{
	string text = "";
	for (int i = pos; i < pos + 7; i++)
	{
		text += chars[i];
	}
	if (text == "Queries" && !isalnum(chars[pos + 7]))
	{
		Token* mytoken = new Token("QUERIES", text, line);
		tokens.push_back(mytoken);
		return pos + 6;
	}
	return pos;
}
int Lexicon::id(int line, int pos)
{
	int toreturn = pos;
	switch (chars[pos])
	{
	case 'S':
		toreturn = schemes(line, pos);
		if (toreturn != pos)
			return toreturn;
	case 'F':
		toreturn = facts(line, pos);
		if (toreturn != pos)
			return toreturn;
	case 'R':
		toreturn = rules(line, pos);
		if (toreturn != pos)
			return toreturn;
	case 'Q':
		toreturn = queries(line, pos);
		if (toreturn != pos)
			return toreturn;
	default:
		toreturn = 0;
		string text = "";
		for (int i = pos; toreturn == 0; i++)
		{
			text += chars[i];
			if (isspace(chars[i + 1]) || chars[i + 1] == '\n' || !isalpha(chars[i + 1]))
				toreturn = i;
		}
		Token* mytoken = new Token("ID", text, line);
		tokens.push_back(mytoken);
		return toreturn;
	}

}
int Lexicon::gettoken(int pos)
{
	if (pos < tokens.size() && pos >= 0)
	{
		if (tokens[pos]->gettype() == "COMMA")
			return COMMA;
		if (tokens[pos]->gettype() == "PERIOD")
			return PERIOD;
		if (tokens[pos]->gettype() == "Q_MARK")
			return Q_MARK;
		if (tokens[pos]->gettype() == "LEFT_PAREN")
			return LEFT_PAREN;
		if (tokens[pos]->gettype() == "RIGHT_PAREN")
			return RIGHT_PAREN;
		if (tokens[pos]->gettype() == "COLON")
			return COLON;
		if (tokens[pos]->gettype() == "COLON_DASH")
			return COLON_DASH;
		if (tokens[pos]->gettype() == "MULTIPLY")
			return MULTIPLY;
		if (tokens[pos]->gettype() == "ADD")
			return ADD;
		if (tokens[pos]->gettype() == "SCHEMES")
			return SCHEMES;
		if (tokens[pos]->gettype() == "FACTS")
			return FACTS;
		if (tokens[pos]->gettype() == "RULES")
			return RULES;
		if (tokens[pos]->gettype() == "QUERIES")
			return QUERIES;
		if (tokens[pos]->gettype() == "ID")
			return ID;
		if (tokens[pos]->gettype() == "STRING")
			return STRING;
		if (tokens[pos]->gettype() == "EOF")
			return end;
	}
	return -1;
}
Token* Lexicon::returnToken(int pos)
{
	return tokens[pos];
}
