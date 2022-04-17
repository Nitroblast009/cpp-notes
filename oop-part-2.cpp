/*
    - Every time you use = operator for two variables, C++ does a shallow copy (except for references which are just aliases )
    - Shallow copy does not copy values at pointer but just the same pointer address
    - Three types of class constructors: constructors, destructors, and copy constructors
    - Default copy constructor C++ provides just shallow copies class (MyClass(const MyClass& other) : param1(other.param1), param2(other.param2)... {})
    */
#include <iostream>

class Unconstructable
{
private:
    Unconstructable() {} // Cuz constructor is private class cant be initialized
};

class Point
{
public:
    int x, y;
    int *ptrX, *ptrY;

    Point(int userX, int userY) : x(userX), y(userY), ptrX(&this->x), ptrY(&this->y) {} // Member initializer lists mean that you initialize attributes with the value you want, instead of just intializing them and then assigning them in the constructor body by default
    Point() : x(), y(), ptrX(&this->x), ptrY(&this->y) {}                               // Empty brackets in member initializer lists mean that attributes will be given a default value based on their type; for numerical types, that value is 0
};

class CopyablePoint
{
public:
    int x, y;
    int *ptrX, *ptrY;

    CopyablePoint(int userX, int userY) : x(userX), y(userY), ptrX(&this->x), ptrY(&this->y) {}
    CopyablePoint() : x(), y(), ptrX(&this->x), ptrY(&this->y) {}

    CopyablePoint(const CopyablePoint &other) : x(other.x), y(other.y), ptrX(&this->x), ptrY(&this->y)
    {
    }
};

std::ostream &operator<<(std::ostream &stream, const Point v) // Point object gets copied here, calling copy constructor
{
    stream << "(" << v.x << ", " << v.y << ")" << std::endl;
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const CopyablePoint v) // Point object gets copied here, calling copy constructor
{
    stream << "(" << v.x << ", " << v.y << ")" << std::endl;
    return stream;
}

int main()
{
    // Unconstructable *u = new Unconstructable(); // Won't work cuz of above

    Point p1 = Point();
    Point p2 = p1;

    *p2.ptrX = 6; // Because v2 is a shallow copy, its pointers point to v1's attributes instead of its own
    *p2.ptrY = 9;

    CopyablePoint cp1 = CopyablePoint(4, 20);
    CopyablePoint cp2 = cp1;

    *cp2.ptrX = 5;
    *cp2.ptrY = 3;

    std::cout << p1 << p2 << cp1 << cp2;
}