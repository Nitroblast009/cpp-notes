#include <iostream>

class Player
{
private:              // Private accessor is technically unneeded here but should still put it for clarity's sake
    int playerZ = 69; // Private attribute

public:                                 // Constructors must be listed under public
    Player(const int &x, const int &y); // Constructor defined outside of class
    int playerX, playerY;
    int speed = -10;

    void printCoords()
    {
        std::cout << "(" << playerX << ", " << playerY << ", " << playerZ << ")" << std::endl;
    }
};

Player::Player(const int &x, const int &y)
{
    playerX = x;
    playerY = y;
} // Is a function and thus no ending semicolon

class Point
{
private:
    int x, y, z, w;

public:
    Point(const int &coord) { x = y = z = w = coord; } // Assign multiple vars to the same value inline by chaining = operators
    void printData() { std::cout << x << y << z << w << std::endl; }
};

int main()
{

    Player player0(9, 2);           // Create objects like this with this shortcut (on stack)
    Player player00 = Player(9, 2); // Create object by using copy constructor (copy object on right to player00); not preferred but works
    player00.printCoords();
    Player *p, *p2;
    {
        Player player1(5, 2); // Creates new object in stack memory
        p = &player1;
        player1.printCoords(); // Same res as below
        (*p).printCoords();    // Same res as below
        p->printCoords();      // -> is like . for pointers to classes; it also dereferences the pointer just like *

        Player *player2 = new Player(2, 8); // Creates new object in heap memory; using new keyword returns a pointer and thus player2 is just a Player pointer
        p2 = player2;
    }
    p->printCoords();  // player1 object has been discared (cuz its out of stack) so this may not work
    p2->printCoords(); // Can't just re-use player2 pointer here cuz it was declared in stack memory and gets discarded
    delete p2;         // Must delete object out of heap memory cuz C++ doesn't know when we're done with the object; this is called garbage collecting

    Point pnt(5);
    pnt.printData();
}
