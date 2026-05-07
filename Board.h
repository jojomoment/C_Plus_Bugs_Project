#pragma once

#include <vector>
#include "Bug.h"

class Board
{
private:
    std::vector<Bug*> bugs;

    // 🔥 NEW: 10x10 grid
    std::vector<Bug*> grid[10][10];

    void clearGrid();
    void updateGrid();
    void resolveFights();

public:
    void loadFromFile();
    void displayBugs();
    void findBug(int id);
    void tap();

    // optional but VERY useful later
    void displayGrid();



    bool isGameOver();
};