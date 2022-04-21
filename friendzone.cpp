/*
    - Note friendships shouldn't be overused as they kinda defeat the whole purpose of OOP
    - Allow certain functions/classes to access private attributes/methods
*/
#include <iostream>

class DontTouchMe
{
private:
    int var;
    DontTouchMe(int x) : var(x) {}

public:
    DontTouchMe() : DontTouchMe(69) {} // Can delegate constructor to another
    friend void iCanTouchYou();        // Function signature of friend
    friend class OtherClass;           // Friended other class
};

class OtherClass
{
public:
    static void hahaImmaTouchYou()
    {
        DontTouchMe dtm3 = DontTouchMe(100);
        std::cout << dtm3.var;
    }
};

void iCanTouchYou()
{
    DontTouchMe dtm2 = DontTouchMe();
    std::cout << dtm2.var; // Can access private attributes cuz is a friend
}

int main()
{
    DontTouchMe dtm1 = DontTouchMe();
    // std::cout << dtm.var; // Doesn't work cuz private var
    iCanTouchYou();
    OtherClass::hahaImmaTouchYou();
}