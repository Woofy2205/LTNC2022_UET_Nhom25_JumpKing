#include<bits/stdc++.h>
#include"time.h"
#include"core.h"
#include"character.h"


//Constructor.
Character::Character(SDL_Renderer* renderer, float xPos, float yPos) {
	//Initializing variables.
	this->xPos = xPos;
	this->yPos = yPos;
	this->sage = 3;
	this->materialID = 1;
	this->score = 0;
	this->frameID = 1;
	this->nextFallFrameID = 0;

	this->godMode = false;
	this->godID = 0;

	this->moveDir = true;
	this->jumpSpeed = 0;
	this->changeMoveDirection = false;

	this->onBlockID = -1;
	this->timePassed = SDL_GetTicks();
	this->jumpState = 0;
	this->currentFallSped = 2.7f;
	this->aniTime = 0;

	//Load Sprite.
	vector<string> str;
	vector<int> v;

	srand((unsigned)time(NULL));		//no idea what this is...

	/*
	* Normie JK.
	*/
	str.push_back("JK/JK_death");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JK");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JK_jump");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JK_end1");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JK_end2");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	/*
	* Buff: Smoll JK.
	*/
	str.push_back("JK/JK1");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JK1_jump");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JK1_end1");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JK1_end2");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	/*
	* Buff: QuickSilver_JK.
	*/
	str.push_back("JK/JK2");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JK2_jump");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JK2_end1");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JK2_end2");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	/*
	* Debuff: GigaChad_JK.
	*/
	str.push_back("JK/JKchad");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JKchad_jump");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JKchad_end1");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JKchad_end2");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	/*
	* Debuff: Drunk_JK.
	*/
	str.push_back("JK/JKdrunk");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JKdrunk_jump");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JKdrunk_end1");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();

	str.push_back("JK/JKdrunk_end2");
	v.push_back(0);
	Materials.push_back(new Material(renderer, str, v, true));
	str.clear();
}


//Destructor.
Character::~Character(void) {
	for (vector<Material*>::iterator i = Materials.begin(); i != Materials.end(); i++) {
		delete(*i);
	}
}

//Functions.
void Character::Update() {
	physics();
	moveCharacter();

	if (frameID > 0) {
		frameID--;
	}
}

void Character::physics() {
	/*
	if (jumpState == 1) {
		updateYPos(-(int)currentJumpSped);
		currentJumpDist += (int)currentJumpSped;

		currentJumpSped *= (currentJumpDist / jumpDist > 0.75f ? 0.972f : 0.986f);

		if (currentJumpSped < 2.5f) {
			currentJumpSped = 2.5f;
		}

		if (!(config::pressSpace) && currentJumpDist > 64) {
			jumpDist = 16;
			currentJumpDist = 0;
			currentJumpSped = 2.5f;
		}

		if (jumpDist <= currentJumpDist) {
			jumpState = 2;
		}
	}
	else {
		if (onBlockID == -1) {
			onBlockID = mainCore::getDungeon()->checkCollisionWithPlatform((int)xPos, (int)yPos, getHitBoxX(), getHitBoxY());
			if (onBlockID >= 0) {
				if (mainCore::getDungeon()->checkCollisionLB((int)(xPos - mainCore::getDungeon()->getXPos() + 2), (int)yPos + 2, getHitBoxY(), true) || mainCore::getDungeon()->checkCollisionRB((int)(xPos - mainCore::getDungeon()->getXPos() - 2), (int)yPos + 2, getHitBoxX(), getHitBoxY(), true)) {
					onBlockID = -1;
					resetJump();
				}
				else {
					yPos = (float)mainCore::getDungeon()->getPlatform(onBlockID)->getYPos() - getHitBoxY();
					resetJump();
					mainCore::getDungeon()->getPlatform(onBlockID)->turnON();
				}
			}
		}
		else {
			onBlockID = mainCore::getDungeon()->checkCollisionWithPlatform((int)xPos, (int)yPos, getHitBoxX(), getHitBoxY());
		}

		if (onBlockID >= 0) {
			if (mainCore::getDungeon()->checkCollisionLB((int)(xPos - mainCore::getDungeon()->getXPos() + 2), (int)yPos + 2, getHitBoxY(), true) || mainCore::getDungeon()->checkCollisionRB((int)(xPos - mainCore::getDungeon()->getXPos() - 2), (int)yPos + 2, getHitBoxX(), getHitBoxY(), true)) {
				onBlockID = -1;
				resetJump();
			}
			else {
				yPos += mainCore::getDungeon()->getPlatform(onBlockID)->getMoveY();
				mainCore::getDungeon()->getPlatform(onBlockID)->moveY();
				//if(moveSpeed == 0)
				mainCore::getDungeon()->setXPos(mainCore::getDungeon()->getXPos() - mainCore::getDungeon()->getPlatform(onBlockID)->getMoveX());

				jumpState = 0;
			}
		}
		else if (!mainCore::getDungeon()->checkCollisionLB((int)(xPos - mainCore::getDungeon()->getXPos() + 2), (int)yPos + 2, getHitBoxY(), true) &&
			!mainCore::getDungeon()->checkCollisionRB((int)(xPos - mainCore::getDungeon()->getXPos() - 2), (int)yPos + 2, getHitBoxX(), getHitBoxY(), true)) {

			if (nextFallFrameID > 0) {
				--nextFallFrameID;
			}
			else {
				currentFallSped *= 1.05f;

				if (currentFallSped > startJumpSped) {
					currentFallSped = startJumpSped;
				}

				updateYPos((int)currentFallSped);
			}


			jumpState = 2;

			setCharSprite(5);
		}
		else if (jumpState == 2) {
			resetJump();
		}
		else {
			checkCollisionBot(0, 0);
		}
	}
	*/
}

void Character::moveCharacter() {
	if (bMove = true && !changeMoveDirection) {
		if (moveSpeed > currentMaxMove) {
			--moveSpeed;
		}
		else if ((signed)SDL_GetTicks() - (100 + 35 * moveSpeed) >= timePassed && moveSpeed < currentMaxMove) {
			++moveSpeed;
			timePassed = SDL_GetTicks();
		}
		else if (moveSpeed == 0) {
			moveSpeed = 1;
		}
	}
	else {
		if ((signed)SDL_GetTicks() - (50 + 15 * (currentMaxMove - moveSpeed)) > timePassed && moveSpeed != 0) {
			--moveSpeed;
			timePassed = SDL_GetTicks();
		}

		if (changeMoveDirection && moveSpeed <= 1) {
			moveDir = newMoveDirection;
			changeMoveDirection = false;
			bMove = true;
		}
	}

	if (moveSpeed > 0) {
		if (moveDir) {
			updateXPos(moveSpeed);
		}
		else {
			updateXPos(-moveSpeed);
		}

		if (!changeMoveDirection && jumpState == 0 && bMove) {
			moveAni();
		}
	}
	else if (jumpState == 0) {
		setCharSprite(1);
		updateXPos(0);
	}
	else {
		updateXPos(0);
	}
}


void Character::moveAni() {
	if ((signed)SDL_GetTicks() - 65 + moveSpeed * 4 > aniTime) {
		aniTime = SDL_GetTicks();
		if (materialID >= 15) {
			setCharSprite(2);
		}
		else {
			++materialID;
		}
	}
}

void Character::startMove() {
	aniTime = SDL_GetTicks();
	timePassed = SDL_GetTicks();
	moveSpeed = 1;
	bMove = true;
}

void Character::resetMove() {
	--moveSpeed;
	bMove = false;
}

void Character::stopMove() {
	moveSpeed = 0;
	bMove = false;
	changeMoveDirection = false;
	setCharSprite(1);
}


void Character::startJump(int height) {
	currentJumpSped = startJumpSped;
	jumpDist = 32 * height + 24.0f;
	currentJumpDist = 0;

	setCharSprite(5);
	jumpState = 1;
}

void Character::resetJump() {
	jumpState = 0;
	jumpDist = 0;
	currentJumpDist = 0;
	currentFallSped = 2.7f;
	nextFallFrameID = 0;
}

void Character::updateXPos(int n) {
	/*
	checkCollisionBot(n, 0);
	checkCollisionCenter(n, 0);
	if (n > 0) {
		if (!mainCore::getDungeon()->checkCollisionRB((int)(xPos - mainCore::getDungeon()->getXPos() + n), (int)yPos - 2, getHitBoxX(), getHitBoxY(), true) && !mainCore::getDungeon()->checkCollisionRT((int)(xPos - mainCore::getDungeon()->getXPos() + n), (int)yPos + 2, getHitBoxX(), true)) {
			if (xPos >= 416 && mainCore::getDungeon()->getMoveMap()) {
				mainCore::getDungeon()->moveMap(-n, 0);
			}
			else {
				xPos += n;
			}
		}
		else {
			updateXPos(n - 1);
			if (moveSpeed > 1 && jumpState == 0) --moveSpeed;
		}
	}
	else if (n < 0) {
		if (!mainCore::getDungeon()->checkCollisionLB((int)(xPos - mainCore::getDungeon()->getXPos() + n), (int)yPos - 2, getHitBoxY(), true) && !mainCore::getDungeon()->checkCollisionLT((int)(xPos - mainCore::getDungeon()->getXPos() + n), (int)yPos + 2, true)) {
			if (xPos <= 192 && mainCore::getDungeon()->getXPos() && mainCore::getDungeon()->getMoveMap() && config::canMoveBackward) {

				mainCore::getDungeon()->moveMap(-n, 0);
			}
			else if (xPos - mainCore::getDungeon()->getXPos() + n >= 0 && xPos >= 0) {
				xPos += n;
			}
			else if (config::canMoveBackward && xPos >= 0) {
				updateXPos(n + 1);
			}
		}
		else {
			updateXPos(n + 1);
			if (moveSpeed > 1 && jumpState == 0) --moveSpeed;
		}
	}
	*/
}

void Character::updateYPos(int n) {
	/*
	bool _left, _right;

	if (n > 0) {
		_left = mainCore::getDungeon()->checkCollisionLB((int)(xPos - mainCore::getDungeon()->getXPos() + 2), (int)yPos + n, getHitBoxY(), true);
		_right = mainCore::getDungeon()->checkCollisionRB((int)(xPos - mainCore::getDungeon()->getXPos() - 2), (int)yPos + n, getHitBoxX(), getHitBoxY(), true);

		if (!_left && !_right) {
			yPos += n;
		}
		else {
			if (jumpState == 2) {
				jumpState = 0;
			}
			updateYPos(n - 1);
		}
	}
	else if (n < 0) {
		_left = mainCore::getDungeon()->checkCollisionLT((int)(xPos - mainCore::getDungeon()->getXPos() + 2), (int)yPos + n, false);
		_right = mainCore::getDungeon()->checkCollisionRT((int)(xPos - mainCore::getDungeon()->getXPos() - 2), (int)yPos + n, getHitBoxX(), false);

		if (mainCore::getDungeon()->checkCollisionWithPlatform((int)xPos, (int)yPos, 0, 0) >= 0 || mainCore::getDungeon()->checkCollisionWithPlatform((int)xPos, (int)yPos, getHitBoxX(), 0) >= 0) {
			jumpState = 2;
		}
		else if (!_left && !_right) {
			yPos += n;
		}
		else {
			if (jumpState == 1) {
				if (!_left && _right) {
					Vector* vect = getBlockRT(xPos - mainCore::getDungeon()->getXPos(), yPos + n);

					if (!mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(vect->getX(), vect->getY())->getBlockID())->getVisible()) {
						if (mainCore::getDungeon()->blockUse(vect->getX(), vect->getY(), mainCore::getDungeon()->getDungeonBlock(vect->getX(), vect->getY())->getBlockID(), 0)) {
							jumpState = 2;
						}
						else {
							yPos += n;
						}
					}
					else if ((int)(xPos + getHitBoxX() - mainCore::getDungeon()->getXPos()) % 32 <= 8) {
						updateXPos((int)-((int)(xPos + getHitBoxX() - mainCore::getDungeon()->getXPos()) % 32));
					}
					else if (mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(vect->getX(), vect->getY())->getBlockID())->getUse()) {
						if (mainCore::getDungeon()->blockUse(vect->getX(), vect->getY(), mainCore::getDungeon()->getDungeonBlock(vect->getX(), vect->getY())->getBlockID(), 0)) {
							jumpState = 2;
						}
						else {
							yPos += n;
						}
					}
					else {
						jumpState = 2;
					}

					delete vect;
				}
				else if (_left && !_right) {
					Vector* vect2 = getBlockLT(xPos - mainCore::getDungeon()->getXPos(), yPos + n);
					if (!mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(vect2->getX(), vect2->getY())->getBlockID())->getVisible()) {
						if (mainCore::getDungeon()->blockUse(vect2->getX(), vect2->getY(), mainCore::getDungeon()->getDungeonBlock(vect2->getX(), vect2->getY())->getBlockID(), 0)) {
							jumpState = 2;
						}
						else {
							yPos += n;
						}
					}
					else if ((int)(xPos - mainCore::getDungeon()->getXPos()) % 32 >= 24) {
						updateXPos((int)(32 - (int)(xPos - mainCore::getDungeon()->getXPos()) % 32));
					}
					else if (mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(vect2->getX(), vect2->getY())->getBlockID())->getUse()) {
						if (mainCore::getDungeon()->blockUse(vect2->getX(), vect2->getY(), mainCore::getDungeon()->getDungeonBlock(vect2->getX(), vect2->getY())->getBlockID(), 0)) {
							jumpState = 2;
						}
						else {
							yPos += n;
						}
					}
					else {
						jumpState = 2;
					}

					delete vect2;
				}
				else {
					if ((int)(xPos + getHitBoxX() - mainCore::getDungeon()->getXPos()) % 32 > 32 - (int)(xPos - mainCore::getDungeon()->getXPos()) % 32) {
						Vector* vect3 = getBlockRT(xPos - mainCore::getDungeon()->getXPos(), yPos + n);

						if (mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(vect3->getX(), vect3->getY())->getBlockID())->getUse()) {
							if (mainCore::getDungeon()->blockUse(vect3->getX(), vect3->getY(), mainCore::getDungeon()->getDungeonBlock(vect3->getX(), vect3->getY())->getBlockID(), 0)) {
								jumpState = 2;
							}
						}
						else {
							jumpState = 2;
						}

						delete vect3;
					}
					else {
						Vector* vect2 = getBlockLT(xPos - mainCore::getDungeon()->getXPos(), yPos + n);

						if (mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(vect2->getX(), vect2->getY())->getBlockID())->getUse()) {
							if (mainCore::getDungeon()->blockUse(vect2->getX(), vect2->getY(), mainCore::getDungeon()->getDungeonBlock(vect2->getX(), vect2->getY())->getBlockID(), 0)) {
								jumpState = 2;
							}
						}
						else {
							jumpState = 2;
						}

						delete vect2;
					}
				}
			}

			updateYPos(n + 1);
		}
	}

	if ((int)yPos % 2 == 1) {
		yPos += 1;
	}

	if (!mainCore::getDungeon()->getInEvent() && yPos - getHitBoxY() > config::gameHeight) {
		mainCore::getDungeon()->CharacterDeath(false, true);
		yPos = -80;
	}
	*/
}

bool Character::checkCollisionBot(int x, int y) {
	/*
	Vector* v = getBlockLB(xPos - mainCore::getDungeon()->getXPos() + x, yPos + y);

	if (mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID())->getUse()) {
		mainCore::getDungeon()->blockUse(v->getX(), v->getY(), mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID(), 1);
	}

	delete v;

	v = getBlockRB(xPos - mainCore::getDungeon()->getXPos() + x, yPos + y);

	if (mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID())->getUse()) {
		mainCore::getDungeon()->blockUse(v->getX(), v->getY(), mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID(), 1);
	}

	delete v;
	*/
	return true;
}

bool Character::checkCollisionCenter(int x, int y) {
	/*
	if (smollJK == 0) {
		Vector* v = getBlockLC(xPos - mainCore::getDungeon()->getXPos() + x, yPos + y);

		if (mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID())->getUse()) {
			mainCore::getDungeon()->blockUse(v->getX(), v->getY(), mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID(), 2);
		}

		delete v;

		v = getBlockRC(xPos - mainCore::getDungeon()->getXPos() + x, yPos + y);

		if (mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID())->getUse()) {
			mainCore::getDungeon()->blockUse(v->getX(), v->getY(), mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID(), 2);
		}

		delete v;
	}
	else {
		Vector* v = getBlockLC(xPos - mainCore::getDungeon()->getXPos() + x, yPos + y + (smollJK > 0 ? 16 : 0));

		if (mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID())->getUse()) {
			mainCore::getDungeon()->blockUse(v->getX(), v->getY(), mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID(), 2);
		}

		delete v;

		v = getBlockRC(xPos - mainCore::getDungeon()->getXPos() + x, yPos + y + (smollJK > 0 ? 16 : 0));

		if (mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID())->getUse()) {
			mainCore::getDungeon()->blockUse(v->getX(), v->getY(), mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID(), 2);
		}

		delete v;

		v = getBlockLC(xPos - mainCore::getDungeon()->getXPos() + x, yPos + y - (smollJK > 0 ? 16 : 0));

		if (mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID())->getUse()) {
			mainCore::getDungeon()->blockUse(v->getX(), v->getY(), mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID(), 2);
		}

		delete v;

		v = getBlockRC(xPos - mainCore::getDungeon()->getXPos() + x, yPos + y - (smollJK > 0 ? 16 : 0));

		if (mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID())->getUse()) {
			mainCore::getDungeon()->blockUse(v->getX(), v->getY(), mainCore::getDungeon()->getDungeonBlock(v->getX(), v->getY())->getBlockID(), 2);
		}

		delete v;
	}
	*/
	return true;
	
}


Vector* Character::getBlockLB(float x, float y) {
	return mainCore::getDungeon()->getBlockID((int)x + 1, (int)y + getHitBoxY() + 2);
}

Vector* Character::getBlockRB(float x, float y) {
	return mainCore::getDungeon()->getBlockID((int)x + getHitBoxX() - 1, (int)y + getHitBoxY() + 2);
}

Vector* Character::getBlockLC(float x, float y) {
	return mainCore::getDungeon()->getBlockID((int)x - 1, (int)y + getHitBoxY() / 2);
}

Vector* Character::getBlockRC(float x, float y) {
	return mainCore::getDungeon()->getBlockID((int)x + getHitBoxX() + 1, (int)y + getHitBoxY() / 2);
}

Vector* Character::getBlockLT(float x, float y) {
	return mainCore::getDungeon()->getBlockID((int)x + 1, (int)y);
}

Vector* Character::getBlockRT(float x, float y) {
	return mainCore::getDungeon()->getBlockID((int)x + getHitBoxX() - 1, (int)y);
}

void Character::Draw(SDL_Renderer* renderer) {
	Materials[getCharSprite()]->getImg()->Draw(renderer, (int)xPos, (int)yPos + (mainCore::getDungeon()->getInEvent() ? 0 : 2), !moveDir);
}



//Getters and Setters.

int Character::getCharSprite() {
	return materialID;
}

void Character::setCharSprite(int id) {
	this->materialID = id;
}

int Character::getHitBoxX() {
	return smollJK == 0 ? jk_x : jk_X;
}

int Character::getHitBoxY() {
	return smollJK == 0 ? jk_y : jk_Y;
}

void Character::setDir(bool moveDir) {
	this->moveDir = moveDir;
}

bool Character::getChangeDir() {
	return changeMoveDirection;
}

void Character::setChangeDir() {
	this->changeMoveDirection = true;
	this->newMoveDirection = !moveDir;
}

int Character::getXPos() {
	return (int)xPos;
}

void Character::setXPos(float xPos) {
	this->xPos = xPos;
}

int Character::getYPos() {
	return (int)yPos;
}

void Character::setYPos(float yPos) {
	this->yPos = yPos;
}

int Character::getSize() {
	return smollJK;
}

void Character::setSize(int smollJK) {
	sage++;
	this->smollJK = smollJK;
}

void Character::resetSize() {
	this->smollJK = 0;
	this->materialID = 1;
}

int Character::getSage() {
	return sage;
}

bool Character::getGod() {
	return godMode;
}

void Character::setSage(int sage) {
	this->sage = sage;
}

int Character::getMoveSped() {
	return moveSpeed;
}

void Character::setMoveSped(int moveSpeed) {
	this->moveSpeed = moveSpeed;
}

int Character::getJumpState() {
	return jumpState;
}

bool Character::getMove() {
	return bMove;
}

bool Character::getMoveDir() {
	return moveDir;
}

void Character::setNextFallFrameID(int nextFallFrameID) {
	this->nextFallFrameID = nextFallFrameID;
}

void Character::setCurrentJumpSped(float currentJumpSped) {
	this->currentJumpSped = currentJumpSped;
}

unsigned int Character::getScore() {
	return score;
}

void Character::setScore(unsigned int score) {
	this->score = score;
}

Material* Character::getCharImg() {
	return Materials[1 + 11 * smollJK];
}
