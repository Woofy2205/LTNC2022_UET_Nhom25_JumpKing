#include"frame.h"
#include"config.h"
#include"core.h"
#include<iostream>

using namespace std;

//Constructor.
Frame::Frame(int size, int type, int xStart, int yStart, int xEnd, int yEnd,
				float xPos, float yPos, bool dir) {
	this->size = size;
	this->type = type;
	this->xStart = xStart;
	this->xEnd = xEnd;
	this->yStart = yStart;
	this->yEnd = yEnd;
	this->xPos = xPos;
	this->yPos = yPos;
	this->dir = dir;
	
	this->active = false;

}

//Destructor
Frame::~Frame(void) {

}


void Frame::Update() {
	switch (type) {
	case 0: //Bottom
		if (yPos > yEnd) {
			yPos = (float)yStart;
		}
		else {
			yPos += 2;
		}
		break;
	case 1: //Top
		if (yPos < yStart) {
			yPos = (float)yEnd;
		}
		else {
			yPos -= 2;
		}
		break;
	case 2: //Bottom+Top
		if (dir) {
			if (yPos < yStart) {
				dir = false;
			}
			else if (yPos < yStart + 32) {
				yPos -= 1;
			}
			else {
				yPos -= 2;
			}
		}
		else {
			if (yPos > yEnd) {
				dir = true;
			}
			else if (yPos > yEnd - 32) {
				yPos += 1;
			}
			else {
				yPos += 2;
			}
		}
		break;
	case 3: //Right+Left
		if (dir) {
			if (xPos > xEnd) {
				dir = false;
			}
			else if (xPos < xStart + 16 || xPos + 16 > xEnd) {
				xPos += 0.5f;
			}
			else {
				xPos += 1;
			}
		}
		else {
			if (xPos < xStart) {
				dir = true;
			}
			else if (xPos - 16 < xStart || xPos + 16 > xEnd) {
				xPos -= 0.5f;
			}
			else {
				xPos -= 1;
			}
		}
		break;
	case 4: //Bonus
		if (xPos > xEnd) {
			size = 0;
		}
		else if (active) {
			xPos += 3;
		}
		break;
	}
}

void Frame::Draw(SDL_Renderer* renderer) {
	/*
	for (int i = 0; i < iSize; i++) {
		CCore::getDungeon()->getBlock(iType != 4 ? 74 : 126)->Draw(rR, (int)fXPos + i * 16 + (int)CCore::getDungeon()->getXPos(), (int)fYPos);
	}
	*/
	// this should be done after "map.h" and "map.cpp"
}

//Getters and Setters.
float Frame::getMoveX() {
	switch (type) {
		case 3:
			if (dir) {
				if (xPos < xStart + 16 || xPos + 16 > xEnd) {
					return 0.5f;
				}
				else {
					return 1;
				}
			}
			else {
				if (xPos - 16 < xStart || xPos + 16 > xEnd) {
					return -0.5f;
				}
				else {
					return -1;
				}
			}
			break;
		case 4:
			return 3;
	}

	return 0;
}

int Frame::getMoveY() {
	switch (type) {
		case 0:
			return 2;
		case 1:
			return -2;
		case 2:
			if (dir) {
				if (yPos < yStart + 32) {
					return -1;
				}
				else {
					return -2;
				}
			}
			else {
				if (yPos > yEnd - 32) {
					return 1;
				}
				else {
					return 2;
				}
			}
		case 5:
			return 2;
	}

	return 0;
}

void Frame::moveY() {
	switch (type) {
	case 5:
		yPos += 2;
		break;
	}
}


int Frame::getSize() {
	return size;
}

void Frame::setType(int type) {
	this->type = type;
}

int Frame::getType() {
	return type;
}

void Frame::activate() {
	this->active = true;
}