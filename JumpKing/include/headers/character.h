#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

#include"material.h"
#include"vector.h"
#include<bits/stdc++.h>

class Character {
private:
	vector<Material*> Materials;
	int materialID;
	int aniTime;

	float xPos, yPos;
	int sage;						//no. Lives, jk =))))

	bool godMode;
	int godTime;
	int godID;

	int score;
	int frameID;
	int nextFallFrameID;

	/*
	* Edit this after measure JK.bmp file.
	* Resolution: 3x4
	*/
	const static int jk_X = 30, jk_Y = 40;
	const static int jk_x = 24, jk_y = 32;

	int smollJK;
	
	//Jump - The only available way of moving in game, literally.
	int jumpState;
	bool moveDir;				//T = left, F = right;
	bool bMove;
	float currentJumpSped;
	float startJumpSped;
	bool changeMoveDirection;
	bool newMoveDirection;
	float jumpDist;
	float currentJumpDist;
	float currentFallSped;
	static const int maxMove = 4;
	int currentMaxMove;
	int onBlockID;

	int jumpSpeed;
	int moveSpeed;
	int timePassed;

	//Methods.
	void moveCharacter();

	bool checkCollisionBot(int nX, int nY);
	bool checkCollisionCenter(int nX, int nY);


	//Getters.
	Vector* getBlockLB(float nX, float nY);
	Vector* getBlockRB(float nX, float nY);

	Vector* getBlockLC(float nX, float nY);
	Vector* getBlockRC(float nX, float nY);

	Vector* getBlockLT(float nX, float nY);
	Vector* getBlockRT(float nX, float nY);

public:
	//Constructor.
	Character(SDL_Renderer* rR, float fXPos, float fYPos);
	//Destructor.
	~Character(void);

	//Functions.
	void Draw(SDL_Renderer* renderer);
	void Update();

	void physics();

	void updateXPos(int n);
	void updateYPos(int n);

	

	void moveAni();

	void startMove();
	void resetMove();
	void stopMove();
	bool getChangeDir();
	void setChangeDir();


	void jump();
	void startJump(int height);
	void resetJump();

	void setMaterials(int iID);
	int getMaterials();
	int getHitBoxX();
	int getHitBoxY();

	//Getters and Setters.

	int getXPos();
	void setXPos(float fXPos);
	int getYPos();
	void setYPos(float fYPos);
	void setCharSprite(int ID);
	int getCharSprite();

	bool getGod();
	int getSage();
	void setSage(int sage);
	bool getDir();
	void setDir(bool moveDir);
	void setNextFallFrameID(int nextFallFrameID);
	void setCurrentJumpSped(float currentJumpSped);
	int getJumpState();
	bool getMove();
	bool getMoveDir();
	int getMoveSped();
	void setMoveSped(int moveSpeed);
	Material* getCharImg();

	unsigned int getScore();
	void setScore(unsigned int iScore);

	int getSize();
	void setSize(int smollJK);
	void resetSize();
};

#endif