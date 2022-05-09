#pragma once

#ifndef FRAME_H
#define FRAME_H

#include"header.h"

class Frame{
private:
	/*
	* Note that: 
	* 0 = bottom
	* 1 = top
	* 2 = bottom + top
	* 3 = right + left
	* 4 = bonus
	* 5 = falling
	*/
	int type;
	int xStart, xEnd, yStart, yEnd;

	float xPos, yPos;

	/*
	* true  = Right
	*	    = Top
	* false = Left
	*		= Bottom
	*/
	bool dir;

	int size;
	bool active;
public:
	//Constructor.
	Frame(int size, int type, int xStart, int yStart, int xEnd, int yEnd,
			float xPos, float yPos, bool dir);
	//Destructor.
	~Frame(void);

	void Update();
	void Draw(SDL_Renderer* renderer);

	void moveY();

	void activate();

	//Getters and Setters.
	int getXpos();
	int getYpos();
	int getSize();

	float getMoveX();
	int getMoveY();

	int getType();
	void setType(int type);


};

#endif