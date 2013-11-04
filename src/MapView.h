/*
 * MapView.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef MAPVIEW_H_
#define MAPVIEW_H_

#include "Observer.h"
#include "TileOption.h"
#include "Map.h"
#include "MapTile.h"
#include "TextRenderer.h"
#include "TextureRenderer.h"
#include "Button.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class MapView : public Observer
{
    public:
        MapView();
        MapView(int, int);
        ~MapView() override;

        void update() override;
        bool initialize(Map * model);
        void run();

    private:
        // Constant configurations
        static const int SCREEN_WIDTH = 800;
        static const int SCREEN_HEIGHT = 600;
        std::string WINDOW_NAME;

        int screenWidth;
        int screenHeight;
        bool isRunning;

        SDL_Renderer * renderer;
        SDL_Window * window;
        TextureRenderer texture;
        TextRenderer text;
        Map * mapModel;
        Cell::CellType selectedOption;
        std::vector<Clickable*> * clickables;

        void handleEvents(SDL_Event&);
        void loadViewComponents();
        void drawAll();
        std::string selectedOptionStr();
};

#endif /* MAPVIEW_H_ */
