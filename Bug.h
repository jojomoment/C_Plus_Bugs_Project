//
// Created by Elvis on 06/05/2026.
//

#pragma once
#include <utility>
#include <list>
using namespace std;

class Bug {
protected:
    int id;
    pair<int,int> position;
    int direction;
    int health;
    bool alive;
    list<pair<int,int>> path;

public:
    Bug(int id, int x, int y, int dir, int health);

    virtual void move() = 0;

    bool isWayBlocked();

    int getId();
    pair<int,int> getPosition();
    bool isAlive();
};


