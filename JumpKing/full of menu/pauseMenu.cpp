#include "pauseMenu.h"
#include "config.h"
#include "core.h"

//Constructor.
pauseMenu::pauseMenu(void) {
	//h and w
    pauseRect.h = 270;
    pauseRect.w = 360;
	//x and y 
    pauseRect.y = 405;
    pauseRect.x = 540;

	this->menuOptionList.push_back(new menuOption("RESUME", 0, 460));
	this->menuOptionList.push_back(new menuOption("OPTIONS", 0, 530));

	this->menuOptionList.push_back(new menuOption("QUIT TO MENU", 0, 600));
	// this->menuOptionList.push_back(new menuOption("QUIT TO DESKTOP", 0, 252));

	this->menuOptionCnt = (int)menuOptionList.size();
}
//Destructor.
pauseMenu::~pauseMenu(void) {

}

/*
* Functions.
* Update, updateActiveButton and Draw are up-casting functions from virtual Menu::void.
*/
void pauseMenu::Update() {

}

void pauseMenu::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 240);

	SDL_RenderFillRect(renderer, &pauseRect);

	SDL_SetRenderDrawColor(renderer, 5, 5, 5, 255);

    pauseRect.x += 5; 	// 545
	pauseRect.y += 5;	// 410
	pauseRect.h -= 10;	// 350
	pauseRect.w -= 10;	// 260

    SDL_RenderFillRect(renderer, &pauseRect);

    for(unsigned int i = 0; i < menuOptionList.size(); i++) {
		if(i == menuOptionAct) {
	 		config :: getText() -> DrawCenterX(renderer, menuOptionList[i]->getText(), menuOptionList[i]->getY(), 20, 255, 255, 255);
	 	} else {
	 		config :: getText() -> DrawCenterX(renderer, menuOptionList[i]->getText(), menuOptionList[i]->getY(), 20, 50, 50, 50);
	 	}
	}

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
	// CCore::getDungeon()->setBackgroundColor(rR);
}

void pauseMenu::enter() {
    switch(menuOptionAct) {
		case 0:
			config :: getMenuManagement() -> setID(config :: getMenuManagement() -> gaming_state);
			// config::getMusic()->PlayMusic();
			break;
		case 1:
			config :: getMenuManagement() -> getOptionMenu() -> setEscTo_mainMenu(false);
			config :: getMenuManagement() -> resetActiveOptionID (config :: getMenuManagement() -> option_state);
			// config :: getMenuManagement()->getOptionMenu()->updateVolumeRect();
			config :: getMenuManagement() -> setID (config :: getMenuManagement() -> option_state);
			break;
		case 2:
			// CCore::getDungeon()->resetGameData();
			config :: getMenuManagement() -> setID (config :: getMenuManagement() -> mainMenu_state);
			break;
		// case 3:
		// 	CCore::quitGame = true;
		// 	break;
	}
}

void pauseMenu::escape() {
    config :: getMenuManagement() -> setID(config :: getMenuManagement() -> gaming_state);
	// CCFG::getMusic()->PauseMusic();
}

void pauseMenu::updateActiveButton(int directory) {
    Menu :: updateActiveButton(directory);
}


