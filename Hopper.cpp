//
// Created by Elvis on 06/05/2026.
//

#include "Hopper.h"
#include <cstdlib>

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




