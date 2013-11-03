/*
 * Clickable.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#ifndef CLICKABLE_H_
#define CLICKABLE_H_

#include <SDL.h>
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "Observable.h"

class Clickable : public Observable
{
    public:
        Clickable(SDL_Renderer *, TextureRenderer *, TextRenderer *, int, int, int, int);
        virtual ~Clickable();

        virtual void handleEvents(SDL_Event &) = 0;
        virtual void draw() = 0;

    protected:
        Clickable();

        // Location on screen
        int x;
        int y;

        // Space occupied on screen
        int width;
        int height;

        // Renderer used to draw graphics
        SDL_Renderer * renderer;
        TextureRenderer * texture;
        TextRenderer * text;
};

#endif /* CLICKABLE_H_ */
