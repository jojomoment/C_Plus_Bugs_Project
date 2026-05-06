//
// Created by Elvis on 06/05/2026.
//

#include "Hopper.h"
#include <cstdlib>

Hopper::Hopper(int id, int x, int y, int dir, int health, int hop)
: Bug(id, x, y, dir, health)
{

    {
        hopperJumpLength = hop;
    }

    void Hopper::move()
    {
        if (!alive) return;

        while (isWayBlocked())
        {
            direction = rand()%4 + 1;
        }

        for (int i = 0; i < hopperJumpLength; i++)
        {
            if (isWayBlocked()) break;

            if (direction == 1) position.second--;
            if (direction == 2) position.first++;
            if (direction == 3) position.second++;
            if (direction == 4) position.first--;
        }

        path.push_back(position);

    }

}


