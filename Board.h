#pragma once

#include <vector>
#include "Bug.h"

class Board
{
private:
    std::vector<Bug*> bugs;

public:
    void loadFromFile();
    void displayBugs();
    void findBug(int id);
    void tap();
};