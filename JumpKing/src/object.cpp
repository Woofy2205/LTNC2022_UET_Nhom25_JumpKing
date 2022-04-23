#include"object.h"

int Object::getBlockID() {
	return blockID;
}

void Object::setBlockID(int iBlockID) {
	this->blockID = iBlockID;
}

int Object::getXPos() {
	return (int)xPos;
}

int Object::getYPos() {
	return (int)yPos;
}

void Object::setYPos(int iYPos) {
	this->yPos = (float)iYPos;
}

int Object::getMinionState() {
	return objState;
}