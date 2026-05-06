//
// Created by Elvis on 06/05/2026.
//

#include "Bug.h"

using namespace std;

Bug::Bug(int id, int x, int y, int dir, int health)
{
    this->id = id;
    position = {x,y};
    direction = dir;
    this->health = health;
    alive = true;
    path.push_back(position);
}

int Bug::getId() { return id; }
pair<int,int> Bug::getPosition() { return position; }
bool Bug::isAlive() { return alive; }
bool Bug::isWayBlocked(){return false;}