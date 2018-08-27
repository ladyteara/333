#ifndef _CALC_SCANNER_
#define _CALC_SCANNER_

#include <string>
#include <iostream>
#include <array>

//
// This is an enumeration of every possible token that
// our scanner should be able to identify. The final value
// in the enum (NUM_TOKEN) is simply a 'trick' used for
// automatically calculating the total number of tokens.
//
enum class TOKEN {
    ASSIGN,
    PLUS,
    MINUS,
    TIMES,
    DIV,
    LPAREN,
    RPAREN,
    ID,
    READ,
    WRITE,
    NUMBER,
    COMMENT,
    END,
    TOKEN_ERROR,
    NUM_TOKEN
};

//
// This struct will be used to represent each token. Each token that
// we create comprises a TOKEN from the above enum, and the text associated
// with the token.
//
struct Token
{
    TOKEN token;
    std::string text;

    //
    // A function used to print a token
    //
    std::string to_string() {
        static const auto NUM_TOKEN = static_cast<size_t>(TOKEN::NUM_TOKEN);
        static const std::array<std::string, NUM_TOKEN> TOKEN_STRINGS = {{
            "ASSIGN", "PLUS", "MINUS", "TIMES", "DIV", "LPAREN", "RPAREN",
            "ID", "READ", "WRITE", "NUMBER", "COMMENT", "END", "TOKEN_ERROR"
        }};

        return TOKEN_STRINGS.at(static_cast<unsigned>(token)) + " : " + text;

    }
};

//
// The signature for the function that you will be implementing in
// the calc_scanner.cpp file.
//
Token get_next_token(std::istream &token_stream);

#endif
