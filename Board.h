#pragma once

#include <vector>
#include "Bug.h"

class Board
{
private:
    std::vector<Bug*> bugs;

    //  10x10 grid
    std::vector<Bug*> grid[10][10];

    void clearGrid();
    void resolveFights();

public:

    void loadFromFile();
    void displayBugs();
    void findBug(int id);
    void tap();
    void displayLifeHistory();
    void displayGrid();
    bool isGameOver();
    void updateGrid();
    void saveLifeHistoryToFile();
};