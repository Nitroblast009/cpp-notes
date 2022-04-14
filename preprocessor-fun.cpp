// Practice for #define, #undef, #ifdef, #endif
#define VAL // Can have macros with no value that just exist
#define PI 3.14
#define lotsaEs "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
// DONT MAKE FUNCTION MACROS! #define square(a) a * a
#undef PI
using namespace std;

int main()
{
#ifdef PI
    cout << "PI macro has been defined";
#endif
#ifndef PI
    // Cause preprocessor error: #error
#endif
}