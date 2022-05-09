#include"menu.h"
#include"config.h"

using namespace std;

//vector<menuOption*> menuOptionList

Menu :: Menu(void){
    this -> menuOptionAct = 0;
    this -> menuOptionCnt = 0;
}

Menu :: ~Menu(void){
    //...
}

void Menu :: Update(){

}

void Menu :: Draw(SDL_Renderer* renderer){
	for(unsigned int i = 0; i < menuOptionList.size(); i++) {
		config :: getText()->Draw(renderer, menuOptionList[i]->getText(), menuOptionList[i]->getX(), menuOptionList[i]->getY());
	}
	config :: getMenuManagement()->getActiveOption()->Draw(renderer, menuOptionList[menuOptionAct]->getX() - 32, menuOptionList[menuOptionAct]->getY());
}

void Menu :: updateActiveButton(int directory){
    switch(directory) {
		case 0:
			if (menuOptionAct - 1 < 0) {
				menuOptionAct = menuOptionCnt - 1;
			} else {
				--menuOptionAct;
			}
			break;
		case 2:
			if (menuOptionAct + 1 >= menuOptionCnt) {
				menuOptionAct = 0;
			} else {
				++menuOptionAct;
			}
			break;
		default:
			break;
	}
}

