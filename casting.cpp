/*
    - C++ type system isn't as enforced, allowing for type punning
    - For the most part, C++ casts don't do much different from C-style casts; but makes code more readable and adds compile-time checking
    - Should thus use C++ casts preferably
    - Static cast is more limited and only lets you do more simple casting; they are not checked at run-time
    - Dynamic cast returns null if casting wasn't successful and does proper validation to make sure cast worked; they are checked at run-time (more like a function)
    - Dynamic casts are mostly useful for converting between base and derived classes (through inheritance)
    - Reinterpret cast is like a raw cast that literally changes how it interprets the bits at a certain location of memory
    - Const casts remove const-ness from a pointer/reference
*/

#include <iostream>

struct Point
{
    float x, y;
};

int main()
{
    int a = 5;
    double b = a;             // Implicitly converts to double (don't need to do anything cuz program knows what to do without any major data lost)
    double c = *(double *)&a; // Reinterprets int a's memory location as a double, which could cause crash

    double x = 5.25;
    int y = (int)x;              // Explicitly convert to int (called C-style cast)
    int s = static_cast<int>(x); // Same as line above

    // Cast struct of 2 floats as floats array:
    Point p{5.3, 7.0};
    std::cout << p.x; // What a sane person would do

    float f = *reinterpret_cast<float *>(&p); // Reinterpret memory as another data type instead cuz y not

    std::cout << f << std::endl;

    int i = 0;
    const int *ptr = &i;
    // *ptr = 4; //This won't work, need to remove const-ness from pointer/reference
    *const_cast<int *>(ptr) = 4; // Treats ptr as a non-const int pointer

    std::cout << i;
}