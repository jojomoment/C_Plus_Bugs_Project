//
// Created by Elvis on 06/05/2026.
//

#include "Hopper.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// hopper constructor
// specific variable, hoplength
Hopper::Hopper(int id, int x, int y, int dir, int health, int hop)
    : Bug(id, x, y, dir, health)
{
    hopLength = hop;
}


void Hopper::move()
{
    // dead bug
    if (!alive)
        return;

    // choose new direction if its blocked
    while (isWayBlocked())
    {
        //random direction for bug to face
        direction = rand() % 4 + 1;
    }

    // move hopLength spaces
    for (int i = 0; i < hopLength; i++)
    {
        // stop if edge reached
        if (isWayBlocked())
            break;

        // North
        if (direction == 1)
            position.second--;

        // East
        else if (direction == 2)
            position.first++;

        // South
        else if (direction == 3)
            position.second++;

        // West
        else if (direction == 4)
            position.first--;
    }

    // record new position
    path.push_back(position);
}

void Hopper::display()
{
    string dirText;

    if(direction == 1) dirText = "North";
    else if(direction == 2) dirText = "East";
    else if(direction == 3) dirText = "South";
    else dirText = "West";

    cout << id
         << " Hopper "
         << "(" << position.first << "," << position.second << ") "
         << health << " "
         << dirText << " "
         << hopLength << " "
         << (alive ? "Alive" : "Dead")
         << endl;
}


void Hopper::displayHistory()
{
    cout << id << " Hopper Path: ";

    for (auto &p : path)
        cout << "(" << p.first << "," << p.second << "),";

    cout << (alive ? " Alive!" : " Dead!") << endl;
}




