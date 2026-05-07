#pragma once
#include <utility>
#include <list>
using namespace std;

class Bug
{
protected:
    int id;
    pair<int, int> position; //stores bugs x and y postiton
    int direction;
    int health;
    bool alive;
    list<std::pair<int, int>> path; // tracks bugs movement

public:
    Bug(int id, int x, int y, int dir, int health);

    virtual ~Bug() = default;// destructor that runs whenever a bug object is deleted

    virtual void move() = 0;

    virtual void display() = 0;

    virtual void displayHistory() = 0;


    bool isWayBlocked();

    int getId();
    pair<int, int> getPosition();
    bool isAlive();

    int getHealth();
    void setAlive(bool status);

    const list<std::pair<int,int>>& getPath() const;
};