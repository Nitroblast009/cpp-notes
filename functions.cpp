/*
    - Function body must be defined globally
    - Inline keyword makes calling a function more assembly code but more efficient (as function calling overheaded is skipped)
    - Is up to the compiler to inline function, but it usually does
    - Doesn't matter what order static and inline keywords are in but I'll put static/extern first
*/
#include <iostream>
#include "func.h" // Declare e() from func2.cpp

static inline void printer(       // Instead of calling the function, the code from the function literally gets copied and pasted at where it is called (still with scope)
    std::string text = "Default") // Text param is "Default" if no param was specified at call
{
    std::cout << text << std::endl;
}

int main()
{
    printer("Hello, world!");
    e();
}
