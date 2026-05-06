//
// Created by Elvis on 06/05/2026.
//

#pragma once
#include <vector>
#include "Bug.h"

class Board {
    private:
    vector<Bug*> bugs;

    public:
    void loadFromFile();
    void displayBugs();
    void findBug(int id);
    void tap();

};
