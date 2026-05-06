//
// Created by Elvis on 06/05/2026.
//

#pragma once
#include "Bug.h"

class Hopper : public Bug {
    private:
    int hopperJumpLength;

    public:
    Hopper(int id, int x, int y, int dir, int health, int hop);

    void move() override;
};