/*
    - If wanna use values to remove/go through elements in vector, need algorithms lib
    - Should use unordered_maps (aka hashmaps) by default as they are usually faster
    - All keys need to be hashed; custom types we define don't have a way they can be hashed, so we can't use them as keys (unless we define one ourselves)
    - Can hash pointers though, as they are literally just integers
    - Any time user [] operator on unordered map, will always create an empty value at that key if it didn't exist; thus cannot also use these operators for a constant map
    - For const maps, need to use .at() instead of []; it does the same thing, except it never actually mutates the array, just returns the element at a specific index
 */
#include <iostream>
#include <vector>
#include <unordered_map>

struct Person
{
    int m_Age;
    bool m_IsAlive;

    Person() = default; // Mostly same as saying Person() {}
    Person(int age, bool isAlive) : m_Age(age), m_IsAlive(isAlive) {}

    Person(const Person &other)
    {
        this->m_Age = other.m_Age;
        this->m_IsAlive = other.m_IsAlive;
    }
};

int main()
{
    std::vector<int> myVec = {83, 117, 99, 107, 32, 109, 121, 32, 110, 117, 116, 115, 33};
    for (int c : myVec)
        std::cout << static_cast<char>(c);

    myVec.pop_back();    // Removes ! mark at the end
    myVec.push_back(63); // Appends ? mark

    for (std::vector<int>::iterator i = myVec.begin(); i != myVec.end(); i++) // What range-based for loop actually does
        std::cout << static_cast<char>(*i);                                   // Iterator is like a pointer to the value at its index; the iterator at vector.end() is like a null termination character

    for (int i = 0; i < myVec.size(); i++)
    {
        if (myVec[i] == 117)
            myVec.erase(myVec.begin() + i);
    }

    for (int i : myVec)
        std::cout << static_cast<char>(i);

    myVec.clear();                          // Clears all elements
    std::cout << myVec.size() << std::endl; // Size is now 0

    std::unordered_map<std::string, Person> ppl;
    ppl["Erro"]; // Indexing an unordered map with a new key, automatically creates a new value at that key with zero arguments passed into the constructor
    ppl["Faichaan"] = Person{16, true};
    std::cout << ppl["Faichaan"].m_Age;

    // Best way to append new items without calling copy constructor
    Person &obama = ppl["Obama"];
    obama.m_Age = 69;
    obama.m_IsAlive = false;
    std::cout << ppl["Obama"].m_Age << ppl["Obama"].m_IsAlive << std::endl;

    const auto daPpl = ppl;
    // std::cout << daPpl["Faichaan"].m_IsAlive; // Will give error cuz daPpl is a const map
    std::cout << daPpl.at("Faichaan").m_IsAlive;

    // daPpl.at("Joe mama"); // Get out of range error for doing this
    if (daPpl.find("Biden") == daPpl.end()) // Can use .find() to check whether a certain key-value exists; returns .end() if result is false
    {
        std::cout << "Biden doesn't exist! Adding him now..." << std::endl;
        Person &biden = ppl["Biden"];
        biden.m_Age = 100;
        biden.m_IsAlive = true;
    }

    // Old way of iterating through map (using .first and .second)
    for (auto &kv : ppl)
    {
        std::cout << kv.first << ", " << kv.second.m_Age << ", " << (kv.second.m_IsAlive ? "Alive" : "Dead") << std::endl;
    }

    // Newer way
    for (auto &[name, data] : ppl) // Uses structured bindings to convert returned pair obj into two vars
    {
        std::cout << name << ", " << data.m_Age << ", " << (data.m_IsAlive ? "Alive" : "Dead") << std::endl;
    }
}