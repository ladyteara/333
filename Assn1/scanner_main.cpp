/**********************************************************

This file is inlcudes a main function for testing your
scanner code.

**********************************************************/

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include "calc_scanner.h"

int main(int argc, char const *argv[])
{
    //
    // An input file is given via the commnad line
    //
	//cout << argc << endl;
    if (argc != 2) {
        cerr << "Invalid number of input arguments.\n"
             << "This program should be run with the following command\n"
             << "    ./scanner input-file.calc\n"
             << "     where \"input-file.calc\" is a file containing valid strings."
             << endl;
        return EXIT_FAILURE;
    }

    //
    // Open the given file
    //
    ifstream calc_stream(argv[1]);
    if (!calc_stream.is_open()) {
        cerr << "Unable to open the file \"" << argv[1] << "\"." << endl;
        return EXIT_FAILURE;
    }

    //
    // Pass the file to the get_next_token function and
    // print each discovered token
    //
	
	/*std::string loc = "C:\\Users\\avalo\\Google Drive\\_CSC 333 - Languages and Machines\\Assn 1\\tests\\";
	ifstream calc_stream(loc + "example.calc");*/

    Token tok;
    do {
        tok = get_next_token(calc_stream);				//change argument to std::cin or any other input method 
        cout << tok.to_string() << endl;
    } while (tok.token != TOKEN::END);

    return EXIT_SUCCESS;
}

