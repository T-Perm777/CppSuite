//including what we need
#include "PassGen.h"
#include <iostream>
#include <fstream>
//the main body of the program
int main(int argc, char* argv[]) {
    Flags flags = parseFlags(argc, argv);
    std::string password = genPass(flags);
    //outputting the password, if desired
    if (flags.outFile == "true") {
        std::ofstream out(flags.outPath);
        out << password;
    } else {
        //outputting the password
        std::cout << std::endl << "Generated password: " << password;
    }
}