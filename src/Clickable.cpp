/*
 * Clickable.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "Clickable.h"

Clickable::Clickable()
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    renderer = nullptr;
    texture=nullptr;
    text = nullptr;
}

Clickable::Clickable(SDL_Renderer* ren, TextureRenderer * tr, TextRenderer * t, int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    width = w;
    height = h;
    renderer = ren;
    texture = tr;
    text = t;
}

Clickable::~Clickable()
{
    // This class is not the main owner of the renderer. It won't be destroyed here.
    renderer = nullptr;
}
