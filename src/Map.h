/*
 * Map.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef MAP_H_
#define MAP_H_

#include "Cell.h"
#include "PathFinder.h"
#include "Observable.h"
#include <vector>
#include <iostream>

class Map: public Observable
{
    public:
        Map();
        ~Map();

        void initialize(int, int);

        // Map properties
        int getWidth();
        int getHeight();

        // Cell operations
        std::shared_ptr<Cell> getCell(int, int);
        std::shared_ptr<Cell> getStartCell();
        std::shared_ptr<Cell> getEndCell();
        void setCell(Cell::CellType, int, int);
        void setStartCell(int, int);
        void setEndCell(int, int);

        // Validations
        bool validateMap();
        bool isValidCell(Cell);
        bool isValidCell(int, int);
        bool isValidCell(CellLocation);
        bool isOccupiable(CellLocation);
        bool isValidPath(Cell, Cell);

        // Path calculation
        std::vector<CellLocation> getShortestPath(Cell&, Cell&);

        // IObservable functions
        void attach(std::shared_ptr<Observer>) override;
        void detach(std::shared_ptr<Observer>) override;
        void notify() override;

        void printMap();

    private:
        // Map variables
        std::vector<CellLocation> shortestPath;
        std::vector<std::vector<std::shared_ptr<Cell>>>matrix;
        int mapWidth;
        int mapHeight;

        // IObserver variables
        std::vector<std::shared_ptr<Observer>> observers;
    };

#endif /* MAP_H_ */
