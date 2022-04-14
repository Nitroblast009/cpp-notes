#include <iostream>
#include <string>

int main()
{
    ; // Literally does nothing

    {
        int x = 0; // x var only accessible within block
    }

    int x, y;
    // std::cin >> x >> y;
    if (x == y)
        std::cout << "Equal";
    else if (x > y)
        std::cout << "Greater";
    else
        std::cout << "Less";
    std::cout << std::endl;

    short i = 10;
    while (i--)
    {
        switch (i)
        {
        case 0:
            break;
        case 1:
            std::cout << "Printed nuts 1 time." << std::endl;
            continue;
        default:
            std::cout << "Printed nuts " << i << " times."
                      << std::endl;
        }
    }

    for (short i = 0; i < 5; i++)
        std::cout << "I can count to " << i << "!\n";

    std::string animals[] = {"cat",
                             "dog",
                             "bird"};
    for (auto &animal : animals)
        std::cout << animal << " is an animal.\n";

    i = 3;
    do
        std::cout << "Printed stuff" << std::endl;
    while (i--);
    /* Above equivalent to:
        std::cout << "Printed stuff" << std::endl;
        while (i--)
            std::cout << "Printed stuff" << std::endl;
     */

    // Note: C++ try-catch statements are very lax and need to specify what error type was thrown
    try
    {
        int num;
        std::cin >> num;
        if (!num)
            throw std::to_string(num);
        std::cout << "No error.";
    }
    catch (std::string &e) // Catch for string errors thrown
    {
        std::cerr << e << '\n'; // Use error stream
    }
    catch (int &e) // Catch for int errors thrown
    {
        e = 69;
        std::cerr << e;
    }

    std::cerr << "Test";
    std::cout << "test";
}