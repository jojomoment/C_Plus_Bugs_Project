#include "Board.h"
#include <iostream>
using namespace std;

int main() {
    Board board;
    int choice;

    do {
   cout << "\n1.Load\n2.Display\n3.Find\n4.Tap\n5.Grid\n6.Display Life History of all bugs\n8.Exit\n";        cin >> choice;

        switch(choice)
            {
            case 1: board.loadFromFile(); break;
            case 2: board.displayBugs(); break;
            case 3:
                {
                int id;
                cout << "Enter id: ";
                cin >> id;
                board.findBug(id);
                break;
            }
            case 4:
                board.tap();
                board.displayBugs();
                break;

            case 5:
                board.updateGrid();
                board.displayGrid();
                break;

            case 6:
                board.displayLifeHistory();
                break;
        }

    } while (choice != 8);

    return 0;
}