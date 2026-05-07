#include "Crawler.h"
#include <iostream>

using namespace std;

//constructor definition
Crawler::Crawler(int id,int x,int y,int direction,int health)
    : Bug(id, x, y, direction, health)
{

}


void Crawler::move()
{
    // dead bug
    if (!alive)
        return;

    // if blocked, choose random direction
    while (isWayBlocked())
    {
        direction = rand() % 4 + 1;
    }

    // North
    if(direction == 1)
    {
        position.second--;
    }

    // East
    else if(direction == 2)
    {
        position.first++;
    }

    // South
    else if(direction == 3)
    {
        position.second++;
    }

    // West
    else if(direction == 4)
    {
        position.first--;
    }

    // save new position
    path.push_back(position);
}