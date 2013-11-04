/*
 * Button.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "Button.h"

Button::Button(int x, int y, int w, int h) :
        Clickable(x, y, w, h)
{
}

Button::~Button()
{
}

void Button::handleEvents(SDL_Event &event, Cell::CellType* option)
{
    if (event.type == SDL_MOUSEBUTTONDOWN && !click)
    {
        int clickX = event.button.x;
        int clickY = event.button.y;

        // Check if it falls inside the boundaries of this Clickable object
        if (clickX >= x && clickY >= y && clickX <= (x + width) && clickY <= (y + height))
        {
            click = true;
            notify();
        }
    }
    else if (click && event.type == SDL_MOUSEBUTTONUP)
    {
        click = false;
    }
}

void Button::draw()
{
    texture->drawTexture("empty", x, y, 300, 50);

    // Draws string with a shadow
    text->renderText(x + 17, y + 17, "Click here to validate map", "calibri_bold", text->black, 25);
    text->renderText(x + 15, y + 15, "Click here to validate map", "calibri_bold", text->white, 25);
}
