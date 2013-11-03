/*
 * MapView.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#ifndef MAPVIEW_H_
#define MAPVIEW_H_

#include "Observer.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include "TextRenderer.h"
#include "TextureRenderer.h"

class MapView : public Observer
{
    public:
        MapView();
        MapView(int, int);
        ~MapView() override;

        void update() override;
        bool initialize();

    private:
        // Constant configurations
        const int SCREEN_WIDTH = 800;
        const int SCREEN_HEIGHT = 600;
        const std::string WINDOW_NAME = "Assignment 2 - Observer Pattern on Map";

        int screenWidth;
        int screenHeight;

        SDL_Renderer * renderer;
        SDL_Window * window;
        TextureRenderer textures;
        TextRenderer texts;
};

#endif /* MAPVIEW_H_ */
