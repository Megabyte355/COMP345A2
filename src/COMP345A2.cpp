//============================================================================
// Name        : COMP345A2.cpp
// Author      : Gary Chang
// Version     : 1.0
// Description : Program Driver for Assignment 2
//============================================================================

#include <iostream>
#include <memory>
#include "Map.h"
#include "MapView.h"

int main(int argc, char** argv)
{
    // Initialization
    Map mapModel(20,20);
    MapView * mapView = new MapView();
    mapModel.attach(mapView);

    // Execution
    if (mapView->initialize(&mapModel))
    {
        mapView->run();
    }

    // Clean up
    mapModel.detach(mapView);
    delete mapView;
    return 0;
}
