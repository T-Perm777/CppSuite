//linking the .cpp and the .h
#include "getOS_Type.h"
//There are a few things we need to include, as you can see
#include <array>
#include <memory>
#include <string>
#include <cstdio>
#include <iostream>
//Making the actual function (this one's for Windows as the name implies)
void getDetailedWinVer(){
    //making an immutable character pointer (that for some reason acts like std::string but we do this for a later line) named cmd
    const char* cmd = 
    //This is an AMAZING command, go have fun with it :)
    //Command without the table headers: Get-CimInstance Win32_OperatingSystem | Select-Object Caption, Version, BuildNumber | Format-Table -HideTableHeaders
    //Command with table headers: Get-CimInstance Win32_OperatingSystem | Select-Object Caption, Version, BuildNumber
        "powershell -Command \"Get-CimInstance Win32_OperatingSystem | "
        "Select-Object Caption, Version, BuildNumber | "
        "Format-Table -HideTableHeaders\""; 
    //a character array of 256 bits named buffer
    std::array<char, 256> buffer;
    //Initializing the 'result' variable as a string; we'll use this a few lines down.
    std::string result;
    //gets really messt right around now. This is just a fancy way to open a command in powershell, kind of. we're opening a 'pipe' with read permissions
    //and then making sure that we don't cause a memory leak or anything, using pointers and stuff (i don't understand how it works to be honest)
    std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
    //error handling in case the pipe didn't open
    if (!pipe){
        std::cerr << "Failed to run PowerShell command." << std::endl;
    }
    //this loops through what we read earlier in the pipe, stores it in a buffer, then adds it to our 'result' variable until there's nothing left to read
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr){
        result += buffer.data();
    }
    //printing everything
    std::cout << "Windows Version:" << result << std::endl;
}