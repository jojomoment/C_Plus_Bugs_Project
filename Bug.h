#pragma once
#include <utility>
#include <list>

class Bug
{
protected:
    int id;
    std::pair<int, int> position;
    int direction;
    int health;
    bool alive;
    std::list<std::pair<int, int>> path;

public:
    Bug(int id, int x, int y, int dir, int health);

    virtual ~Bug() = default;   // IMPORTANT for polymorphism

    virtual void move() = 0;

    virtual void display() = 0;

    virtual void displayHistory() = 0;


    bool isWayBlocked();

    int getId();
    std::pair<int, int> getPosition();
    bool isAlive();

    int getHealth();
    void setAlive(bool status);
};