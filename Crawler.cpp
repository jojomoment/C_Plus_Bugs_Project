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
    // North
    if(direction == 1 && position.second > 0)
    {
        position.second--;
    }

    // East
    else if(direction == 2  && position.first < 9)
    {
        position.first++;
    }

    // South
    else if(direction == 3 && position.second < 9)
    {
        position.second++;
    }

    // West
    else if(direction == 4 && position.first > 0)
    {
        position.first--;
    }

    // Save new position to path
    path.push_back(position);
}