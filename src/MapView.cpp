/*
 * MapView.cpp
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#include "MapView.h"

MapView::MapView()
{
    x = 1;
    
}

MapView::~MapView()
{
    x = 0;
}

void MapView::update()
{
    std::cout << "MapView update() function" << std::endl;
}
