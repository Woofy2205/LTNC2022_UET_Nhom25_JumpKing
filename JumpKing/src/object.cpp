#include"object.h"
//#include "image.h"
Object::Object(int objW, int objH) {
	this->xPos = 400;
	this->yPos = 150;
	this->objH = objH;
	this->objW = objW;
    objRect.x = this->xPos;
    objRect.y = this->yPos;
    objRect.w = objW;
    objRect.h = objH;
}

Object::~Object(void){
    
}

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

void Object::Draw(SDL_Renderer* renderer, Image* img) {
    if(!isTouched) img->Draw(renderer, xPos, yPos);
}

bool Object::collideWithCharacter(SDL_Rect A, SDL_Rect B) {
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //If any of the sides from A are outside of B
    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

void Object::updateObj(){
}

void Object::Update(){}

void Object::updateXPos(int varX){}

void Object::updateYPos(int varY){}

void Object::objPhysics(){}

