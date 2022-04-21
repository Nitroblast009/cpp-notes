/*
    - Pure virtual functions make class into an interface
    - Cannot be instantiated
    - Can only instantiate class if it has all its pure virtual functions implemented
*/

#include <iostream>

class Printable // Interface called Printable; any class that extends from it, will be guaranteed to have a getClassName() func
{
public:
    virtual inline std::string getClassName() const = 0; // = 0 makes virtual function into pure virtual function
};

class Entity : public Printable
{
public:
    virtual std::string GetName() { return "Entity"; };
    inline std::string getClassName() const override { return "Entity"; }; // Overrides pure virtual function (const keyword before override); overrides the same way for Player class if not overide again
};

class Player : public Entity
{
private:
    std::string m_Name; // Private members should start with m_

public:
    Player(const std::string &name) : m_Name(name) {}
    std::string GetName() override { return this->m_Name; } // Override keyword is a courtesy (like a decorator) to just make sure and reinforce that this function is overwritting another virtual (=abstract) function
    inline std::string getClassName() const override { return m_Name; }
};

void printName(Printable &obj) // Takes in a class that is guaranteed to be printable (by implementing Printable interface)
{
    std::cout << obj.getClassName() << std::endl;
}

int main()
{
    Entity e = Entity();
    std::cout << e.GetName() << std::endl;

    Player p = Player("Anon");
    std::cout << p.GetName() << std::endl;

    Entity *ePtr = &p;
    std::cout << ePtr->GetName() << std::endl; // Without virtual keyword, uses Entity's GetName() method cuz polymorphism

    printName(e);
    printName(p);
}