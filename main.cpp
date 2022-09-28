#include <cctype>
#include <iostream>
#include <fstream>
#include "string.h"

int main(int argc, char *argv[]) {
    std::istream* in = NULL;
    std::ifstream file;
    std::string flag;

	if(argc == 1) {
        std::cerr << "Missing File Name." << std::endl;
		return 0;
	}

    if (argc >= 2) {
        // handle file 
        std::string fname = argv[1];
        file.open(fname.c_str());
        if( file.is_open() == false ) {
            std::cerr << "CANNOT OPEN " << fname << std::endl;
            return 0;
        }

        in = &file;

        // handle flag 
        if (argc == 3) {
            flag = argv[2];
        } else {
        // handle no flag

        }
    }

    /* std::string fname = "file"; */
    /* file.open(fname.c_str()); */

    int wordc = 0;
    int namec = 0;
    int numc = 0;

    std::string line;
    char* charPtr;

    while (std::getline(file, line)) {
        charPtr = &line[0];
        // word status 
        bool isname = false;
        bool isnum = false;

        /* std::cout << *charPtr << std::endl; */
        // Evaluate the first word
        while (*charPtr != '\0') {
            // check the first character in each line or the first character in each word
            if (charPtr == &line[0] || *(charPtr - 1) == ' ') {
                if (*charPtr == '_' || std::isalpha(*charPtr)) {
                    isname = true; 
                } 
                else if (*charPtr == '+' || *charPtr == '-' || std::isdigit(*charPtr)) {
                    isnum = true;
                }
            }
            else if (!std::isdigit(*charPtr)) {
                isnum = false;
            }
            // once the next character is a space, evaluate the word and reset the status
            if (*(charPtr + 1) == ' ' || *(charPtr + 1) == '\0' || *(charPtr + 1) == '\n' || *(charPtr + 1) == '\t') {
                if (isname) {
                    namec++;  
                    isname = false;
                } else if (isnum) {
                    numc++;
                    isnum = false;
                } else {
                    isname = false;
                    isnum = false;
                }
            }
            charPtr++;
        }

    }

    if (flag == "-all") {
        std::cout << namec << std::endl; 
        std::cout << numc << std::endl;
    }
    else if (flag == "-ints") {
        std::cout << numc << std::endl;
    }
    else if (flag == "-names") {
        std::cout << namec << std::endl; 
    } 
    else {
        std::cout << namec << std::endl; 
        std::cout << numc << std::endl;
    }

    return 0;

}
