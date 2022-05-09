#include"optionMenu.h"
#include"config.h"
#include"core.h"

using namespace std;

//Constructor
optionMenu :: optionMenu(void){
	// h and w
    optionRect.h = 680;
    optionRect.w = 1040;
	// x and y
    optionRect.y = 200;
    optionRect.x = 200;

	// this->menuOptionList.push_back(new MenuOption("VOLUME", 73, 65));
	this -> menuOptionList.push_back(new menuOption("LEFT", 73, 89));
	// this -> menuOptionList.push_back(new menuOption("DOWN", 73, 113));
	this -> menuOptionList.push_back(new menuOption("RIGHT", 73, 137));
	this -> menuOptionList.push_back(new menuOption("JUMP", 73, 161));
	// this -> menuOptionList.push_back(new menuOption("RUN", 73, 185));
	this -> menuOptionList.push_back(new menuOption("CAN MOVE BACKWARD", 73, 209));
	this -> menuOptionList.push_back(new menuOption("MAIN MENU", 73, 257));

    // SetKey.h = 70
    // SetKey.w = 350
    // SetKey.x = 80
    // SetKey.y = 280

    this -> inSetKey = false;
    this -> resetSetKey = false;

    this -> escTo_mainMenu = true;

}

//Destructor
optionMenu ::~optionMenu(void){
    
}

//Update and draw functions
void optionMenu :: Update(){
    if (resetSetKey){
        inSetKey = false;
        resetSetKey = false;
    }
}

void optionMenu :: Draw(SDL_Renderer* renderer){
    //blend others
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    //draw a rectangle that contains the option
    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 240);
    SDL_RenderFillRect(renderer, &optionRect);

    //draw another to create layers of menu
    SDL_SetRenderDrawColor(renderer, 5, 5, 5, 255);

    /* decrease the portion */
	optionRect.x += 5; 	// 545
	optionRect.y += 5;	// 410
	optionRect.h -= 10;	// 350
	optionRect.w -= 10;	// 260

    SDL_RenderFillRect(renderer, &optionRect);

    for(unsigned int i = 0; i < menuOptionList.size(); i++) {
		if(i == menuOptionAct) {
			config :: getText()->Draw(renderer, menuOptionList[i] -> getText(), menuOptionList[i]->getX(), menuOptionList[i] -> getY(), 20, 255, 255, 255);
		} else {
			config :: getText()->Draw(renderer, menuOptionList[i] -> getText(), menuOptionList[i]->getX(), menuOptionList[i] -> getY(), 20, 50, 50, 50);
		}
	}

	// SDL_SetRenderDrawColor(rR, 4, 4, 4, 245);
	// SDL_RenderFillRect(rR, &rVolumeBG);

	// SDL_SetRenderDrawColor(rR, activeMenuOption == 0 ? 150 : 90, activeMenuOption == 0 ? 150 : 90, activeMenuOption == 0 ? 150 : 90, 255);
	// SDL_RenderFillRect(rR, &rVolume);

	// if(activeMenuOption == 0) {
	// 	SDL_SetRenderDrawColor(rR, 255, 255, 255, 255);
	// 	SDL_RenderDrawRect(rR, &rVolumeBG);
	// } else {
	// 	SDL_SetRenderDrawColor(rR, 160, 160, 160, 55);
	// 	SDL_RenderDrawRect(rR, &rVolumeBG);
	// }

    config :: getText() -> Draw(renderer, config :: getKey(config :: keyID_A), 185, 89, 16, menuOptionAct == 1 ? 255 : 90, menuOptionAct == 1 ? 255 : 90, menuOptionAct == 1 ? 255 : 90);
	config :: getText() -> Draw(renderer, config :: getKey(config :: keyID_S), 185, 113, 16, menuOptionAct == 2 ? 255 : 90, menuOptionAct == 2 ? 255 : 90, menuOptionAct == 2 ? 255 : 90);
	config :: getText() -> Draw(renderer, config :: getKey(config :: keyID_D), 185, 137, 16, menuOptionAct == 3 ? 255 : 90, menuOptionAct == 3 ? 255 : 90, menuOptionAct == 3 ? 255 : 90);
	config :: getText() -> Draw(renderer, config :: getKey(config :: keyID_Space), 185, 161, 16, menuOptionAct == 4 ? 255 : 90, menuOptionAct == 4 ? 255 : 90, menuOptionAct == 4 ? 255 : 90);
	config :: getText() -> Draw(renderer, config :: getKey(config :: keyID_Shift), 185, 185, 16, menuOptionAct == 5 ? 255 : 90, menuOptionAct == 5 ? 255 : 90, menuOptionAct == 5 ? 255 : 90);

	config :: getText()->Draw(renderer, config :: moveBack ? "TRUE" : "FALSE", 357, 209, 16, menuOptionAct == 6 ? 255 : 90, menuOptionAct == 6 ? 255 : 90, menuOptionAct == 6 ? 255 : 90);

    // many things

    if(inSetKey) {
		SDL_SetRenderDrawColor(renderer, 20, 20, 20, 245);
		SDL_RenderFillRect(renderer, &SetKey);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SetKey.x += 1;
		SetKey.y += 1;
		SetKey.h -= 2;
		SetKey.w -= 2;
		SDL_RenderDrawRect(renderer, &SetKey);
		SetKey.x -= 1;
		SetKey.y -= 1;
		SetKey.h += 2;
		SetKey.w += 2;

		config :: getText()->Draw(renderer, "PRESS KEY FOR " + menuOptionList[menuOptionAct]->getText(), 92, SetKey.y + 16, 16, 255, 255, 255);
		config :: getText()->Draw(renderer, "PRESS ESC TO CANCEL", 92, SetKey.y + 40, 16, 255, 255, 255);
	}


    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    //CCore::getDungeon()->setBackgroundColor(rR);
}

void optionMenu :: enter(){
    switch(menuOptionAct) {
		case 0:
			// CCFG::getMusic()->PlayChunk(CCFG::getMusic()->cCOIN);
			break;
		case 1: case 2: case 3: case 4: case 5:
			inSetKey = true;
			break;
		case 6:
			config :: moveBack = !config :: moveBack;
			break;
		case 7:
			// CCore::getDungeon()->resetGameData();
			// config :: getMenuManagement() -> setID(config :: getMenuManagement()->mainMenu_state);
			break;
	}
}

void optionMenu :: updateActiveButton(int iDir){
	// if(menuOptionAct == 0 && (iDir == 1 || iDir == 3)) {
	// 	switch(iDir) {
	// 		case 1:
	// 			if(CCFG::getMusic()->getVolume() < 100) {
	// 				CCFG::getMusic()->setVolume(CCFG::getMusic()->getVolume() + 5);
	// 			} else {
	// 				CCFG::getMusic()->setVolume(100);
	// 			}
	// 			break;
	// 		case 3:
	// 			if(CCFG::getMusic()->getVolume() > 0) {
	// 				CCFG::getMusic()->setVolume(CCFG::getMusic()->getVolume() - 5);
	// 			} else {
	// 				CCFG::getMusic()->setVolume(0);
	// 			}
	// 			break;
	// 	}
	// 	updateVolumeRect();
	// 	CCFG::getMusic()->PlayChunk(CCFG::getMusic()->cCOIN);
	// }
	// if(!inSetKey) {
	// 	Menu::updateActiveButton(iDir);
	// }
}

void optionMenu :: escape(){
    if(inSetKey) {
		resetSetKey = true;
	} else {
		if(escTo_mainMenu) {
			//CCore::getDungeon()->resetGameData();
			config :: getMenuManagement()->setID(config :: getMenuManagement() -> mainMenu_state);
		} else {
			config :: getMenuManagement()->setID(config :: getMenuManagement() -> pause_state);
		}
	}
}

void optionMenu :: setKey(int keyID){

}

void optionMenu :: setEscTo_mainMenu(bool escTo_mainMenu){
	this -> escTo_mainMenu = escTo_mainMenu;
}

