/*
    - Static attributes/methods aren't really tied to class other than scope (like in a namespace)
    - Static variables are really just like global variables across the entire program, but having it inside the class makes more sense
    - Need static vars definitions declared globally too
    - Static methods can't access non-static members
*/

#include <iostream>

class Statify
{
public:
    static int x, y;
    void printStatic()
    {
        std::cout << "(" << Statify::x << ", " << Statify::y << ")\n";
    }
};

// IMPORTANT: NEED STATIC VARIABLE DEFINITIONS (LIKE GLOBAL VARS)
int Statify::x;
int Statify::y;

namespace Namify // Static values kinda like this
{
    int x, y;
    inline void printNamespace() const
    {
        std::cout << "(" << Namify::x << ", " << Namify::y << ")";
    }
}

int main()
{
    Statify s1 = Statify();
    s1.x = 5;
    Statify::y = 2; // Should be accesing static values like this

    // Statify::printStatic(); // Won't work cuz printStatic() is an instance function

    s1.printStatic();

    Namify::x = 2;
    Namify::y = 5;
    Namify::printNamespace();
}
