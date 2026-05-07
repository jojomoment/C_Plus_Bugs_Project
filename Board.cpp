//
// Created by Elvis on 06/05/2026.
//

#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

void Board::loadFromFile()
{
    ifstream file("bugs.txt");

    if (!file)
    {
        cout << "FAILED TO OPEN bugs.txt" << endl;
        return;
    }

    cout << "bugs.txt opened successfully" << endl;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        char type, comma;
        int id, x, y, dir, health, hop;

        ss >> type >> comma
           >> id >> comma
           >> x >> comma
           >> y >> comma
           >> dir >> comma
           >> health;

        if (type == 'C')
        {
            bugs.push_back(new Crawler(id, x, y, dir, health));
        }
        else if (type == 'H')
        {
            ss >> comma >> hop;
            bugs.push_back(new Hopper(id, x, y, dir, health, hop));
        }


    }
    updateGrid();
}

void Board::displayBugs()
{
    for (Bug* b : bugs)
    {
        b->display();
    }
}



    void Board::findBug(int id)
    {
        for (Bug* b : bugs)
            {
            if (b->getId() == id)
                {
                cout << "Found bug " << id << endl;
                b->display();
                return;
            }
        }
    cout << "bug " << id << " not found\n";
    }

void Board::tap()
{
    cout << "\nTapping board...\n";

    for (Bug* b : bugs)
    {
        b->move();
    }

    updateGrid();       // place bugs into cells
    resolveFights();    // handle collisions
    updateGrid();       // refresh after deaths

    cout << "Tap complete.\n";
}

void Board::clearGrid()
{
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            grid[x][y].clear();
        }
    }
}


void Board::updateGrid()
{
    // clear grid first
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            grid[x][y].clear();
        }
    }

    // re-add all alive bugs into grid
    for (Bug* b : bugs)
    {
        if (b->isAlive())
        {
            auto pos = b->getPosition();

            int x = pos.first;
            int y = pos.second;

            if (x >= 0 && x < 10 && y >= 0 && y < 10)
            {
                grid[x][y].push_back(b);
            }
        }
    }
}

void Board::resolveFights()
{
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            auto &cell = grid[x][y];

            if (cell.size() <= 1) continue;

            // find strongest bug
            Bug* strongest = cell[0];

            for (Bug* b : cell)
            {
                if (b->getHealth() > strongest->getHealth())
                    strongest = b;
            }

            // kill others
            for (Bug* b : cell)
            {
                if (b != strongest)
                {
                    b->setAlive(false);
                }
            }

            // keep only strongest in cell
            cell.clear();
            cell.push_back(strongest);
        }
    }
}

bool Board::isGameOver()
{
    int aliveCount = 0;

    for (Bug* b : bugs)
    {
        if (b->isAlive())
            aliveCount++;
    }

    return aliveCount <= 1;
}

void Board::displayGrid()
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            cout << "(" << x << "," << y << "): ";

            if (grid[x][y].empty())
            {
                cout << "empty";
            }
            else
            {
                cout << grid[x][y][0]->getId();
            }

            cout << endl;
        }
    }
}
void Board::displayLifeHistory()
{
    for (Bug* b : bugs)
    {
        b->displayHistory();
    }
}





