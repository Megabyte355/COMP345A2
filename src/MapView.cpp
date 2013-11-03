/*
 * MapView.cpp
 *
 *  Created on: Oct 27, 2013
 *      Author: Gary
 */

#include "MapView.h"

MapView::MapView()
{
    screenWidth = SCREEN_WIDTH;
    screenHeight = SCREEN_HEIGHT;
    renderer = nullptr;
    window = nullptr;
}

MapView::MapView(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    renderer = nullptr;
    window = nullptr;
}

MapView::~MapView()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    renderer = nullptr;
    window = nullptr;
}

bool MapView::initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init error." << std::endl;
        return false;
    }
    if (TTF_Init() == -1)
    {
        std::cout << TTF_GetError() << std::endl;
        return false;
    }
    window = SDL_CreateWindow(WINDOW_NAME.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "SDL_CreateWindow error." << std::endl;
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer error." << std::endl;
        return false;
    }
    textures.setRenderer(renderer);
    textures.loadAllTextures();
    texts.setRenderer(renderer);
    texts.loadFontPaths();

    std::cout << "MapView initialization complete!" << std::endl;
    return true;
}

void MapView::update()
{
    std::cout << "MapView update() function called!" << std::endl;
}
