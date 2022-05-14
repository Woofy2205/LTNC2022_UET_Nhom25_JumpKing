#pragma once

#ifndef FLAG_H
#define FLAG_H

#include "header.h"
#include "image.h"

class Flag {
private:

public:
	Flag(int xPos, int yPos);
	~Flag(void);

	int xPos, yPos;
	int blockID;

	int yTextPos;
	int points;

	int endFlagExtraXPos;
	int endFlagY;

	void Update();
	void UpdateEndPointFlag();
	void Draw(SDL_Renderer* renderer, Image* img);
	void DrawEndPointFlag(SDL_Renderer* renderer, Image* img);
};

#endif