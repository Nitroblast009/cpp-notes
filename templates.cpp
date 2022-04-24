/*
    - Templates are like macros that don't get used until they are called
    - Instead of having to write multiple overloads for functions, can use templates
    - Use <> to call parameters in template
    - Can use templates to make compiler write code for you with instructions
    - <typename T> is synonymous with <class T>
*/

#include <iostream>

template <typename T, int N> // Template goes on top of related class/func
class Arr
{
public:
    T m_Arr[N];
};

template <typename T> // Not actual code, gets materialized during compilation
void printer(T val)
{
    std::cout << val << std::endl;
} // All other overloads of this function don't exist until they are called

int main()
{
    printer<int>(5); // void printer(int val) is now a function that exists
    printer(10);

    Arr<std::string, 10> a;
    std::cout << a.m_Arr << std::endl; // m_Arr is an array pointer of size 10 to std::string
}