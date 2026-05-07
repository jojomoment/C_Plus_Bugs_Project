//include guard
#pragma once

//file import
#include "Bug.h"

//creating a bug sub class
class Crawler : public Bug
{

public: // accessable outside of class

    //constructor
    Crawler(int id,int x,int y,int direction,int health);

    // move function override
    // replaces base version of move
    void move() override;

    // display function
    void display();

    // display history function
    void displayHistory();
};