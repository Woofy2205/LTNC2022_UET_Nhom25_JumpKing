#pragma once

#ifndef BLOCK_H
#define BLOCK_H

#include<bits/stdc++.h>			//I don't wanna use this...
#include"material.h"
#include"image.h"

class Block {
private:
	Material* materials;
	int blockID;
	bool blockCollision;
	bool blockDeath;
	bool blockUse;
	bool blockVisible;
	string blockType;
public:
	/*
	* Constructors.
	*/
	Block(void);
	Block(int blockID, Material* materials, bool blockCollision, bool blockDeath, bool blockUse, bool blockVisible);
	/*
	* Destructors.
	*/
	~Block(void);

	//Functions.
	void Draw(SDL_Renderer* renderer, int x, int y);

	/*
	* Getters and Setters.
	*/
	int getBlockID();
	bool getCollision();
	bool getDeath();
	bool getUse();
	bool getVisible();
	Material* getMaterial();
	void setBlockID(int ID);
	//inherit void functions for subclasses.
};

#endif
