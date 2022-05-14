#include <bits/stdc++.h>
#include "header.h"
#include "core.h"
#include "image.h"
#include "config.h"
#include "textControl.h"
// #include "SDL_mixer.h"
using namespace std;

//Global Initialization.

dungeon* mainCore::Dungeon = new dungeon();
bool mainCore::mouseLeftClick = false;
bool mainCore::mouseRightClick = false;
int mainCore::mouseX = 0;
int mainCore::mouseY = 0;
bool mainCore::quitGame = false;

bool mainCore::movePressed = false;
bool mainCore::menuPressed = false;
bool mainCore::keyS = false;
bool mainCore::keyW = false;
bool mainCore::keyA = false;
bool mainCore::keyD = false;
bool mainCore::keyAPressed = false;
bool mainCore::keyDPressed = false;

//Constructor.
mainCore::mainCore(void) {
	this->quitGame = false;
	this->iFPS = 0;
	this->nFPS = 0;
	this->FPSTime = 0;
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("JumpKing_Nhom25", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		quitGame = true;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	/*
	icon (for later use)
	string imagePath;
	SDL_Surface* loadedSurface = SDL_LoadBMP(imagePath.c_str());
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));
	SDL_SetWindowIcon(window, loadedSurface);
	SDL_FreeSurface(LoadedSurface);
	*/

	string imagePath = "";
	SDL_Surface* loadedSurface = SDL_LoadBMP(imagePath.c_str());
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));
	SDL_SetWindowIcon(window, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	event = new SDL_Event();
}

//Destructor
mainCore :: ~mainCore(void) {
	delete Dungeon;
	delete event;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

//private functions
void mainCore::input() {
	// switch(config :: getMenuManagement()->getID()) {
	// 	case 2: case 7:
	// 		if(!oMap->getInEvent()) {		//this line is not fixed
	// 			inputCharacter();
	// 		} else {
	// 			resetMove();
	// 		}
	// 		break;
	// 	default:
	// 		inputMenu();
	// 		break;
	// }
}
void mainCore::mouseInput() {
	switch (event->type) {
	case SDL_MOUSEBUTTONDOWN: {
		switch (event->button.button) {
		case SDL_BUTTON_LEFT:
			mouseLeftClick = true;
			break;
		case SDL_BUTTON_RIGHT:
			mouseRightClick = true;
			break;
		}
		break;
	}
	case SDL_MOUSEMOTION: {

		SDL_GetMouseState(&mouseX, &mouseY);
		//CCFG::getMM()->getConsole()->print("x:" + std::to_string(mouseX));
		//CCFG::getMM()->getConsole()->print("y:" + std::to_string(mouseY));
		break;
	}
	case SDL_MOUSEBUTTONUP: {
		switch (event->button.button) {
		case SDL_BUTTON_LEFT:
			mouseLeftClick = false;
			break;
		case SDL_BUTTON_RIGHT:
			mouseRightClick = false;
			break;
		}
		break;
	}
	case SDL_MOUSEWHEEL:
		if (event->wheel.timestamp > SDL_GetTicks() - 2) {
			//CCFG::getMM()->getLE()->mouseWheel(mainEvent->wheel.y);
		}
		break;
	}
}
void mainCore::inputCharacter() {
	// if(event->type == SDL_WINDOWEVENT) {
	// 	switch(event->window.event) {
	// 		case SDL_WINDOWEVENT_FOCUS_LOST:
	// 			CCFG::getMM()->resetActiveOptionID(CCFG::getMM()->ePasue);
	// 			CCFG::getMM()->setViewID(CCFG::getMM()->ePasue);
	// 			CCFG::getMusic()->PlayChunk(CCFG::getMusic()->cPASUE);
	// 			CCFG::getMusic()->PauseMusic();
	// 			break;
	// 	}
	// }

	// if(event->type == SDL_KEYUP) {
	// 	if(event->key.keysym.sym == config::keyIDD) {
	// 			if(firstDir) {
	// 				firstDir = false;
	// 			}

	// 			keyDPressed = false;
	// 		}

	// 		if(event->key.keysym.sym == config::keyIDS) {
	// 			oMap->getPlayer()->setSquat(false);
	// 			keyS = false;
	// 		}

	// 		if(event->key.keysym.sym == config::keyIDA) {
	// 			if(!firstDir) {
	// 				firstDir = true;
	// 			}

	// 			keyAPressed = false;
	// 		}

	// 		if(event->key.keysym.sym == config::keyIDSpace) {
	// 			config::keySpace = false;
	// 		}

	// 		if(event->key.keysym.sym == config::keyIDShift) {
	// 			if(keyShift) {
	// 				oMap->getPlayer()->resetRun();
	// 				keyShift = false;
	// 			}
	// 		}
	// 	switch(event->key.keysym.sym) {
	// 		case SDLK_KP_ENTER: case SDLK_RETURN: case SDLK_ESCAPE:
	// 			keyMenuPressed = false;
	// 			break;
	// 	}
	// }

	// if(event->type == SDL_KEYDOWN) {
	// 	if(event->key.keysym.sym == config::keyIDD) {
	// 		keyDPressed = true;
	// 		if(!keyAPressed) {
	// 			firstDir = true;
	// 		}
	// 	}

	// 	if(event->key.keysym.sym == config::keyIDS) {
	// 		if(!keyS) {
	// 			keyS = true;
	// 			if(!oMap->getUnderWater() && !oMap->getPlayer()->getInLevelAnimation()) oMap->getPlayer()->setSquat(true);
	// 		}
	// 	}

	// 	if(event->key.keysym.sym == config::keyIDA) {
	// 		keyAPressed = true;
	// 		if(!keyDPressed) {
	// 			firstDir = false; 				//
	// 		}
	// 	}

	// 	if(event->key.keysym.sym == config::keyIDSpace) {
	// 		if(!config::keySpace) {
	// 			oMap->getPlayer()->jump();
	// 			config::keySpace = true;
	// 		}
	// 	}

	// 	if(event->key.keysym.sym == config::keyIDShift) {
	// 		if(!keyShift) {
	// 			oMap->getPlayer()->startRun();
	// 			keyShift = true;
	// 		}
	// 	}

	// 	switch(event->key.keysym.sym) {
	// 		case SDLK_KP_ENTER: case SDLK_RETURN:
	// 			if(!keyMenuPressed) {
	// 				config::getMM()->enter();
	// 				keyMenuPressed = true;
	// 			}
	// 		case SDLK_ESCAPE:
	// 			if(!keyMenuPressed && config::getMM()->getViewID() == config::getMM()->eGame) {
	// 				config::getMM()->resetActiveOptionID(config::getMM()->ePasue);
	// 				config::getMM()->setViewID(config::getMM()->ePasue);
	// 				config::getMusic()->PlayChunk(config::getMusic()->cPASUE);
	// 				config::getMusic()->PauseMusic();
	// 				keyMenuPressed = true;
	// 			}
	// 			break;
	// 	}
	// }

	// if(keyAPressed) {
	// 	if(!oMap->getPlayer()->getMove() && firstDir == false && !oMap->getPlayer()->getChangeMoveDirection() && !oMap->getPlayer()->getSquat()) {
	// 		oMap->getPlayer()->startMove();
	// 		oMap->getPlayer()->setMoveDirection(false); //false is right
	// 	} else if(!keyDPressed  && oMap->getPlayer()->getMoveSpeed() > 0 && firstDir != oMap->getPlayer()->getMoveDirection()) {
	// 		oMap->getPlayer()->setChangeMoveDirection();
	// 	}
	// }

	// if(keyDPressed) {
	// 	if(!oMap->getPlayer()->getMove() && firstDir == true && !oMap->getPlayer()->getChangeMoveDirection() && !oMap->getPlayer()->getSquat()) {
	// 		oMap->getPlayer()->startMove();
	// 		oMap->getPlayer()->setMoveDirection(true);
	// 	} else if(!keyAPressed && oMap->getPlayer()->getMoveSpeed() > 0 && firstDir != oMap->getPlayer()->getMoveDirection()) {
	// 		oMap->getPlayer()->setChangeMoveDirection();
	// 	}
	// }

	// if(oMap->getPlayer()->getMove() && !keyAPressed && !keyDPressed) {
	// 	oMap->getPlayer()->resetMove();
	// }
}
void mainCore::inputMenu() {
	if (event->type == SDL_KEYDOWN) {
		config::getMenuManagement()->setKey(event->key.keysym.sym);

		switch (event->key.keysym.sym) {
		case SDLK_s: case SDLK_DOWN:
			if (!menuPressed) {
				config::getMenuManagement()->keyPressed(2);
				menuPressed = true;
			}
			break;
		case SDLK_w: case SDLK_UP:
			if (!menuPressed) {
				config::getMenuManagement()->keyPressed(0);
				menuPressed = true;
			}
			break;
		case SDLK_KP_ENTER: case SDLK_RETURN:
			if (!menuPressed) {
				config::getMenuManagement()->enter();
				menuPressed = true;
			}
			break;
		case SDLK_ESCAPE:
			if (!menuPressed) {
				config::getMenuManagement()->escape();
				menuPressed = true;
			}
			break;
		case SDLK_LEFT: case SDLK_d:
			if (!menuPressed) {
				config::getMenuManagement()->keyPressed(3);
				menuPressed = true;
			}
			break;
		case SDLK_RIGHT: case SDLK_a:
			if (!menuPressed) {
				config::getMenuManagement()->keyPressed(1);
				menuPressed = true;
			}
			break;
		}
	}

	if (event->type == SDL_KEYUP) {
		switch (event->key.keysym.sym) {
		case SDLK_s: case SDLK_DOWN: case SDLK_w: case SDLK_UP: case SDLK_KP_ENTER: case SDLK_RETURN: case SDLK_ESCAPE: case SDLK_a: case SDLK_RIGHT: case SDLK_LEFT: case SDLK_d:
			menuPressed = false;
			break;
		default:
			break;
		}
	}
}

//mainloop to start the game
void mainCore::mainLoop() {
	FPSTime = SDL_GetTicks();

	while (!quitGame && event->type != SDL_QUIT) {
		frameTime = SDL_GetTicks();
		SDL_PollEvent(event);
		SDL_RenderClear(renderer);

		config::getMenuManagement()->setBGColor(renderer);
		SDL_RenderFillRect(renderer, NULL);

		input();
		mouseInput();
		Update();
		Draw();

		// CCFG::getText()->Draw(rR, "FPS:" + std::to_string(iNumOfFPS), CCFG::GAME_WIDTH - CCFG::getText()->getTextWidth("FPS:" + std::to_string(iNumOfFPS), 8) - 8, 5, 8);

		// if(SDL_GetTicks() - 1000 >= lFPSTime) {
		// 	lFPSTime = SDL_GetTicks();
		// 	iNumOfFPS = iFPS;
		// 	iFPS = 0;
		// }

		// ++iFPS;

		SDL_RenderPresent(renderer);

		if (SDL_GetTicks() - frameTime < minFrameTime) {
			SDL_Delay(minFrameTime - (SDL_GetTicks() - frameTime));
		}
	}
}

//Update and draw function
void mainCore::Update() {
	config::getMenuManagement()->Update();
}
void mainCore::Draw() {
	config::getMenuManagement()->Draw(renderer);
}

//reset Functions
void mainCore::resetMove() {
	this->keyAPressed = this->keyDPressed = false;
}

void mainCore::resetKeys() {
	movePressed = menuPressed = keyS = keyW = keyA = keyD = config::pressSpace /*= keyShift */ = keyAPressed = keyDPressed = false;
}

dungeon* mainCore :: getDungeon(){
	return Dungeon;
}