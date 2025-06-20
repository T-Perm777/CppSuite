//Making sure it isn't impored more than once
#pragma once
//Including the string lib
#include <string>
//a struct named flags (a containger for variables that's called Flags)
struct Flags{
    //if the user wants the file to be outputted, set this to true
    std::string outFile = "false";
    //set to true if the user wants fast mode (the -f flag)
    std::string fastMode = "false";
    //all of these are default values for password settings
    std::string wantUpper = "true";
    std::string wantSpecial = "true";
    std::string wantNums = "true";
    int passLength = 12;
    //the output path if the -o flag is specified
    std::string outPath = "";
};
//defining the genPass function
std::string genPass(Flags& flags);
//definig the parseFlags function, with argc (the amount of varaibles passed) and argv (an array of variables)
Flags parseFlags(int argc, char* argv[]);