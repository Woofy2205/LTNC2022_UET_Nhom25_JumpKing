#pragma once

#ifndef EVENT_H
#define EVENT_H

#include"header.h"
#include"bits/stdc++.h"

using namespace std;

class Event {
private:
	/// <summary>
	/// true = old
	/// false = new
	/// </summary>
	bool state;

	int stepID;

public:
	//Constructor.
	Event(void);
	//Destructor.
	~Event(void);

	enum aniType {
		//Directions.
		eTop,
		eBottom,
		eRight,
		eLeft,
		//Frame-ends.
		eRightEnd,
		eLeftEnd,
		eEndBot1,
		eEndBot2,
		eEndPoint,
		//Dead states.
		eDeath,
		eDeathTop,
		eDeathBot,
		//Game ends.
		eGameOver,
		//Normal state.
		eNormalState,
		//Loading state.
		eLoading,
		//End-game state.
		eEndGame,
		//Sprite.
		eCharSprite,
	};

	vector<aniType> oldDirections;
	vector<aniType> newDirections;
	vector<int> oldLength;
	vector<int> newLength;
	vector<int> reDrawX;
	vector<int> reDrawY;

	enum eventType {
		eNormal,
		eEnd,
	};

	eventType eID;

	void Normal();
	void End();

	int speed;

	void resetData();

	int newLayerType;
	int newDungeonPos;
	
	int newCharXPos;
	int newCharYPos;

	bool newMoveDungeon;
	int delay;
	int time;

	int newCurrentLayer;
	bool inEvent;

	bool endGame;
	
	//Methods.
	void Draw(SDL_Renderer* renderer);
	void Animate();

	void newDungeon();
	void resetReDraw();
};

#endif