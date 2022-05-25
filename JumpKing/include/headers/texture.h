#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include "Header.h"
#include "Game.h"

// used to handle the texture that create the game
class texture
{
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};


#endif

