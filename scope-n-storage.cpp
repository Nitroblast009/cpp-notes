/*
    - static and extern keywords are specifically for global vars across multiple files
    - should make global vars static by default, making them private for each file
    - extern means that this global var is being taken from a global var in another file
    - files must be compiled together (with linker) for static and extern keywords to really matter
*/
#include <iostream>

void Log(const char *message) { std::cout << message; }

extern std::string nuts;
extern int a; // Will not work cuz a is static in sns.cpp
static char b = 49;

int main()
{
    Log("nuts");
    char b = 48; // Will use local scope var by default
    if (1)
    {
        std::cout << b;
    }
}