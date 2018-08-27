//include header
#include "calc_scanner.h"
#include <iostream>

using std::string;

Token get_next_token(std::istream &token_stream)
{
	char c, x;
	string str = "";

	token_stream.get(c);

	//white space
	if (isspace(c)) 
		{ token_stream.get(c); 
	///Instead of this line, "token_stream >> c;" will skip all white space.
	}
	else
	{
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
			x = token_stream.peek();
			if (x == '/')
			{
				token_stream.get(c); //ignore second '/'
				while (token_stream.get(c) && c != '\n')
				{
					getline(token_stream, str);  /// GETLINE ALLOWS FOR A 3RD PARAMETER THAT LET'S YOU PICK WHERE TO START
				}
				//token_stream.get(c);
				return{ TOKEN::COMMENT, str };
			}
			//if followed by a *, then a comment until */ or EOF
			else if (x == '*')
			{
				///GETLINE (TOKEN_STREAM, STR, '*');
				while (token_stream.get(c) && !(c == '*' && x == '/'))
				{
					x = token_stream.peek();
					str += string(1, c);
				}
				return{ TOKEN::COMMENT, str };
			}
			//else, div				
			else
				return{ TOKEN::DIV, "/" };
		}

		//NUMBER
		else if (c == '.')
		{
			str += string(1, c);
			token_stream.get(c);
			if (token_stream.get(c) && isdigit(c))
			{
				while (token_stream.get(c) && isdigit(c))
				{
					str += string(1, c);
				}
				return{ TOKEN::NUMBER, str };
			}
			else
				return{ TOKEN::TOKEN_ERROR, "Unexpected character." };
		}

		else if (isdigit(c))
		{
			str += string(1, c);
			if (token_stream.get(c) && isdigit(c))
			{
				while (token_stream.get(c) && isdigit(c))
				{
					str += string(1, c);
				}
				if (c == '.')
				{
					str += string(1, c);
				}
				while (token_stream.get(c) && isdigit(c))
				{
					str += string(1, c);
				}
				return{ TOKEN::NUMBER, str };
			}
			else
				return{ TOKEN::TOKEN_ERROR, "Unexpected character - possibly second '.'" };
		}


		//READ, WRITE, and ID
		else if (token_stream.get(c) && isalpha(c))
		{
			///STR(1, C);
			while (token_stream.get(c) && (isalpha(c) || isdigit(c)))
			{
				str += string(1, c);
				///STR.PUSH_BACK(C);
				token_stream.get(c);
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
}