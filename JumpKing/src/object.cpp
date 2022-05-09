#include"object.h"
#include"core.h"

Object::Object(void) {
	//initializing default variables.
	this->objState = 0;
	this->hitBoxX = 32;
	this->hitBoxX = 32;
	this->lethality = false;
	this->objSpawned = false;
	this->collisionWithCharacter = false;

	this->moveDir = true;
	this->moveSpeed = 0;
	this->jumpState = 0;

	/*
	* These won't be used much since most objects in this game are immobile.
	*/
	this->sJumpSpeed = 6.64f;
	this->fallSpeed = 2.2f;
	this->jumpSpeed = 0;
	this->jumpDistance = 0;
	this->currentJumpDistance = 0;
	this->fallSpeed = 0;

	this->existTime = -1;
}

Object::~Object(void) {

}

void Object::Update() {

}

void Object::Draw(SDL_Renderer* renderer, Image* img) {
	
}

bool Object::updateObj() {
	if (!objSpawned) {
		Spawn();
	}
	else {
		objPhysics();
	}
	return objSpawned;
}

void Object::objPhysics() {
	if (jumpState == 1) {
		pState1();
	}
	else {
		//if (!mainCore::getDungeon()->checkCollisionLB((int)xPos + 2, (int)yPos + 2, hitBoxY, true) && !mainCore::getDungeon()->checkCollisionRB((int)xPos - 2, (int)yPos + 2, hitBoxX, hitBoxY, true)) {
		//	pState2();
		//}
		//else {
			jumpState = 0;
		//}
	}
}

void Object::pState1() {
	updateYPos(-(int)currentJumpSpeed);
	currentJumpDistance += (int)currentJumpSpeed;

	currentJumpSpeed *= (currentJumpDistance / jumpDistance > 0.75f ? 0.972f : 0.986f);

	if (currentJumpSpeed < 2.5f) {
		currentJumpSpeed = 2.5f;
	}

	if (jumpDistance <= currentJumpDistance) {
		jumpState = 2;
	}
}

void Object::pState2() {
	fallSpeed *= 1.06f;

	if (fallSpeed > sJumpSpeed) {
		fallSpeed = sJumpSpeed;
	}

	updateYPos((int)fallSpeed);

	jumpState = 2;

	if (yPos >= config::gameHeight) {
		objState = -1;
	}
}

void Object::updateXPos() {
	/*
	// ----- LEFT
	if (moveDir) {
		if (mainCore::getDungeon()->checkCollisionLB((int)xPos - moveSpeed, (int)yPos - 2, hitBoxY, true) || mainCore::getDungeon()->checkCollisionLT((int)xPos - moveSpeed, (int)yPos + 2, true)) {
			moveDir = !moveDir;
			if (lethality && xPos > -mainCore::getDungeon()->getXPos() - 64 && xPos < -mainCore::getDungeon()->getXPos() + config::gameWidth + 64 + hitBoxX) config::getMusic()->PlayChunk(config::getMusic()->cBLOCKHIT);
		}
		else {
			xPos -= (jumpState == 0 ? moveSpeed : moveSpeed / 2.0f);
		}
	}
	// ----- RIGHT
	else {
		if (mainCore::getDungeon()->checkCollisionRB((int)xPos + moveSpeed, (int)yPos - 2, hitBoxX, hitBoxY, true) || mainCore::getDungeon()->checkCollisionRT((int)xPos + moveSpeed, (int)yPos + 2, hitBoxX, true)) {
			moveDir = !moveDir;
			if (lethality && xPos > -mainCore::getDungeon()->getXPos() - 64 && xPos < -mainCore::getDungeon()->getXPos() + config::gameWidth + 64 + hitBoxX) config::getMusic()->PlayChunk(config::getMusic()->cBLOCKHIT);
		}
		else {
			xPos += (jumpState == 0 ? moveSpeed : moveSpeed / 2.0f);
		}
	}

	if (xPos < -hitBoxX) {
		objState = -1;
	}
	*/
}

void Object::updateYPos(int n) {
	/*
	if (n > 0) {
		if (!mainCore::getDungeon()->checkCollisionLB((int)xPos + 2, (int)yPos + n, hitBoxY, true) && !mainCore::getDungeon()->checkCollisionRB((int)xPos - 2, (int)yPos + n, hitBoxX, hitBoxY, true)) {
			yPos += n;
		}
		else {
			if (jumpState == 1) {
				jumpState = 2;
			}
			updateYPos(n - 1);
		}
	}
	else if (n < 0) {
		if (!mainCore::getDungeon()->checkCollisionLT((int)xPos + 2, (int)yPos + n, true) && !mainCore::getDungeon()->checkCollisionRT((int)xPos - 2, (int)yPos + n, hitBoxX, true)) {
			yPos += n;
		}
		else {
			if (jumpState == 1) {
				jumpState = 2;
			}
			updateYPos(n + 1);
		}
	}

	if ((int)yPos % 2 == 1) {
		yPos += 1;
	}
	*/
}

void Object::collisionEffect() {
	if (objSpawned) {
		moveDir = !moveDir;
	}
}

void Object::objExterminate(){
	xPos += (moveDir ? -1.5f : 1.5f);
	yPos += 2 * (existTime > 8 ? -1 : existTime > 2 ? 1 : 4.25f);

	if (existTime > 0) {
		--existTime;
	}

	if (yPos > config::gameHeight) {
		objState = -1;
	}
}

void Object::collideWithCharacter(bool flag) {

}

void Object::lockObj() {

}

void Object::Spawn() {

}

void Object::points(int pts) {

}

void Object::setObjState(int objState) {

}

bool Object::buff() {
	return 1;
}
/// <summary>
/// Continue from here.
/// TsunN 10:14 April 30th 2022.
/// </summary>
/// <returns>
/// Pushed on Github.
/// </returns>



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

int Object::getObjState() {
	return objState;
}