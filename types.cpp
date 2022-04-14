#include <iostream>
#include <math.h>
#include <typeinfo>

void func(int &x) { x = 0; }

enum J2 // Plain enum starting at 0 (all values must be int)
{
    A,
    B = 9,
};

enum class L2 // Class enum (preferred)
{
    C,
    E,
    D,
};

typedef unsigned int UINT; // Makes type alias called UINT; doesn't make new type
typedef double FLOAT64;    // Makes type alias called FLOAT64

int main()
{
    // Numerical - Integrals (signed by default, vary in size):

    int a = 2147483647;
    int b = -2147483648;
    unsigned int c = 4294967295;

    short int d = 32767; // Remember 32 thousand as constraints
    short int e = -32768;
    unsigned short int f = 65535;

    long int g = 2147483647; // On windows, long int and int are same size, but on certain OS, int datatype is made smaller, whereas long int is not
    long int h = -2147483648;
    unsigned long int i = 4294967295;

    long long int j = 9223372036854775807; // Could also use: (long long int) pow(2,63) - 1;
    long long int k = -9223372036854775808;
    unsigned long long int l = 18446744073709551615;

    // Numerical - Fractional (always signed, uses scientific notation to represent big nums, vary in precision):

    float m = INFINITY; // No real point in thinking of floating numbers as having a max or min value
    float n = -INFINITY;
    float o = 0.1234567; // Has up to 7 decimal places

    double p = INFINITY;
    double q = -INFINITY;
    double r = 0.123456789012345; // Has up to 15 decimal places, with "double" the precision of a float; should use by default

    long double s = INFINITY;
    long double t = -INFINITY;
    long double u = 0.1234567890123456789; // Has up to 19 decimal places

    // Text-related:

    char v = '0'; // Stored as number internally; number corresponds to ASCII code
    char w = 48;  // Can be perceived as signed or unsigned, which could cause confusion; should only use char if value is 0-127
    signed char x = -1;
    unsigned char y = 255; // Same character as above but different way of storing it

    char z[] = "text";       // A C string (aka character array) with a NULL terminator character at the end ('\0'); use if need to modify text
    const char *a2 = "text"; // A char pointer that points to a string, which must be const so pointer location doesn't change; use if don't need to modify text
    std::string b2 = "text"; // A proper C++ string; should use this preferably for text, as it has much more functionality than above two

    // Pointers (& is to get address, * is to get value at address):

    int c2 = 69;
    int *d2 = &c2;       // Mutable ptr
    int *const e2 = &c2; // Constant ptr

    int f2 = 1;
    func(f2); // f9 becomes 0, as paramater required int& instead of int, meaning f9 was passed in by reference

    void *g2 = nullptr; // void* means a pointer than can point to any datatype; should use nullptr instead of NULL, since NULL is just a macro for 0, whereas nullptr is a pointer to a null object

    // Other:

    bool h2 = true;  // Also equal to any number except 0
    bool i2 = false; // Also equal to 0

    // Using enums above int main()
    int k2 = B;    // Plain enum where values are ints and are at same scope; pretty much like run-time macros
    L2 m2 = L2::C; // Class enum is like a whole new type; need to use scope operator for values within

    // Using typedefs above int main()
    UINT n2 = 4294967295;        // Same as type unsigned int
    FLOAT64 o2 = 0.234923842934; // Same as type double

    auto x9 = nullptr; // A placeholder used for a variable with a complicated type; can get type using: typeid(var).name()

    std::cout.precision(19); // Set precision of cout function, so can display full precision of floating-point values
    std::cout << x9;
}