//
// Created by Elvis on 06/05/2026.
//

#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"
#include <fstream>
#include <sstream>

void board::loadFromFile()
{
    ifstream file("bugs.txt");  //reads file
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        char type;
        int id,x,y,dir,health,hop;

        ss >> type; ss.ignore();
        ss >> id; ss.ignore();
        ss >> x; ss.ignore();
        ss >> y; ss.ignore();
        ss >> dir; ss.ignore();
        ss >> health; ss.ignore();

        if (type == 'C')
        {
            bugs.push_back(new Crawler(id, x, y, dir, health));
        }
        else
        {
            ss.ignore();
            ss >> hop;
            bugs.push_back(new Hopper(id, x, y, dir, health, hop));
        }

    }

}