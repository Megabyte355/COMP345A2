/*
 * Map.cpp
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#include "Map.h"

Map::Map()
{
    initialize(10, 10);
}

Map::Map(int width, int height)
{
    initialize(width, height);
}

Map::~Map()
{
}

void Map::initialize(int width, int height)
{
    mapWidth = width;
    mapHeight = height;
    matrix.resize(mapWidth);
    for (int i = 0; i < mapWidth; i++)
    {
        matrix[i].resize(mapHeight);
        for (int j = 0; j < mapHeight; j++)
        {
            matrix[i][j] = std::make_shared<Cell>(i, j);
        }
    }
}

int Map::getWidth()
{
    return mapWidth;
}

int Map::getHeight()
{
    return mapHeight;
}

std::shared_ptr<Cell> Map::getCell(int x, int y)
{
    if (isValidCell(x, y))
    {
        return matrix[x][y];
    }
    return nullptr;
}

std::shared_ptr<Cell> Map::getStartCell()
{
    for (int i = 0; i < mapWidth; i++)
    {
        for (int j = 0; j < mapHeight; j++)
        {
            if (matrix[i][j]->getType() == Cell::CellType::Start)
            {
                return matrix[i][j];
            }
        }
    }
    return nullptr;
}

std::shared_ptr<Cell> Map::getEndCell()
{
    for (int i = 0; i < mapWidth; i++)
    {
        for (int j = 0; j < mapHeight; j++)
        {
            if (matrix[i][j]->getType() == Cell::CellType::End)
            {
                return matrix[i][j];
            }
        }
    }
    return nullptr;
}

void Map::setCell(Cell::CellType cellType, int x, int y)
{
    if (isValidCell(x, y))
    {
        matrix[x][y].reset();
        matrix[x][y] = std::make_shared<Cell>(cellType, x, y);
        matrix[x][y]->setX(x);
        matrix[x][y]->setY(y);
    }

    notify();
}

void Map::setStartCell(int x, int y)
{
    if (isValidCell(x, y))
    {
        if (getStartCell() != nullptr)
        {
            getStartCell()->setType(Cell::CellType::Surface);
        }
        matrix[x][y].reset();
        matrix[x][y] = std::make_shared<Cell>(Cell::CellType::Start, x, y);
        matrix[x][y]->setX(x);
        matrix[x][y]->setY(y);

        notify();
    }
}

void Map::setEndCell(int x, int y)
{
    if (isValidCell(x, y))
    {
        if (getEndCell() != nullptr)
        {
            getEndCell()->setType(Cell::CellType::Surface);
        }
        matrix[x][y].reset();
        matrix[x][y] = std::make_shared<Cell>(Cell::CellType::End, x, y);
        matrix[x][y]->setX(x);
        matrix[x][y]->setY(y);

        notify();
    }
}

bool Map::validateMap()
{
    /*
     * A map is considered valid if it satisfies 3 conditions:
     *     1- A start point exist.
     *     2- An end point exist.
     *     3- There is a walkable path linking the start and end points.
     */
    std::shared_ptr<Cell> start = getStartCell();
    std::shared_ptr<Cell> end = getEndCell();

    bool hasStart = start != nullptr;
    bool hasEnd = end != nullptr;
    bool hasValidPath = false;

    if (hasStart && hasEnd)
    {
        shortestPath = PathFinder::getShortestPath(*this, *start, *end);
        hasValidPath = !(shortestPath.empty());
    }
    return hasStart && hasEnd && hasValidPath;
}

bool Map::isValidPath(Cell origin, Cell dest)
{
    return !PathFinder::getShortestPath(*this, origin, dest).empty();
}

std::vector<CellLocation> Map::getShortestPath(Cell &origin, Cell &dest)
{
    return PathFinder::getShortestPath(*this, origin, dest);
}

bool Map::isValidCell(Cell c)
{
    return isValidCell(c.getX(), c.getY());
}

bool Map::isValidCell(int x, int y)
{
    return x >= 0 && x < mapWidth && y >= 0 && y < mapHeight;
}

bool Map::isValidCell(CellLocation loc)
{
    return isValidCell(loc.x, loc.y);
}

bool Map::isOccupiable(CellLocation loc)
{
    std::shared_ptr<Cell> temp = getCell(loc.x, loc.y);
    return temp != nullptr && temp->isOccupiable();
}

void Map::attach(std::shared_ptr<Observer> obs)
{
    observers.push_back(obs);
}

void Map::detach(std::shared_ptr<Observer> obs)
{
    for (std::vector<std::shared_ptr<Observer>>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        if ((*it)->getSubscriberID() == obs->getSubscriberID())
        {
            observers.erase(it);
            break;
        }
    }
}

void Map::notify()
{
    for (std::vector<std::shared_ptr<Observer>>::iterator it = observers.begin(); it != observers.end(); it++)
    {
        (*it)->update();
    }
}
