/*
 * TileOption.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "TileOption.h"

TileOption::TileOption(Cell::CellType type, int x, int y, int w, int h) :
        Clickable(x, y, w, h)
{
    this->myType = type;
}

TileOption::~TileOption()
{
}

Cell::CellType TileOption::getCellType()
{
    return myType;
}

void TileOption::handleEvents(SDL_Event& event, Cell::CellType * option)
{
    if (event.type == SDL_MOUSEBUTTONDOWN && !click)
    {
        int clickX = event.button.x;
        int clickY = event.button.y;

        // Check if it falls inside the boundaries of this Clickable object
        if (clickX >= x && clickY >= y && clickX <= (x + width) && clickY <= (y + height))
        {
            std::cout << "Tile option " << myType << " clicked." << std::endl;
            *option = myType;
            click = true;
            notify();
        }
    }
    else if (click && event.type == SDL_MOUSEBUTTONUP)
    {
        click = false;
    }
}

void TileOption::draw()
{
    std::string textureName;
    std::string label;

    if (myType == Cell::CellType::Wall)
    {
        textureName = "bricks";
        label = "Wall tile";
    }
    else if (myType == Cell::CellType::Surface)
    {
        textureName = "floor";
        label = "Floor tile";
    }
    else if (myType == Cell::CellType::Start)
    {
        textureName = "start";
        label = "Start";
    }
    else if (myType == Cell::CellType::End)
    {
        textureName = "stop";
        label = "End";
    }
    else
    {
        textureName = "empty";
        label = "Empty tile";
    }

    texture->drawTexture(textureName, x, y, 50, 50);
    text->renderText(x + 75, y + 13, label, "calibri", text->white, 25);
}
