#include"loadingMenu.h"
#include"core.h"
#include"config.h"

//Constructor.
loadingMenu :: loadingMenu(void) {
    this -> time = 0;
    this -> loadingState = true;
}
//Destructor.
loadingMenu :: ~loadingMenu(void){
    // nothing...
}

/*
* Functions.
* Update and Draw are up-casting functions from virtual Menu::void.
*/
void loadingMenu :: Update() {
    if((int)SDL_GetTicks() >= time + 2500 + (loadingState ? 0 : 2750)) {
		if(loadingState) {
			// if(!CCore::getDungeon()->getInEvent()) {
			// 	CCore::getDungeon()->setSpawnPoint();
			// 	CCore::getDungeon()->loadLVL();
			// }
			config::getMenuManagement()->setID(config :: getMenuManagement() -> gaming_state);
			// config::getMusic()->changeMusic(true, true);
		} else {
			// CCore::getDungeon()->resetGameData();
			config::getMenuManagement()->setID(config :: getMenuManagement() -> mainMenu_state);
		}
	} else {
		// config::getMusic()->StopMusic();
	}
	// CCore::getDungeon()->UpdateBlocks();
}

void loadingMenu :: Draw(SDL_Renderer* renderer) {
    if(loadingState) {
		// CCore::getDungeon()->DrawGameLayout(rR);
		config :: getText()->Draw(renderer, "WORLD", 320, 144);
		// config :: getText()->Draw(renderer, CCore::getDungeon()->getLevelName(), 416, 144);

		// CCore::getDungeon()->getPlayer()->getMarioSprite()->getTexture()->Draw(rR, 342, 210 - CCore::getDungeon()->getPlayer()->getHitBoxY()/2);

		config :: getText()->Draw(renderer, "y", 384, 208);

		// if(CCore::getDungeon()->getPlayer()->getNumOfLives() > 9) {
		// 	CCore::getDungeon()->getBlock(180)->getSprite()->getTexture()->Draw(rR, 410, 210);
		// }
		// config::getText() -> Draw(renderer, std::to_string(CCore::getDungeon()->getPlayer()->getNumOfLives()), 432, 208);
		config :: getText() -> DrawCenterX(renderer, "REMEMBER THAT YOU CAN RUN WITH " + config :: getKey(config :: keyID_Shift), 400, 16);
	} else {
		// CCore::getDungeon()->DrawGameLayout(rR);
		config :: getText()->DrawCenterX(renderer, "GAME OVER", 240, 16);
	}
}
void loadingMenu :: updateTime() {
    this -> time = SDL_GetTicks();
}


