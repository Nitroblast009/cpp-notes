/*
    - Virtual methods are the C++ term for abstract methods
    - Pretty minimal impact
    - Should use override keyword on function that is overriding the virtual function
    - Important cuz polymorphism
    - Not all virtual methods must be overwritten
    - Can override destructors too, but not constructors
*/
#include <iostream>

class Entity
{
public:
    virtual std::string GetName() { return "Entity"; } // Virtual keyword means that this function can be overwritten at runtime
};

class Player : public Entity
{
private:
    std::string m_Name; // Private members should start with m_

public:
    Player(const std::string &name) : m_Name(name) {}
    std::string GetName() override { return this->m_Name; } // Override keyword is a courtesy (like a decorator) to just make sure and reinforce that this function is overwritting another virtual (=abstract) function
};

int main()
{
    Entity e = Entity();
    std::cout << e.GetName() << std::endl;

    Player p = Player("Anon");
    std::cout << p.GetName() << std::endl;

    Entity *ePtr = &p;
    std::cout << ePtr->GetName() << std::endl; // Without virtual keyword, uses Entity's GetName() method cuz polymorphism
}