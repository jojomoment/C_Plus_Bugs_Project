//
// Created by Elvis on 06/05/2026.
//

#include "Bug.h"
#include <fstream>
#include <ctime>

using namespace std;

//constructor
Bug::Bug(int id, int x, int y, int dir, int health)
{
    this->id = id;
    position = {x,y};
    direction = dir;
    this->health = health;
    alive = true;
    path.push_back(position); // bugs movement history
}

//getters
int Bug::getId() { return id; }
pair<int,int> Bug::getPosition() { return position; }
bool Bug::isAlive() { return alive; }

bool Bug::isWayBlocked()
{
    int x = position.first;
    int y = position.second;

    // North
    if (direction == 1 && y == 0)
        return true;

    // East
    if (direction == 2 && x == 9)
        return true;

    // South
    if (direction == 3 && y == 9)
        return true;

    // West
    if (direction == 4 && x == 0)
        return true;

    return false;
}

int Bug::getHealth()
{
    return health;
}

void Bug::setAlive(bool status)
{
    alive = status;
}

const std::list<std::pair<int,int>>& Bug::getPath() const
{
    return path;
}