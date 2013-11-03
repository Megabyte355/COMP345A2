/*
 * TileOption.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#ifndef TILEOPTION_H_
#define TILEOPTION_H_

#include "Clickable.h"
#include "Cell.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include <string>
#include <SDL.h>

class TileOption: public Clickable
{
    public:
        TileOption(Cell::CellType, SDL_Renderer *, TextureRenderer *, TextRenderer *, int, int, int, int);
        ~TileOption() override;
        void handleEvents(SDL_Event &) override;
        void draw() override;
        bool isClicked();

    private:
        Cell::CellType type;
        bool click;
};

#endif /* TILEOPTION_H_ */
