/*
 * Cell.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef CELL_H_
#define CELL_H_

#include "CellOccupant.h"
#include <memory>

class Cell
{
    public:
        enum CellType
        {
            Wall, Surface, Empty, Start, End
        };

        Cell();
        Cell(CellType);
        virtual ~Cell();

        CellType getType();
        void setType(CellType);
        void clearOccupant();
        void setOccupant(std::shared_ptr<CellOccupant>);
        std::shared_ptr<CellOccupant> getOccupant();

    private:
        CellType type;
        std::shared_ptr<CellOccupant> occupant;
};

#endif /* CELL_H_ */
