/*
 * Cell.cpp
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#include "Cell.h"

Cell::Cell(int x, int y)
{
    this->type = Surface;
    location.x = x;
    location.y = y;
}

Cell::Cell(CellType type, int x, int y)
{
    this->type = type;
    location.x = x;
    location.y = y;
}

Cell::~Cell()
{
}

void Cell::setX(int x)
{
    location.x = x;
}

void Cell::setY(int y)
{
    location.y = y;
}

int Cell::getX()
{
    return location.x;
}

int Cell::getY()
{
    return location.y;
}

Cell::CellType Cell::getType()
{
    return type;
}

void Cell::setType(CellType type)
{
    this-> type = type;
}

void Cell::clearOccupant()
{
    occupant.reset();
}

void Cell::setOccupant(std::shared_ptr<CellOccupant> occupant)
{
    this->occupant = occupant;
}

CellLocation Cell::getLocation()
{
    return location;
}

std::shared_ptr<CellOccupant> Cell::getOccupant()
{
    return occupant;
}

std::vector<CellLocation> Cell::getNeighbors()
{
    return location.getNeighborLocations();
}

bool Cell::isOccupiable()
{
    return type == Surface || type == Start || type == End;
}
