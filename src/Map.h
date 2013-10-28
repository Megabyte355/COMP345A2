/*
 * Map.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef MAP_H_
#define MAP_H_

#include "Cell.h"

class Map
{
    public:
        Map();
        ~Map();

        void initialize(int,int);

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
        bool isValidMap();
        bool isValidPath(Cell, Cell);
        bool isValidCell(Cell);
        bool isValidCell(int, int);

};

#endif /* MAP_H_ */
