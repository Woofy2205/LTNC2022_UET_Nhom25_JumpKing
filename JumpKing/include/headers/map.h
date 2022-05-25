#pragma once
#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Header.h"
#include "Game.h"
#include "GameObject.h"

class Map
{
private:
    SDL_Rect src, dest;

    SDL_Texture* dirt = NULL;
    SDL_Texture* grass = NULL;
    SDL_Texture* red_grass = NULL;
    SDL_Texture* stone = NULL;
    
    /// hashed map to load the texture bu going through the 2D array
    int mapping[240][60];
    SDL_Rect tile[240][60];

public:
    // constructor and destructor
    Map();
    ~Map();
    // function to load, draw and close the map
    void LoadMap(int arr[240][60]);
    void DrawMap(SDL_Rect Camera);
    void DrawBabe(SDL_Rect Camera);
    void CloseMap();

    // collision checking function
    bool checkCollision(SDL_Rect a, SDL_Rect b);

    // friend function
    friend void GameObject::Update(SDL_Rect Tile[][60], int Mapping[][60]);
    friend bool Collide(SDL_Rect Tile[], int Mapping[][60]);
    friend void Game::update();

};
#endif 
