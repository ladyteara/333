//include header
#include "calc_scanner.h"
#include <iostream>

using std::string;

Token get_next_token(std::istream &token_stream)
{
	char c, x;
	string str = "";

	token_stream >> c;
	
		///START HERE
		if (!token_stream.get(c)) { return{ TOKEN::END, "end" }; }

		//PLUS - single character
		else if (c == '+'){ return{ TOKEN::PLUS, "+" }; }

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
			//if followed by a /, then a comment until \n or EOF
			//x = token_stream.peek();
			if (token_stream.peek()=='/')
			{
				//while (token_stream.get(c) && c != '\n')	//This get takes the second character and gets it out of the way
				//{
					getline(token_stream, str);				/// GETLINE ALLOWS FOR A 3RD PARAMETER THAT LET'S YOU PICK WHERE TO START
				//}
				return{ TOKEN::COMMENT, str };
			}
			//if followed by a *, then a comment until */ or EOF
			else if (token_stream.peek() == '*')
			{
				///GETLINE (TOKEN_STREAM, STR, '*');
				getline(token_stream, str, '*');
				return{ TOKEN::COMMENT, str };
			}
			//else, div				
			else
				return{ TOKEN::DIV, "/" };
		}

		//NUMBER
		else if (c == '.')
		{
			str.push_back(c);
			token_stream.get(c);
			if (token_stream.get(c) && isdigit(c))
			{
				while (token_stream.get(c) && isdigit(c))
				{
					str.push_back(c);
				}
				return{ TOKEN::NUMBER, str };
			}
			else
				return{ TOKEN::TOKEN_ERROR, "Unexpected character." };
		}

		else if (isdigit(c))
		{
			str.push_back(c);
			if (token_stream.get(c) && isdigit(c))
			{
				while (token_stream.get(c) && isdigit(c))
				{
					str.push_back(c);
				}
				if (c == '.')
				{
					str.push_back(c);
				}
				while (token_stream.get(c) && isdigit(c))
				{
					str.push_back(c);
				}
				return{ TOKEN::NUMBER, str };
			}
			else
				return{ TOKEN::TOKEN_ERROR, "Unexpected character - possibly second '.'" };
		}


		//READ, WRITE, and ID
		else if (token_stream.get(c) && isalpha(c))
		{
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
		
			//TOKEN_ERROR is built into each check

			//NUM_TOKEN counts the number of tokens - no use.
		}
		else return{ TOKEN::ID, "This is not working." };
	}