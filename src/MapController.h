/*
 * MapController.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef MAPCONTROLLER_H_
#define MAPCONTROLLER_H_

#include "Map.h"
#include "MapView.h"

class MapController
{
    public:
        MapController();
        ~MapController();
    private:
        Map map;
        MapView view;
};

#endif /* MAPCONTROLLER_H_ */
