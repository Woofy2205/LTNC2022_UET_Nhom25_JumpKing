#include"dungeon.h"
#include<bits/stdc++.h>

using namespace std;


#include"block.h"
#include"config.h"
#include"core.h"
#include"header.h"
#include"image.h"
#include"loadingMenu.h"
#include"mainMenu.h"
#include"dungeon.h"
#include"material.h"
#include"menu.h"
#include"menuManagement.h"
#include"menuOption.h"
#include"object.h"
#include"optionMenu.h"
#include"pauseMenu.h"
#include"TextControl.h"

using namespace std;

//Constructors.
dungeon::dungeon(void) {

}

dungeon::dungeon(SDL_Renderer*renderer) {
	_character = new Character(renderer, 84, 368);
	this->currentLayerID = 0;
	this->dungeonH = 0;
	this->dungeonW = 0;
	this->layerType = 0;

	this->drawLines = false;
	this->xPos = 0;
	this->yPos = 0;

	this->inEvent = false;
	this->spawnPointID = 0;
	this->moveDungeon = true;

	this->frameID = 0;
	this->tp = false;

	config::getText()->setFont(renderer, "font");
	events = new Event();

	srand((unsigned)time(NULL));

	loadGame(renderer);
	loadLayer();

}


//Destructor.
dungeon::~dungeon(void) {
	for (vector<Block*>::iterator i = blocks.begin(); i != blocks.end(); i++) {
		delete(*i);
	}
	for (vector<Block*>::iterator i = objects.begin(); i != objects.end(); i++) {
		delete(*i);
	}

	delete events;
	//delete flags;
}

void dungeon::updateDungeon() {
	updateBlocks();
	updateObjBlocks();
	updateObj();
	if (!inEvent) {
		updateCharacter();
		frameID++;
		if (frameID > 32) {
			frameID = 0;
			if (dungeonTime > 0) {
				dungeonTime--;
				if (dungeonTime <= 0) {
					cDeath(true, true);
				}
			}
		}
	}
	else {
		events->Animate();
	}
	for (int i = 0; i < frames.size(); i++) {
		frames[i]->Update();
	}
	/*
	for (int i = 0; i < points.size(); i++) {
		if (!points[i]->getDelete()) {
			points[i]->Update();
		}
		else {
			delete points[i];
			points.erase(points.begin() + i);
		}
	}
	*/
}

void dungeon::updateCharacter() {
	_character->Update();
	checkSpawnPoint();
}

void dungeon::updateObj() {
	for (int i = 0; i < szObjs; i++) {
		for (int j = 0, sz = (int)objs[i].size(); j < sz; j++) {
			if (objs[i][j]->updateObj()) {
				objs[i][j]->Update();
			}
		}
	}

	for (int i = 0; i < szObjs; i++) {
		for (int j = 0, sz = (int)objs[i].size(); j < sz; j++) {
			if (objs[i][j]->objSpawned) {
				if (objs[i][j]->objState == -1) {
					delete objs[i][j];
					objs[i].erase(objs[i].begin() + j);
					sz = (int)objs[i].size();
					continue;
				}

				if (floor(objs[i][j]->xPos / 160) != i){
					objs[(int)floor((int)objs[i][j]->xPos / 160)].push_back(objs[i][j]);
					objs[i].erase(objs[i].begin() + j);
					sz = (int)objs[i].size();
				}	
			}
		}
	}
}

void dungeon::updateObjCollision()
{
}

void dungeon::updateBlocks()
{
}

void dungeon::updateObjBlocks()
{
}

void dungeon::loadLayer()
{
}

void dungeon::Draw(SDL_Renderer* renderer) {
	DrawDungeon(renderer);

	for (int i = 0; i < frames.size(); i++) {
		frames[i]->Draw(renderer);
	}
	
	
}

void dungeon::DrawDungeon(SDL_Renderer* renderer) {
	//99 is the ID number of end point destination.
	if (flag != NULL) {
		flag->DrawEndPointFlag(renderer, blocks[99]->getMaterial()->getImg());
	}

	for (int i = getStartBlock(), j = getEndBlock(); i < j && i < dungeonW; i++) {
		for (int j = dungeonH - 1; j >= 0; j--) {
			if (dungeons[i][j]->getBlockID() != 0) {
				blocks[dungeons[i][j]->getBlockID()]->Draw(renderer, 32 * i + (int)xPos, config::gameHeight - 32 * j - 16 - dungeons[i][j]->updatePos());
			}
		}
	}

	if (flag != NULL) {
		flag->Draw(renderer, blocks[flag->blockID]->getMaterial()->getImg());
	}
}

void dungeon::DrawObj(SDL_Renderer* renderer) {
	for (int i = 0; i < szObjs; i++) {
		for (int j = 0, k = (int)objs[i].size(); j < k; j++) {
			objs[i][j]->Draw(renderer, objects[objs[i][j]->getBlockID()]->getMaterial()->getImg());
		}
	}
}

void dungeon::DrawLayout(SDL_Renderer* renderer) {
	config::getText()->Draw(renderer, "JumpKing", 54, 16);
	if (_character->getScore() < 100) {
		config::getText()->Draw(renderer, "00000" + to_string(_character->getScore()), 54, 32);
	}
	else if (_character->getScore() < 1000) {
		config::getText()->Draw(renderer, "000" + to_string(_character->getScore()), 54, 32);
	}
	else if (_character->getScore() < 10000) {
		config::getText()->Draw(renderer, "00" + to_string(_character->getScore()), 54, 32);
	}
	else if (_character->getScore() < 100000) {
		config::getText()->Draw(renderer, "0" + to_string(_character->getScore()), 54, 32);
	}
	else {
		config::getText()->Draw(renderer, to_string(_character->getScore()), 54, 32);
	}

	config::getText()->Draw(renderer, "Dungeon", 462, 16);
	//config::getText()->Draw(renderer, getDungeonName(), 480, 32);

	if (layerType != 1) {
		blocks[2]->Draw(renderer, 268, 32);
	}
	else {
		blocks[57]->Draw(renderer, 268, 32);
	}
	config::getText()->Draw(renderer, "y", 286, 32);

	config::getText()->Draw(renderer, "TIME", 672, 16);
	if (config::getMenuManagement()->getID() == config::getMenuManagement()->gaming_state) {
		if (dungeonTime > 100) {
			config::getText()->Draw(renderer, to_string(dungeonTime), 680, 32);
		}
		else if (dungeonTime > 10) {
			config::getText()->Draw(renderer, "0" + to_string(dungeonTime), 680, 32);
		}
		else {
			config::getText()->Draw(renderer, "00" + to_string(dungeonTime), 680, 32);
		}
	}
}


void dungeon::cDeath(bool ani, bool death){
}

Vector* dungeon::getBlockID(int x, int y) {
	return new Vector((int)(x < 0 ? 0 : x) / 32, (int)(y > config::gameHeight - 16 ? 0 : (config::gameHeight - 16 - y + 32) / 32));
}

void dungeon::setInEvent(bool inEvent) {
	this->inEvent = inEvent;
}

bool dungeon::getInEvent() {
	return inEvent;
}

int dungeon::getLayerType() {
	return 0;
}

float dungeon::getXPos() {
	return 0.0f;
}

int dungeon::getStartBlock() {
	return 0;
}

int dungeon::getEndBlock() {
	return 0;
}

void dungeon::loadGame(SDL_Renderer* renderer)
{
}

void dungeon::checkSpawnPoint()
{
}
