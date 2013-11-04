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
    WINDOW_NAME = "Assignment 2 - Observer Pattern on Map";
    isRunning = false;
    renderer = nullptr;
    window = nullptr;
    mapModel = nullptr;
    selectedOption = Cell::CellType::Empty;
    clickables = new std::vector<Clickable*>();
}

MapView::MapView(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    isRunning = false;
    renderer = nullptr;
    window = nullptr;
    mapModel = nullptr;
    selectedOption = Cell::CellType::Empty;
    clickables = new std::vector<Clickable*>();
}

MapView::~MapView()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    clickables->clear();
    delete clickables;
    
    // Map is destroyed outside of this class
    mapModel = nullptr;
    renderer = nullptr;
    window = nullptr;
    clickables = nullptr;
}

bool MapView::initialize(Map * model)
{
    mapModel = model;
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
    window = SDL_CreateWindow(WINDOW_NAME.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth,
            screenHeight, SDL_WINDOW_SHOWN);
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
    texture.setRenderer(renderer);
    texture.loadAllTextures();
    text.setRenderer(renderer);
    text.loadFontPaths();

    loadViewComponents();

    std::cout << "MapView initialization complete!" << std::endl;
    return true;
}

void MapView::loadViewComponents()
{
    // ================================================== Tile options ==================================================
    int offset = 75;
    int n = 0;

    TileOption * wallOption = new TileOption(Cell::CellType::Wall, screenWidth - 200, 100 + offset * n++, 200, 50);
    TileOption * floorOption = new TileOption(Cell::CellType::Surface, screenWidth - 200, 100 + offset * n++, 200, 50);
    TileOption * startOption = new TileOption(Cell::CellType::Start, screenWidth - 200, 100 + offset * n++, 200, 50);
    TileOption * endOption = new TileOption(Cell::CellType::End, screenWidth - 200, 100 + offset * n++, 200, 50);
    TileOption * emptyOption = new TileOption(Cell::CellType::Empty, screenWidth - 200, 100 + offset * n++, 200, 50);

    wallOption->setRenderers(renderer, &texture, &text);
    floorOption->setRenderers(renderer, &texture, &text);
    startOption->setRenderers(renderer, &texture, &text);
    endOption->setRenderers(renderer, &texture, &text);
    emptyOption->setRenderers(renderer, &texture, &text);

    clickables->push_back(wallOption);
    clickables->push_back(floorOption);
    clickables->push_back(startOption);
    clickables->push_back(endOption);
    clickables->push_back(emptyOption);

    // Attach to observable
    wallOption->attach(std::make_shared<MapView>(*this));
    floorOption->attach(std::make_shared<MapView>(*this));
    startOption->attach(std::make_shared<MapView>(*this));
    endOption->attach(std::make_shared<MapView>(*this));
    emptyOption->attach(std::make_shared<MapView>(*this));

    wallOption = nullptr;
    floorOption = nullptr;
    startOption = nullptr;
    endOption = nullptr;
    emptyOption = nullptr;

    // ==================================================== Map tiles ====================================================
    int mapColumns = mapModel->getWidth();
    int mapRows = mapModel->getHeight();

    int tileTextureWidth = 400 / mapColumns;
    int tileTextureHeight = 400 / mapRows;

    int currentX = 25;
    int currentY = 125;

    MapTile * mt = nullptr;
    for (int i = 0; i < mapColumns; i++)
    {
        for (int j = 0; j < mapRows; j++)
        {
            mt = new MapTile(mapModel, i, j, currentX, currentY, tileTextureWidth, tileTextureHeight);
            mt->setRenderers(renderer, &texture, &text);
            clickables->push_back(mt);
            mt->attach(std::make_shared<MapView>(*this));
            mt = nullptr;
            currentY += tileTextureHeight;
        }
        currentX += tileTextureWidth;
        currentY = 125;
    }

    // ==================================================== Buttons ====================================================
    Button * validateButton = new Button(screenWidth - 300, screenHeight - 50, 300, 50);
    validateButton->setRenderers(renderer, &texture, &text);
    clickables->push_back(validateButton);
    validateButton->attach(std::make_shared<MapView>(*this));
    validateButton = nullptr;

}

void MapView::update()
{
    std::cout << "update() function is called via Observer Pattern!!!" << std::endl;

    SDL_RenderClear(renderer);

    // Draw the background
    texture.drawTexture("background", 0, 0, screenWidth, screenHeight);

    // Draw headers
    text.renderText(10, 10, "Map Preview", "starcraft_font", text.white, 35);
    text.renderText(10, 60, "COMP345 - Assignment 2: Observer Pattern", "arial_bold", text.white, 15);
    text.renderText(10, 80, "Gary Chang (9368841)", "arial_bold", text.white, 15);

    // Draw tile options and map tiles
    text.renderText(screenWidth - 300, 25, "Tile selection (click)", "calibri_bold", text.white, 35);
    for (Clickable * c : *clickables)
    {
        // Update selectedOption variable to selected cell type
//        TileOption * to = dynamic_cast<TileOption*>(c);
//        if (to != nullptr && to->isClicked())
//        {
//            selectedOption = to->getCellType();
//        }
//        to = nullptr;
        Button * b = dynamic_cast<Button*>(c);
        if (b != nullptr && b->isClicked())
        {
            bool validMap = mapModel->validateMap();
            if (validMap)
            {
                text.renderText(25, screenHeight - 50, "Map is VALID", "calibri_bold", text.green, 40);
            }
            else
            {
                text.renderText(25, screenHeight - 50, "Map is INVALID", "calibri_bold", text.red, 40);
            }
        }

        c->draw();
    }

    SDL_RenderPresent(renderer);
}

void MapView::run()
{
// Render graphics once
    update();

    isRunning = true;
    SDL_Event event;
    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            handleEvents(event);
        }
    }
}

void MapView::handleEvents(SDL_Event &event)
{
    switch (event.type)
    {
        case SDL_QUIT:
            // Closing the window terminates the program
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            // Pressing escape key terminates the program
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
            break;
        case SDL_KEYUP:
            break;
        case SDL_MOUSEBUTTONDOWN:
            for (auto c : *clickables)
            {
                c->handleEvents(event, &selectedOption);
            }
            break;
        case SDL_MOUSEBUTTONUP:
            for (auto c : *clickables)
            {
                c->handleEvents(event, &selectedOption);
            }
            break;
        default:
            break;
    }
}

std::string MapView::selectedOptionStr()
{
    std::string s = "";
    if (selectedOption == Cell::CellType::Wall)
    {
        s = "wall";
    }
    else if (selectedOption == Cell::CellType::Surface)
    {
        s = "floor";
    }
    else if (selectedOption == Cell::CellType::Start)
    {
        s = "start";
    }
    else if (selectedOption == Cell::CellType::End)
    {
        s = "end";
    }
    else if (selectedOption == Cell::CellType::Empty)
    {
        s = "empty";
    }
    else
    {
        s = "???";
    }
    return s;
}
