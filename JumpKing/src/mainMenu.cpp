#include"mainMenu.h"
#include"core.h"
#include"config.h"

using namespace std;

//Constructor.
mainMenu::mainMenu(void) {
	this->menuOptionList.push_back(new menuOption("LET'S JUMP!", 178, 276));
	this->menuOptionList.push_back(new menuOption("OPTIONS", 222, 308));

	this->menuOptionCnt = (int)menuOptionList.size();

	this->selectLevel = false;

	this->levelSelection.x = 122;
	this->levelSelection.y = 280;
	this->levelSelection.w = 306;
	this->levelSelection.h = 72;

	this->currentLevelID = 0;
	this->nextLevelID = 0;
}

//Destructor.
mainMenu::~mainMenu(void) {
	//this shouldn't have been existed...
}


/*
* Functions.
* Update, Draw and updateActiveButton are up-casting functions from virtual Menu::void.
*/
void mainMenu::Update() {
	//config::getMusic()->stopMusic();
	Menu::Update();
}

void mainMenu::Draw(SDL_Renderer* renderer) {
	config :: getLogo()->Draw(renderer, 80, 48);
	Menu :: Draw(renderer);
	config :: getText()->Draw(renderer, "TsunNDC's Production", 4, config :: gameHeight - 4 - 8, 8, 0, 0, 0);
	config :: getText()->Draw(renderer, "TsunNDC's Production", 5, config :: gameHeight - 5 - 8, 8, 255, 255, 255);
	//Shading for text glowing effects, pretty cool huh Woof.

	if (selectLevel) {
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(renderer, 4, 4, 4, 235);
		SDL_RenderFillRect(renderer, &levelSelection);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		levelSelection.x += 1;
		levelSelection.y += 1;
		levelSelection.h -= 2;
		levelSelection.w -= 2;
		SDL_RenderDrawRect(renderer, &levelSelection);
		levelSelection.x -= 1;
		levelSelection.y -= 1;
		levelSelection.h += 2;
		levelSelection.w += 2;

		config::getText()->Draw(renderer, "SELECT LEVEL", levelSelection.x + levelSelection.w / 2 - config::getText()->getTextWidth("SELECT LEVEL") / 2, levelSelection.y + 16, 16, 255, 255, 255);
		//This to push "SELECT LEVEL" string to centre of the dialog.

		for (int i = 0, xIndent = 0; i < 8; i++) {
			if (i == currentLevelID) {
				config::getText()->Draw(renderer, std::to_string(i + 1) + "-" + std::to_string(nextLevelID + 1), levelSelection.x + 16 * (i + 1) + 16 * i + xIndent, levelSelection.y + 16 + 24, 16, 255, 255, 255);

				xIndent = 32;
			}
			else {
				config::getText()->Draw(renderer, to_string(i + 1), levelSelection.x + 16 * (i + 1) + 16 * i + xIndent, levelSelection.y + 16 + 24, 16, 90, 90, 90);
			}
		}

		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
		//mainCore::getDungeon()->setBGColor(renderer);
	}
}

void mainMenu::enter() {
	switch (currentLevelID) {
		case 0:
			if (!selectLevel) {
				selectLevel = true;
			}
			else {
				config :: getMenuManagement() -> getLoadingMenu() -> updateTime();
				//mainCore::getDungeon()->resetGameData();
				//mainCore::getDungeon()->setCurrentLevelID(currentLevelID* 4 + nextLevelID);
				config :: getMenuManagement() -> setID(config :: getMenuManagement() -> loading_state);
				config :: getMenuManagement() -> getLoadingMenu() -> loadingState = true;
				//config::getDungeon()->setSpawnPointID(0);
				selectLevel = false;
			}
			break;
		case 1:
			config :: getMenuManagement() -> getOptionMenu() -> setEscTo_mainMenu(true);
			config :: getMenuManagement() -> resetActiveOptionID(config::getMenuManagement() -> option_state);
			//config :: getMenuManagement()->getOptions()->updateVolumeRect();
			config :: getMenuManagement() -> setID(config :: getMenuManagement() -> option_state);
			break;
	}
}

void mainMenu::escape() {
	selectLevel = false;
}

//Function to choose specific Levels and Stages.
void mainMenu::updateActiveButton(int dir) {
	switch (dir) {
		case 0: case 2:	
			if (!selectLevel) {
				Menu::updateActiveButton(dir);
			}
			else {
				switch (dir) {
				case 0:
					if (nextLevelID < 1) {
						nextLevelID = 3;
					}
					else {
						nextLevelID--;
					}
					break;
				case 2:
					if (nextLevelID > 2) {
						nextLevelID = 0;
					}
					else {
						nextLevelID++;
					}
					break;
				}
			}
			break;
		case 1:
			if (selectLevel) {
				if (currentLevelID < 7) {
					currentLevelID++;
				}
				else {
					currentLevelID = 0;
				}
			}
			break;
		case 3:
			if (selectLevel) {
				if (currentLevelID > 0) {
					currentLevelID--;
				}
				else {
					currentLevelID = 7;
				}
			}
			break;
		}
}
