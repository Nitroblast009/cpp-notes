#include <iostream>
#include <string>

class Animal
{
private:
    std::string species;
    int lifeSpan;

public:
    Animal(std::string userSpecies, int lifeSpan = 100) : species(userSpecies), lifeSpan(lifeSpan) {} // Constructor params can have same name as attributes
    Animal() : species("Unknown animal"), lifeSpan(0){};

    std::string animalOutText() const
    {
        return "This is a " + this->species + " with a lifespan of " + std::to_string(this->lifeSpan) + ".\n";
    }
};

std::ostream &operator<<(std::ostream &stream, const Animal &animal) // Because the animal object is const here, should not change; calling one of its methods might make it change tho, which is why I can only call const methods that do not modify the instance
{
    stream << animal.animalOutText();
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const Animal *animal)
{
    stream << animal->animalOutText();
    return stream;
}

int main()
{
    // All difference ways to initialize class (without new is on stack, with new is on heap)
    Animal a = {"Human"};
    Animal b("Cat", 16);               // Should not use this way as it is ambiguous; compiler could interpret this as a function declaration
    Animal c = Animal("Dog", 20);      // Assigning via copy; this is the best way to initialize classes
    Animal *d = new Animal{"Frog", 5}; // Creates new animal instance in heap memory
    Animal *e = new Animal("Lynx", 13);

    // Use empty constructor
    Animal x = Animal();
    std::cout << a << b << c << d << e << x;
}