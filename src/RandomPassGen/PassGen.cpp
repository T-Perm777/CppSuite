//importing what we'll use
#include "PassGen.h"
#include <iostream>
#include <random>
//making the function
std::string genPass(Flags& flags){
    //the different characters used in making a password
    const std::string chars_lower = "abcdefghijklmnopqurstuvwxyz";
    const std::string chars_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string nums = "01234567890";
    const std::string special_chars = "!@#$%^&*()_+-={[}]|\\:;\"'<,>.?/}";
    //the characters we'll actively use
    std::string selection_pool;
    //adding the lowercase chars to the selection pool
    selection_pool += chars_lower;
    //checking if fastmode is off (if on, user input is skipped and default settings are used)
    if (flags.fastMode == "false"){
        //getting user input for the pasword settings/variables
        std::cout << "Please input your desired password length (default 12): ";
        std::cin >> flags.passLength;
        //this just clears the input buffer so that we can actually input all the settings
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl << "Please select what character types you would like (lowercase letters are required)." << std::endl;
        std::cout << "Do you want uppercase letters?" << std::endl << "[true/false]: ";
        std::cin >> flags.wantUpper;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl << "Do you want numbers?" << std::endl << "[true/false]: ";
        std::cin >> flags.wantNums;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl << "Do you want special characters? \\ and \" will not be included, ever." << std::endl << "[true/false]";
        std::cin >> flags.wantSpecial;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    //making the actual password (on line 34, wow)
    std::string pw;
    //adding the characters we'll use to the selection pool
    if (flags.wantUpper == "true"){
        selection_pool += chars_upper;
    }
    if (flags.wantNums == "true"){
        selection_pool += nums;
    }
    if (flags.wantSpecial == "true"){
        selection_pool += special_chars;
    }
    //the random character selection stuff
    std::random_device random;
    std::mt19937 gen(random());
    std::uniform_int_distribution<> dist(0, selection_pool.size() - 1);
    for (int count = 0; count < flags.passLength; count++){
        pw += selection_pool[dist(gen)];
    }
    //outputting the password
    return pw;
}
//making the parseFlags function for the -o and -f flags
Flags parseFlags(int argc, char* argv[]){
    Flags flags;
    for (int count = 0; count < argc; count++){
        std::string arg = argv[count];
        if (arg == "-f"){
            flags.fastMode = "true";
        }
        if (arg == "-o"){
            if (count + 1 < argc){
                flags.outFile = "true";
                flags.outPath = argv[++count];
            } else {
                std::cerr << "Missing output path.";
                exit(1);
            }
        }
    }
    //this is just so that everything works in main.cpp
    return flags;
}