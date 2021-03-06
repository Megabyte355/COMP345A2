/*
 * Cell.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef CELL_H_
#define CELL_H_

#include "CellOccupant.h"
#include "CellLocation.h"
#include <memory>

class Cell
{
    public:
        enum CellType
        {
            Wall, Surface, Start, End, Empty
        };

        // Constructors
        Cell(int, int);
        Cell(CellType, int, int);
        ~Cell();

        // Getters and Setters
        int getX();
        int getY();
        void setX(int);
        void setY(int);
        CellType getType();
        void setType(CellType);
        std::shared_ptr<CellOccupant> getOccupant();
        void setOccupant(std::shared_ptr<CellOccupant>);
        CellLocation getLocation();
        std::vector<CellLocation> getNeighbors();

        // Other functions
        void clearOccupant();
        bool isOccupiable();

    private:
        CellLocation location;
        CellType type;
        std::shared_ptr<CellOccupant> occupant;
};

#endif /* CELL_H_ */
