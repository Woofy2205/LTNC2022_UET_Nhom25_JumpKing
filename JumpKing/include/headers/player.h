#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "image.h"

class King
{
public:
	King(){}
	King(int x, int y);
	~King();
	void handleEvents(SDL_Event& event);
	void move();
	void Draw(SDL_Renderer* renderer, Image* img);
	int Getxspeed() { return xspeed; }
	int Getxvel() { return xvel; }
	int Getyvel() { return yvel; }
	int getXpos() { return xpos; }
	int getYpos() { return ypos; }
	static const int xspeed = 5;
	static const int yspeed = 5;
	static const int KING_WIDTH = 71;
	static const int KING_HEIGHT = 74;

	int xpos;
	int ypos;

	int xvel;
	int yvel;
	SDL_Rect srcRect, destRect;
};

#endif // !PLAYER_H
