/*
 * Button.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "Clickable.h"
#include "Cell.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include <string>
#include <SDL.h>

class Button: public Clickable
{
    public:
        Button(int,int,int,int);
        ~Button() override;

        void handleEvents(SDL_Event &, Cell::CellType *) override;
        void draw() override;
};

#endif /* BUTTON_H_ */
