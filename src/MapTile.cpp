/*
 * MapTile.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "MapTile.h"

MapTile::MapTile(Map* mapModel, int i, int j, int x, int y, int w, int h) :
        Clickable(x, y, w, h)
{
    this->mapModel = mapModel;
    this->i = i;
    this->j = j;
    cell = mapModel->getCell(i, j);
    renderer = nullptr;
    texture = nullptr;
    text = nullptr;
}

MapTile::~MapTile()
{
    cell.reset();
    renderer = nullptr;
    texture = nullptr;
    text = nullptr;
    mapModel = nullptr;
    i = 0;
    j = 0;
}

void MapTile::handleEvents(SDL_Event &event, Cell::CellType * option)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        int clickX = event.button.x;
        int clickY = event.button.y;

        // Check if it falls inside the boundaries of this Clickable object
        if (clickX >= x && clickY >= y && clickX <= (x + width) && clickY <= (y + height))
        {
            mapModel->setCell(*option, i, j);
            // test
            //cell->setType(*option);
            click = true;
            notify();
        }
    }
    else if (event.type == SDL_MOUSEBUTTONUP)
    {
        click = false;
    }
}

void MapTile::draw()
{
    if (cell->getType() == Cell::CellType::Wall)
    {
        texture->drawTexture("bricks", x, y, width, height);
    }
    else if (cell->getType() == Cell::CellType::Surface)
    {
        texture->drawTexture("floor", x, y, width, height);
    }
    else if (cell->getType() == Cell::CellType::Start)
    {
        texture->drawTexture("floor", x, y, width, height);
        texture->drawTexture("start", x, y, width, height);
    }
    else if (cell->getType() == Cell::CellType::End)
    {
        texture->drawTexture("floor", x, y, width, height);
        texture->drawTexture("stop", x, y, width, height);
    }
    else if (cell->getType() == Cell::CellType::Empty)
    {
        texture->drawTexture("empty", x, y, width, height);
    }
}
