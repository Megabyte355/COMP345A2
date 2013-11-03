//============================================================================
// Name        : COMP345A2.cpp
// Author      : Gary Chang
// Version     : 1.0
// Description : Program Driver for Assignment 2
//============================================================================

#include <iostream>
#include <memory>
#include "Map.h"
#include "MapView.h"

int main(int argc, char** argv)
{

    // Initialization
    Map mapModel(20,20);
    std::shared_ptr<MapView> mapView = std::make_shared<MapView>();
    mapModel.attach(mapView);

    mapView->initialize();

//    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!;
//
//    Map m;
//
//    m.setStartCell(0,3);
//    m.setEndCell(9,5);
//
//    m.setCell(Cell::CellType::Wall, 1, 0);
//    m.setCell(Cell::CellType::Wall, 1, 1);
//    m.setCell(Cell::CellType::Wall, 1, 2);
//    m.setCell(Cell::CellType::Wall, 1, 3);
//    m.setCell(Cell::CellType::Wall, 1, 4);
//    m.setCell(Cell::CellType::Wall, 1, 5);
//    m.setCell(Cell::CellType::Wall, 1, 6);
//
//    m.setCell(Cell::CellType::Wall, 7, 9);
//    m.setCell(Cell::CellType::Wall, 7, 8);
//    m.setCell(Cell::CellType::Wall, 7, 7);
//    m.setCell(Cell::CellType::Wall, 7, 6);
//    m.setCell(Cell::CellType::Wall, 7, 5);
//    m.setCell(Cell::CellType::Wall, 7, 4);
//
//    m.setCell(Cell::CellType::Wall, 4, 3);
//    m.setCell(Cell::CellType::Wall, 5, 3);
//    m.setCell(Cell::CellType::Wall, 6, 3);
//
//    std::vector<CellLocation> test = m.getShortestPath(*m.getStartCell(), *m.getEndCell());
//    m.printMap();
//    cout << m.validateMap() << endl;



    return 0;
}
