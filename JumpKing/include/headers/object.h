/*
this object class gonna be some potion that can buff our character
*/
#pragma once

#ifndef OBJECT_H
#define OBJECT_H
/*
headers and stuffs
*/
//#include <iostream>
//#include <string>     // NOT PREFER USING THIS LIBRARY BECAUSE ITS GONNA MAKE THE GAME SLOWER
//#include <SDL.h>
//#include <SDL_image.h>
#include "image.h"
#include "player.h"

class Object{
public:
	//Constructor.
	Object(int objW, int objH);
	//Destructor.
	~Object(void);

	//Variables.
	int objState;						//state of the object 
	bool isTouched=false;						//lethal or not
	int blockID;						//ID of the object
	float xPos, yPos, objW, objH;					//Position by x and y
	bool objSpawned;					//spawned or not
	bool collisionWithCharacter;		//idk...
	int existTime;						//time that the object exists
	SDL_Rect objRect;
	//Properties.
	int moveSpeed;
	int jumpState;
	float jumpDistance;								//something the obj buff our character
	float jumpSpeed;
	float jumpHeight;
	float fallSpeed;

	//Virtual Functions that will be different with different object.
	virtual void Update();
	virtual void Draw(SDL_Renderer* renderer, Image* img);
	virtual void updateYPos(int varY);
	virtual void updateXPos(int varX);
	virtual void updateObj();
	virtual void objPhysics();

	/*virtual void collisionEffect();
	virtual void objExterminate();
	void state1();
	void state2();

	void Spawn();*/

	virtual bool collideWithCharacter(SDL_Rect A, SDL_Rect B);
	/*virtual void points(int pts);
	virtual void lockObj();*/


	//Getters and Setters.
	int getBlockID();
	void setBlockID(int blockID);
	int getMinionState();
	/*virtual void setObjState(int objState);
	virtual bool buff();*/

	int getXPos();
	int getYPos();
	void setYPos(int _yPos);
};

#endif
