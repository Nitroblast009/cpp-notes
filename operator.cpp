/*
    - Operators are symbols we use to do stuff like functions (including basic math ones)
    - Operator overloading means changing the behavior of an operator, giving us full control
    - Operator overloading should be minimal and make sense
    - The operators ::, ., .*, and ?: cannot be overloaded
    - :: operator access static members/functions/vars of classes or enums
    - New operators can't be created and operator precedence order cannot be changed either
*/
#include <iostream>

struct MyVector
{
    float x, y;
    MyVector(float userX, float userY) : x(userX), y(userY){};

    inline MyVector add(const MyVector &added) const // const {...} means that method in class does not modify class
    {
        return MyVector(x + added.x, y + added.y);
    }

    inline MyVector mul(const MyVector &added) const // const {...} means that method in class does not modify class
    {
        return MyVector(x * added.x, y * added.y);
    }

    inline MyVector operator+(const MyVector &added) const // Func whose name is the + operator and does the same as add()
    {
        return MyVector(x + added.x, y + added.y);
    }

    inline MyVector operator*(const MyVector &added) const // Func whose same is the * operator and does the same as mul()
    {
        return MyVector(x * added.x, y * added.y);
    }
};

inline bool operator==(const MyVector &v1, const MyVector &v2) // Could also have written this inside of MyVector class, where it would take only one param instead of two
{
    return v1.x == v2.x && v2.y == v2.y ? true : false; // Inline if statement
}

inline std::ostream &operator<<(std::ostream &stream, const MyVector &v) // Overloading << operator to be able to handle MyVector struct
{
    stream << "(" << v.x << ", " << v.y << ")";
    return stream;
}

// MyVector operator+(int a, char b) {} // This doesn't work cuz need to have at least one param as a class/enum/struct for operator overloading outside of any other types; if this did work, then ppl could mutate the C++ language itself which strictly goes against the design principles

int main()
{
    MyVector pos(4.0, 4.0);
    MyVector displacement(2.0, 3.0);
    MyVector boost(1.0, 5.0);

    // Without overloading operators
    MyVector pos2 = pos.add(displacement.mul(boost));
    std::cout << pos2.x << ", " << pos2.y << std::endl;

    // With overloading operators
    MyVector pos3 = pos + displacement * boost; // Cuz of built-in operator precedence, * will evaluate first
    std::cout << pos3 << std::endl;             // Will have same vals as pos2
    std::cout << (pos2 == pos3) << std::endl;   // Need brackets cuz << takes precedence over ==; returns true
}