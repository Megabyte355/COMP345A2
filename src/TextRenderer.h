/*
 * TextRenderer.h
 *
 *  Created on: Nov 2, 2013
 *      Author: Gary
 */

#ifndef TEXTRENDERER_H_
#define TEXTRENDERER_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <map>
#include <iostream>
#include <string>

class TextRenderer
{
    public:
        TextRenderer();
        ~TextRenderer();

        void setRenderer(SDL_Renderer *renderer);
        void loadFontPaths();
        void renderText(int x, int y, std::string message, std::string fontName, SDL_Color color, int fontSize);

        // Preset colors
        SDL_Color black;
        SDL_Color white;
        SDL_Color red;
        SDL_Color green;
        SDL_Color blue;

    private:
        static const int DEFAULT_FONT_SIZE = 20;
        SDL_Renderer* renderer;
        std::map<std::string, std::string> fontMap;

        TTF_Font* loadPath(const std::string &file);
};

#endif /* TEXTRENDERER_H_ */
