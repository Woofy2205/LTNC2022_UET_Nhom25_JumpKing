#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "Game.h"
#include "texture.h"

Game* game = nullptr;

int main(int argc, char* args[]){
    /// <summary>
    /// Game FPS.
    /// Higher FPS is, faster the Animations are.
    /// </summary>
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("JumpKing_Group25", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    /// <summary>
    /// Main Game Loop Controller.
    /// </summary>
    while (game->running() == true)
    {
        if (game->winning() == false && game->retrying() == true)
        {
            //start frame time that SDL initialized
            frameStart = SDL_GetTicks();

            game->handleEvents();
            game->update();
            game->render();

            frameTime = SDL_GetTicks() - frameStart;
            
            if (frameDelay > frameTime)
            {
                SDL_Delay(frameDelay - frameTime);
            }
        }
        else
        {
            game->retry();
        }
    }
    game->clean();


    return 0;
}
