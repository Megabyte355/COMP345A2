/*
 * MapTile.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#ifndef MAPTILE_H_
#define MAPTILE_H_

#include "Cell.h"
#include "Clickable.h"
#include "Map.h"

class MapTile: public Clickable
{
    public:
        MapTile(Map *, int, int, int, int, int, int);
        ~MapTile() override;
        void handleEvents(SDL_Event &, Cell::CellType *) override;
        void draw() override;

    private:
        std::shared_ptr<Cell> cell;
        Map * mapModel;
        int i;
        int j;
};

#endif /* MAPTILE_H_ */
