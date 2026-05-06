//include guard
#pragma once

//file import
#include "Bug.h"

//creating a bug sub class
class Crawler : public Bug
{

public: // accessable outside of class

    //default constructor
    Crawler();

    //constructor
    Crawler(int id,int x,int y,int direction,int health);

    // Override move()
    void move() override;
};