#pragma once

#ifndef DUNGEON_H
#define DUNGEON_H
#include<bits/stdc++.h>
//then include all related header files' titles.
#include"block.h"
#include"image.h"
#include"header.h"
#include"layer.h"
#include"character.h"
#include"frame.h"
#include"object.h"
#include"vector.h"
#include"event.h"
#include"flag.h"
//#include"score.h"

using namespace std;


class dungeon {
private:
	double xPos, yPos;
	vector<Block*> blocks;
	int szBlock;
	vector<Block*> objects;
	int szObject;
	vector<vector<layer*>> dungeons;
	int dungeonW, dungeonH;
	vector<Frame*> frames;
	
	int currentLayerID;
	int layerType;
	
	int spawnPointID;

	bool moveDungeon;

	int frameID;
	int dungeonTime;

	Event* events;
	bool inEvent;

	bool tp;

	/// <summary>
	/// Character.
	/// </summary>
	Character* _character;

	/// <summary>
	/// Objects.
	/// </summary>
	vector<vector<Object*>> objs;
	int szObjs;
	int getListID(int xPos);
	int getNumOfObjects();
	
	/// <summary>
	/// Points.
	/// </summary>
	//vector<Points*> points;

	/// <summary>
	/// Methods.
	/// </summary>
	Flag* flag;
	bool drawLines;
	int getStartBlock();
	int getEndBlock();


	void loadGame(SDL_Renderer* renderer);

	void createDungeon();

	void checkSpawnPoint();
	int getNumOfSpawnPoints();
	int getSpawnPointXPos(int id);
	int getSpawnPointYPos(int id);
public: 
	//Constructor
	dungeon(void);
	dungeon(SDL_Renderer* renderer);
	~dungeon(void);
	//Function
	void updateDungeon();
	void updateCharacter();
	void updateObj();
	void updateObjCollision();
	void updateBlocks();
	void updateObjBlocks();
	void loadLayer();

	void Draw(SDL_Renderer* renderer);
	void DrawDungeon(SDL_Renderer* renderer);
	void DrawObj(SDL_Renderer* renderer);
	void DrawLayout(SDL_Renderer* renderer);
	void DrawLines(SDL_Renderer* renderer);

	void cDeath(bool ani, bool death);

	//Getters and Setters.
	Vector* getBlockID(int x, int y);
	void setInEvent(bool inEvent);
	bool getInEvent();

	void setLayerType(int levelType);
	int getLayerType();

	float getXPos();
	void setXPos(float xPos);
	float getYPos();
	void setYPos(float yPos);
};

#endif

