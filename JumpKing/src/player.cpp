#include "player.h"
#include "image.h"

King::King(int x, int y) {
    xpos = x;
    ypos = y;

    xvel = 0;
    yvel = 0;

    srcRect.h = KING_HEIGHT;
    srcRect.w = KING_WIDTH;
    srcRect.x = 4;
    srcRect.y = 9;

    destRect.h = srcRect.h;
    destRect.w = srcRect.w;
    destRect.x = xpos;
    destRect.y = ypos;
}

King::~King(){}

void King::handleEvents(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_RIGHT: xvel += xspeed; break;
        case SDLK_LEFT: xvel -= xspeed; break;
        case SDLK_UP: yvel -= yspeed; break;
        case SDLK_DOWN: yvel += yspeed; break;
        }
    }
    else if (event.type == SDL_KEYUP && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_RIGHT: xvel -= xspeed; break;
        case SDLK_LEFT: xvel += xspeed; break;
        case SDLK_UP: yvel += yspeed; break;
        case SDLK_DOWN: yvel -= yspeed; break;
        }
    }
}

void King::move() {
    xpos += xvel;
    if ((xpos < 0) || (xpos + KING_WIDTH > 480))
    {
        xpos -= xvel;
    }
    destRect.x = xpos-20;
    ypos += yvel;

    if ((ypos < 0) || (ypos + KING_HEIGHT > 360))
    {
        ypos -= yvel;
    }
    destRect.y = ypos-20;
}

void King::Draw(SDL_Renderer* renderer, Image* img) {
    img->Draw(renderer, xpos, ypos);
}