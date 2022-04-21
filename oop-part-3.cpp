/*
    - A derived class inherits all base class methods and attributes except for its constructors/deconstructors overloaded operators, and friend functions
    - 3 different types of inheritance: public, protected, and private; public inheritance is mostly used
*/
#include <iostream>

class Entity
{
public:
    bool isAlive = true;
    int x, y;

    Entity(int userX, int userY) : x(userX), y(userY) { std::cout << "Called Entity constructor." << std::endl; }

protected:
    inline void die() { this->isAlive = false; } // Is inherited as protected function
};

class Person : public Entity
{
public:
    std::string name;
    bool doIWantToDie;
    Person(std::string userName, int userX, int userY, bool death) : Entity(userX, userY), name(userName), doIWantToDie(death) { std::cout << "Called Person constructor." << std::endl; } // Need to call parent's constructor in member initialization list

    inline void move(const int &x, const int &y)
    {
        this->x = x;
        this->y = y;
    }

    inline void askToDie()
    {
        if (doIWantToDie)
            this->die();
    }
};

std::ostream &operator<<(std::ostream &stream, const Entity &e)
{
    stream << "Entity is " << (e.isAlive ? "alive" : "dead")
           << " and at " << e.x << ", " << e.y << ".\n";
    return stream;
}

int main()
{
    Entity thing1 = Entity(-10, 25);
    std::cout << thing1;

    Person p1 = Person("Faichaan", 19, -6, true);
    p1.askToDie();
    std::cout << p1; // Cuz of polymorphism, << operator is also overloaded to work with Person class
}