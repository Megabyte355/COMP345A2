/*
 * MapView.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef MAPVIEW_H_
#define MAPVIEW_H_

#include "IObserver.h"
#include <iostream>

class MapView : public IObserver
{
    public:
        MapView();
        ~MapView() override;

        void update() override;
    private:
        int x;
};

#endif /* MAPVIEW_H_ */
