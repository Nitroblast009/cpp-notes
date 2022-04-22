/*
    - Raw function pointers can only handle simple lambdas without any captures
    - Lambdas are anonymous functions and are mainly used for function pointers
    - Have 3 sets of brackets: [captures](params){body}
    - Since lambdas are there own functions, they have their own scope and outside vars can only be accessed if they have first been "captured"
*/

#include <iostream>
#include <functional>

void loopThrough(int (&arr)[10], void (*func)(int)) // [n] is just fancy syntax for a pointer that points to an array of size n; need to put & in brackets to mean reference to array pointer
{
    for (int num : arr)
    {
        func(num);
    }
}

void lambdaThrough(int (&arr)[10], std::function<void(int)> func) // Function class includes lambdas
{
    for (int num : arr)
    {
        func(num);
    }
}

void print(int num) { std::cout << num << std::endl; }

int main()
{
    int basicNums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    loopThrough(basicNums, print);
    loopThrough(basicNums, [](int num)
                { std::cout << num; }); // Same as above but lambda

    std::cout << std::endl;
    char seperator = '-';
    lambdaThrough(basicNums, [=](int num)
                  { std::cout << num << seperator; basicNums; }); // [=] captures all vars in main (as copy) scope and allows for their use no matter where lambda gets passed; can use [&] to use all the actual vars in main or just list them off individually
}