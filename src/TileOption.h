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

class TileOption: public virtual Clickable
{
    public:
        TileOption(Cell::CellType, int, int, int, int);
        ~TileOption() override;

        Cell::CellType getCellType();
        void handleEvents(SDL_Event &, Cell::CellType *) override;
        void draw() override;

    private:
        Cell::CellType myType;
};

#endif /* TILEOPTION_H_ */
