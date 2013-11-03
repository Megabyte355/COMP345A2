//============================================================================
// Name        : COMP345A2.cpp
// Author      : Gary Chang
// Version     :
// Copyright   : Free Software
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;



#include "Map.h"
#include <iostream>

int main()
{
    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!;

    Map m;

    m.setStartCell(0,3);
    m.setEndCell(9,5);

    m.setCell(Cell::CellType::Wall, 1, 0);
    m.setCell(Cell::CellType::Wall, 1, 1);
    m.setCell(Cell::CellType::Wall, 1, 2);
    m.setCell(Cell::CellType::Wall, 1, 3);
    m.setCell(Cell::CellType::Wall, 1, 4);
    m.setCell(Cell::CellType::Wall, 1, 5);
    m.setCell(Cell::CellType::Wall, 1, 6);

    m.setCell(Cell::CellType::Wall, 7, 9);
    m.setCell(Cell::CellType::Wall, 7, 8);
    m.setCell(Cell::CellType::Wall, 7, 7);
    m.setCell(Cell::CellType::Wall, 7, 6);
    m.setCell(Cell::CellType::Wall, 7, 5);
    m.setCell(Cell::CellType::Wall, 7, 4);

    m.setCell(Cell::CellType::Wall, 4, 3);
    m.setCell(Cell::CellType::Wall, 5, 3);
    m.setCell(Cell::CellType::Wall, 6, 3);

    
    cout << m.isValidMap() << endl;
    m.printMap();
    cout << m.isValidMap() << endl;
    return 0;
}
