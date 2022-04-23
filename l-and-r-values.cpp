/*
    - Oh f***, here we go...
    - Lvalues are like location values that have some element of storage
    - Rvalues are temporary resources values that are just plain values of the system and can't be changed
    - & means lvalue reference
    - && means rvalue reference
*/

#include <iostream>

void copy(int val) // Makes lvalue val with same value
{
    val = 0;
}

void lvalueReference(int &val)
{
    val = 9;
}

void constLvalueReference(const int &val)
{
    // T-T
}

void rvalueReference(int &&val)
{
    val = 19;
    std::cout << val << std::endl;
}

int &returnVarBigger(int &val)
{
    val++;
    return val;
}

int varBigger(int &val)
{
    val++;
    return val;
}

int main()
{
    int a, b;
    a = 5; // a is an lvalue; 5 is an rvalue
    b = 10;
    // 5 = a; // Cannot set an rvalue equal to something; the expression must be a modifiable (non-const) lvalue

    copy(a);
    std::cout << a << std::endl; // a is still 5
    lvalueReference(a);
    std::cout << a << std::endl; // a becomes 9, cuz actual lvalue was passed
    // lvalueReference(10);         // Does not work cuz can't convert rvalue into lvalue, unless lvalue is const
    constLvalueReference(10); // Can pass in rvalue for lvalue reference cuz its const
    returnVarBigger(b);       // b is 11 now
    returnVarBigger(b) = -6;  // b is now -6 instead of just 12
    // varBigger(a) = 4; // This would not work as varBigger returns an rvalue insted of an lvalue reference like above (like saying 6 = 4;)
    std::cout << b << std::endl;

    int &&c = 10; // c is just a reference for the number 10, not actually a variable in memory
    c = 69;       // c is now a reference to the number 69
    // int &&d = a;  // Will not work cuz d can't be a reference to an lvalue (cuz its an rvalue reference)

    std::cout << c << std::endl;

    int v[] = {1, 2, 3, 4, 5};
    for (int &i : v)
    {
        std::cout << i << std::endl;
    }
}