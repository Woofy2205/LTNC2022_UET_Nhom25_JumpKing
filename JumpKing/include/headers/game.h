#pragma once
#ifndef GAME_H
#define GAME_H

#include "Header.h"
#include <iostream>
#include "textObj.h"
#include <fstream>

/// <summary>
/// game stat, including screen, tile and level
/// </summary>
static const int SCREEN_WIDTH = 960;
static const int SCREEN_HEIGHT = 720;

static const int TILE_WIDTH = 16;
static const int TILE_HEIGHT = 16;
static const int TILE_NUMBERS = 3;

static const int LEVEL_WIDTH = 960;
static const int LEVEL_HEIGHT = 3840;


class Game
{
private:
    /// private variables that check the status of the game
    bool isRunning;
    bool win;
    bool isRetrying;
    SDL_Window* window = NULL;

public:
    /// constructor and destructor
    Game();
    ~Game();

    int createMenu(TTF_Font* font);
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void retry();
    void clean();

    bool checkSelected(const int& x, const int& y, const SDL_Rect& rect);
    bool running(); 
    bool winning(); 
    bool retrying(); 
    
    /// renderer that draw the game
    static SDL_Renderer* renderer;

};
#endif
