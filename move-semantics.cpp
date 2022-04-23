/*
    - Move semantics: instead of making a copy of a temp rvalue passed in, can move that temp value instead
    - Move constructor shallow copies given object
    - At the end of move constructor, must make given object hollow cuz its destructor will delete the object and, by effect, the object returned by the move constructor (cuz it is a shallow copy)
*/

#include <iostream>
#include <cstring>

class Obj
{
public:
    char *m_Arr;
    int m_Size;

    Obj() = default; // Uses default C++-given constructor where all values are set to their defaults

    Obj(const char *c) // Constructor
    {
        this->m_Size = strlen(c) + 1;
        this->m_Arr = new char[m_Size];
        strcpy(m_Arr, c);
        std::cout << "Constructed!" << std::endl;
    }

    Obj(const Obj &other) // Copy constructor
    {
        this->m_Size = other.m_Size;
        this->m_Arr = new char[m_Size];
        strcpy(m_Arr, other.m_Arr);
        std::cout << "Copied!" << std::endl;
    }

    ~Obj() // Destructor
    {
        delete m_Arr;
        std::cout << "Desconstructed!" << std::endl;
    }

    Obj(Obj &&other) // Move constructor
    {
        m_Size = other.m_Size;
        m_Arr = other.m_Arr;

        other.m_Arr = nullptr; // Need to make temp obj given hollow
    }
};

void printObjCopy(Obj o)
{
    std::cout << o.m_Arr << std::endl;
}

void printObjLvalueReference(Obj &o)
{
    std::cout << o.m_Arr << std::endl;
}

void printObjRvalueReference(Obj &&o)
{
    std::cout << o.m_Arr << std::endl;
}

int main()
{
    Obj o{"Hello, world!"};
    printObjCopy(o);                              // o gets copied
    printObjLvalueReference(o);                   // actual o object used, not copied (most efficient)
    printObjRvalueReference(Obj("Suck my nuts")); // Takes in rvalue and is more efficient than copying

    std::cout << "---END OF PROGRAM---" << std::endl;
}