#include <iostream>
#include <string>

class A
{
private:
    std::string str;
    double db;

public:
    int num;

    A() : num(5), str("hello") // Member initializer list (is called before constructor body) and should be listed in order of attributes declared; is like Dart shortcut for intializing class vars
    {
        db = 5.0; // Creates var twice: once at beginning and again once constructor is called (same as saying double db; db = 5.0;); this effect becomes more noticeable for classes
        std::cout << "A constructor called, giving " << num << " and " << str << std::endl;
    }
    A(const std::string &myStr) : num(stoi(myStr)), str(myStr) {} // Use stoi() to convert string to int (need to include <string>)
};

int main()
{
    A();         // Calls empty constructor
    A obj2("5"); // Calls second constructor
    std::cout << obj2.num;
}