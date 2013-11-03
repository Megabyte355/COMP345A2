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
        static const int SCREEN_WIDTH = 800;
        static const int SCREEN_HEIGHT = 600;
        std::string WINDOW_NAME;

        int screenWidth;
        int screenHeight;

        SDL_Renderer * renderer;
        SDL_Window * window;
        //TextureRenderer textures;
        //TextRenderer texts;
};

#endif /* MAPVIEW_H_ */
