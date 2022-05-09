#include"Event.h"
#include"core.h"

using namespace std;

/// <summary>
/// Constructor.
/// </summary>
Event::Event(void){
	this->delay = 0;
	this->endGame = false;
	this->time = 0;
	this->state = 0;
	this->stepID = 0;
}
/// <summary>
/// Destructor.
/// </summary>
Event::~Event(void){

}

/// <summary>
/// Normal Game Happening.
/// </summary>
void Event::Normal(){
	if (state) {
		if (oldDirections.size() > stepID) {
			if (oldLength[stepID] > 0) {
				switch (oldDirections[stepID]) {
					//Directions.
					case eTop:
					case eBottom:
					case eRight:
					case eLeft:
						//Frame-ends.
					case eRightEnd:
					case eLeftEnd:
					case eEndBot1:
					case eEndBot2:
					case eEndPoint:
						//Dead states.
					case eDeath:
					case eDeathTop:
					case eDeathBot:
						//Game ends.
					case eGameOver:
						//Normal state.
					case eNormalState:
						//Loading state.
					case eLoading:
						//End-game state.
					case eEndGame:
						//Sprite.
					case eCharSprite:
						break;
				}
			}
			else {
				stepID++;
				time = SDL_GetTicks();
			}
		}
		else {
			if (!endGame) {
				if ((signed)SDL_GetTicks() >= time + delay) {
					state = false;
					stepID = 0;
					newDungeon();
					/*
					mainCore::getDungeon()->getPlayer()->stopMove();
					if (inEvent) {
						config::getMenuManagement()->getLoadingMenu()->updateTime();
						config::getMenuManagement()->getLoadingMenu()->loadingState = true;
						config::getMenuManagement()->setID(config::getMenuManagement()->loading_state);
						mainCore::getDungeon()->startLevelAnimation();
					}
					*/

					config::pressSpace = false;
				}
			}
			else {
				//mainCore::getDungeon()->resetGameData();
				config::getMenuManagement()->setID(config::getMenuManagement()->mainMenu_state);
				mainCore::getDungeon()->setInEvent(false);
				//mainCore::getDungeon()->getPlayer()->stopMove();
				inEvent = false;
				config::pressSpace = false;
				endGame = false;
				stepID = 0;
			}
		}
	}
	else {
		if (newDirections.size() > stepID) {
			if (newLength[stepID] > 0) {
				/*
				switch (newDirections[stepID]) {
				case eTop: // TOP
					mainCore::getDungeon()->getPlayer()->setYPos((float)mainCore::getDungeon()->getPlayer()->getYPos() - speed);
					newLength[stepID] -= iSpeed;
					break;
				case eBottom:
					mainCore::getDungeon()->getPlayer()->setYPos((float)mainCore::getDungeon()->getPlayer()->getYPos() + speed);
					newLength[stepID] -= iSpeed;
					break;
				case eRight:
					mainCore::getDungeon()->getPlayer()->setXPos((float)mainCore::getDungeon()->getPlayer()->getXPos() + speed);
					newLength[stepID] -= iSpeed;
					mainCore::getDungeon()->getPlayer()->moveAnimation();
					break;
				case eLeft:
					mainCore::getDungeon()->getPlayer()->setXPos((float)mainCore::getDungeon()->getPlayer()->getXPos() - speed);
					newLength[stepID] -= iSpeed;
					mainCore::getDungeon()->getPlayer()->moveAnimation();
					break;
				case eNormalState: //Dit me NDC comment vao nhe.
					newLength[stepID] -= 1;
					break;
				}
				*/
			}
			else {
				stepID++;
			}
		}
		else {
			mainCore::getDungeon()->setInEvent(false);
			//mainCore::getDungeon()->getPlayer()->stopMove();
			//config::getMusic()->changeMusic(true, true);
			inEvent = false;
			config::pressSpace = false;
			mainCore::resetKeys();
		}
	}
}

/// <summary>
/// Draw Method.
/// </summary>
/// <param name="renderer">
/// Pointer to the Renderer.
/// </param>
void Event::Draw(SDL_Renderer* renderer){
	/*
	for (int i = 0; i < reDrawX.size(); i++) {
		if (reDrawX[i] < mainCore::getDungeon()->getDungeonWidth()) {
			mainCore::getDungeon()->getBlock(mainCore::getDungeon()->getDungeonBlock(reDrawX[i],reDrawY[i])->getBlockID())->Draw(rR, 32 * reDrawX[i] + (int)mainCore::getDungeon()->getXPos(), config::gameHeight - 32 * reDrawY[i] - 16);
		}
	}
	*/
}

/// <summary>
/// Animate Method.
/// </summary>
void Event::Animate(){
	switch (eID) {
		case eNormalState: {
			Normal();
			break;
		}
		case eEnd: {
			Normal();
			End();
			break;
		}
		default:
			Normal();
			break;
	}
}

/// <summary>
/// Ending state.
/// </summary>
void Event::End() {
	/*
	if (mainCore::getDungeon()->getFlag() != NULL && mainCore::getDungeon()->getFlag()->iYPos < config::GAME_HEIGHT - 16 - 3 * 32 - 4) {
		mainCore::getDungeon()->getFlag()->Update();
	}
	*/
}

/// <summary>
/// New Dungeons Setup.
/// </summary>
void Event::newDungeon() {
	/*
	mainCore::getDungeon()->setXPos((float)newDungeonPos);
	mainCore::getDungeon()->getPlayer()->setXPos((float)newCharXPos);
	mainCore::getDungeon()->getPlayer()->setYPos((float)newCharYPos);
	mainCore::getDungeon()->setMoveMap(newDungeon);
	if (mainCore::getDungeon()->getCurrentLevelID() != newCurrentLevel) {
		config::getMenuManagement()->getLoadingMenu()->updateTime();
		config::getMenuManagement()->getLoadingMenu()->loadingState = true;
		config::getMenuManagement()->setID(config::getMenuManagement()->loading_state);
		mainCore::getDungeon()->getPlayer()->setCoins(0);
	}
	mainCore::getDungeon()->setCurrentLevelID(newCurrentLevel);
	mainCore::getDungeon()->setLevelType(newLevelType);

	mainCore::getDungeon()->lockObjects();
	*/
}

/// <summary>
/// Resetting Data.
/// </summary>
void Event::resetData() {
	newDirections.clear();
	newLength.clear();
	oldDirections.clear();
	oldLength.clear();
	resetReDraw();

	this->eID = eNormal;

	this->state = true;
	this->stepID = 0;
	this->inEvent = false;
	this->endGame = false;
}

/// <summary>
/// Resetting ReDraws.
/// </summary>
void Event::resetReDraw() {
	reDrawX.clear();
	reDrawY.clear();
}
