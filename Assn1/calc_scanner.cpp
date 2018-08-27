//include header
#include "calc_scanner.h"
#include <iostream>

using std::string;

Token get_next_token(std::istream &token_stream)
{
	char c;
	token_stream >> c;
		if (!token_stream) { return{ TOKEN::END, "end" }; }

		///START HERE

		//PLUS - single character
		if (c == '+'){ return{ TOKEN::PLUS, "+" }; }

		//MINUS - single character
		else if (c == '-'){ return{ TOKEN::MINUS, "-" }; }

		//TIMES - single character
		else if (c == '*'){ return{ TOKEN::TIMES, "*" }; }

		//LPAREN - single char
		else if (c == '(') { return{ TOKEN::LPAREN, "(" }; }

		//RPAREN - single char
		else if (c == ')'){ return{ TOKEN::RPAREN, ")" }; }

		//ASSIGN - 2 characters
		else if (c == ':')
		{
			if (token_stream.peek() == '=')
			{
				token_stream.get(c);				///only extract if the next character is appropriate
				return{ TOKEN::ASSIGN, ":=" };
			}
			else
				return{ TOKEN::TOKEN_ERROR, "Unexpected character following a colon :" };
		}

		//DIV - single char,  COMMENT - (// to \n or EOF) or (/* to */)
		else if (c == '/')
		{	///CHECK /, *, EOF (ERROR)
			string str;
			if (token_stream.peek()=='/')
			{
				getline(token_stream, str);
				return{ TOKEN::COMMENT, "/" + str };
			}
			//if followed by a *, then a comment until */ or EOF
			else if (token_stream.peek() == '*')
			{
				getline(token_stream, str, '/');			/// GETLINE ALLOWS FOR A 3RD PARAMETER THAT LET'S YOU PICK DELIMITER
				return{ TOKEN::COMMENT, "/" + str + "/" };
			}
			//else, div				
			else
				return{ TOKEN::DIV, "/" };
		}

		//NUMBER
		else if (isdigit(c))
		{
			string str;
			str.push_back(c);
			while (token_stream.get(c) && isdigit(c))		//read digits until EOF or not a #
			{
				str.push_back(c);
			}
			if (c == '.')									//if c is a decimal, store it
			{
				str.push_back(c);
				while (token_stream.get(c) && isdigit(c))		//keep adding as long as #
			{
				str.push_back(c);
			}
			}
			
			return{ TOKEN::NUMBER, str };
		}

		else if (c == '.')
		{
			string str;
			str.push_back(c);
			while (token_stream.get(c) && isdigit(c))
			{
				str.push_back(c);
			}
			
			return{ TOKEN::NUMBER, str };
		}
			
		//READ, WRITE, and ID
		else if (isalpha(c))
		{
			string str;
			str.push_back(c);
			while (token_stream.get(c) && (isalpha(c) || isdigit(c)))
			{
				str.push_back(c);
			}
			if (str.compare("read") == 0)
				return{ TOKEN::READ, "read" };
			else if (str.compare("write") == 0)
				return{ TOKEN::WRITE, "write" };
			else
				return{ TOKEN::ID, str };
		}

	else return{ TOKEN::TOKEN_ERROR, "Unexpected Character" };
	}