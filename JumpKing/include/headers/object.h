/*
this object class gonna be some potion that can buff our character
*/

#pragma once

#ifndef OBJECT_H
#define OBJECT_H
/*
headers and stuffs
*/
#include"header.h"
#include"config.h"
#include"image.h"

class Object {
public:
	//Constructor.
	Object(void);
	//Destructor.
	~Object(void);

	//Variables.
	int objState;						//state of the object 
	bool lethality;						//lethal or not
	int blockID;						//ID of the object
	float xPos, yPos;					//Position by x and y
	int hitBoxX, hitBoxY;
	bool objSpawned;					//spawned or not
	bool collisionWithCharacter;		//collide with Character.
	int existTime;						//time that the object exists

	//Properties.
	bool moveDir;						//true = left | false = right.
	int moveSpeed;
	int jumpState;
	float jumpDistance;					//something the obj buff our character
	float currentJumpSpeed;
	float sJumpSpeed;
	float jumpSpeed;
	float currentJumpDistance;
	float fallSpeed;

	//Virtual Functions that will be different with different object.
	virtual void Update();
	virtual void Draw(SDL_Renderer* renderer, Image* img);
	virtual void updateYPos(int var);
	virtual void updateXPos();
	virtual bool updateObj();
	virtual void objPhysics();

	virtual void collisionEffect();
	virtual void objExterminate();
	void pState1();
	void pState2();

	void Spawn();

	virtual void collideWithCharacter(bool flag);
	virtual void points(int pts);
	virtual void lockObj();


	//Getters and Setters.
	int getBlockID();
	void setBlockID(int blockID);
	int getObjState();
	virtual void setObjState(int objState);
	virtual bool buff();

	int getXPos();
	int getYPos();
	void setYPos(int _yPos);
};

#endif