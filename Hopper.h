//
// Created by Elvis on 06/05/2026.
//

#pragma once
#include "Bug.h"

//hopper is a type of bug (inheritance)
class Hopper : public Bug
{
private:
    int hopLength;

public:
    Hopper(int id, int x, int y, int dir, int health, int hop);

    void move() override;

    void display();

    void displayHistory();
};