//most basic thing ever
#include <iostream>
//making sure we have the header imported
#include "getOS_Type.h"
//you should know this part :)
int main(){
    //seeing if it's windows we're working on so that we don't get an error from our function's code
    #ifdef _WIN32
    getDetailedWinVer();
    #endif
    return 0;
}