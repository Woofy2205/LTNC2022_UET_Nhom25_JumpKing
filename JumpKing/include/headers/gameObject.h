#pragma once
#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include "Game.h"
#include <math.h>
#include "header.h"
#include "timer.h"

#define gravity 0.8
#define MAX_FALL_SPEED 20

using namespace std;

/// condition of the player
enum condition { standing, running, charging, jumping };

/// check input key
typedef struct {
    int left;
    int right;
    int up;
    int jump;
}
Input;





class GameObject
{
private:
    // position by x and y
    double xpos;
    double ypos;

    // velocity by x and y
    double xvel;
    double yvel;

    int frame;

    Uint32 startTime;
    int jumpTime;

    // texture and things to render on
    SDL_Texture* objTextureRight = NULL;
    SDL_Texture* objTextureLeft = NULL;
    SDL_Rect srcRect, destRect, collider;

    // sound for the game
    Mix_Chunk* High = NULL;
    Mix_Chunk* potion_music = NULL;

    // for running animation
    SDL_Rect RunningRight[5];
    SDL_Rect RunningLeft[5];

    // input and on ground
    condition status;
    Input inputType;
    bool onGround;
    bool isWin;

    //buff collide time
    Timer buffTime;
public:
    // constructor and destructor
    GameObject(int x, int y);
    ~GameObject();

    friend void Game::handleEvents();
    friend void Game::update();
    friend void Game::retry();

    // get the collider
    SDL_Rect GetCollider() { return collider; }

    // update function
    void Update(SDL_Rect Tile[][60], int Mapping[][60]);

    // run function and buff
    void RunLeft();
    void RunLeftBuff();
    void RunRight();
    void RunRightBuff();

    // jump function and buff
    void PrepareJump();
    void Jump();
    void JumpBuff();
    void JumpLeft();
    void JumpLeftBuff();
    void JumpRight();
    void JumpRightBuff();

    // stop action function
    void StopRunRight();
    void StopRunLeft();
    void StopRunUp();
    void StopRunDown();

    // reset function
    void Reset();

    // set clips and render, close function
    void SetClips();
    void Render();
    void ObjectClose();

    // collide function and check collisions
    void CollideVertical(SDL_Rect& col, SDL_Rect Tile[][60], int Mapping[][60]);
    void CollideHorizontal(SDL_Rect& col, SDL_Rect Tile[][60], int Mapping[][60]);
    bool checkCollision2(SDL_Rect a, SDL_Rect b);

    // get speed and velocity
    int Getxspeed() { return xspeed; }
    int Getxvel() { return (int)xvel; }
    int Getyvel() { return (int)yvel; }

    // speed stat
    static const int xspeed = 1;
    static const int yspeed = 1;

    // limit speed stat
    static const int maxxspeed = 6;
    static const int maxyspeed = 8;

    // character stat
    static const int KING_WIDTH = 48;
    static const int KING_HEIGHT = 48;

    // camera that follows the character position
    SDL_Rect Camera = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };

    // boolean variables that can create some events for the game
    bool isSpdBuff, isSpdBuff_forDraw, isJmpBuff, isJmpBuff_forDraw, isLag, isLag_forDraw, godPot_draw;
};
#endif
