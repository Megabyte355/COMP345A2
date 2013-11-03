/*
 * CellLocation.cpp
 *
 *  Created on: Nov 2, 2013
 *      Author: Gary
 */

#include "CellLocation.h"

CellLocation::CellLocation()
{
    x = 0;
    y = 0;
}

CellLocation::CellLocation(int x, int y)
{
    this->x = x;
    this->y = y;
}

CellLocation::~CellLocation()
{
}

bool CellLocation::operator==(const CellLocation &other)
{
    return this->x == other.x && this->y == other.y;
}

bool CellLocation::isNeighbor(const CellLocation &other)
{
    if ( x == other.x )
    {
        return (y == other.y - 1) || (y == other.y + 1);
    }
    else if (y == other.y)
    {
        return (x == other.x - 1) || (x == other.x + 1);
    }
    else
    {
        return false;
    }
}

std::vector<CellLocation> CellLocation::getNeighborLocations()
{
//    CellLocation up(x, y - 1);
//    CellLocation down(x, y + 1);
//    CellLocation left(x - 1, y);
//    CellLocation right(x + 1, y);

    std::vector<CellLocation> v;
    v.push_back(CellLocation(x, y - 1));
    v.push_back(CellLocation(x, y + 1));
    v.push_back(CellLocation(x - 1, y));
    v.push_back(CellLocation(x + 1, y));

    return v;
//    return {up, down, left, right};
}
