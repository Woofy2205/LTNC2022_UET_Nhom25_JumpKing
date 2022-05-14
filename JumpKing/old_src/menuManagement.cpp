#include"menuManagement.h"
#include"core.h"

//Constructor.
menuManagement :: menuManagement(void) {

	this->currentState = mainMenu_state;

	//initialize.
	this->_mainMenu = new mainMenu();
	this->_optionMenu = new optionMenu();
	this->_loadingMenu = new loadingMenu();
	this->_pauseMenu = new pauseMenu();
	
}

//Destructor.
menuManagement :: ~menuManagement(void) {
	delete activeOption;
	delete _mainMenu;
	delete _loadingMenu;
}

enum gameState {
	mainMenu_state,
	loading_state,
	gaming_state,
	option_state,
	pause_state,
};

void menuManagement::Update() {
	switch (currentState) {
		case mainMenu_state:
			_mainMenu->Update();
			//mainCore::getDungeon()->UpdateBlocks();
			break;
		case loading_state:
			_loadingMenu->Update();
			break;
		case gaming_state:
			//mainCore::getDungeon()->Update();
			//mainCore::getDungeon()->UpdateMinionsCollisions();
			break;
		case option_state:
			_optionMenu->Update();
			break;
		case pause_state:
			_pauseMenu->Update();
			break;
	}
}

void menuManagement::Draw(SDL_Renderer* renderer) {
	switch (currentState) {
		case mainMenu_state:
			//mainCore::getDungeon()->DrawMap(renderer);
			//mainCore::getDungeon()->getPlayer()->Draw(renderer);
			//mainCore::getDungeon()->DrawGameLayout(renderer);
			_mainMenu->Draw(renderer);
			break;
		case loading_state:
			_loadingMenu->Draw(renderer);
			break;
		case gaming_state:
			//mainCore::getDungeon()->Draw(renderer);
			break;
		case option_state:
			//mainCore::getDungeon()->DrawMap(renderer);
			//mainCore::getDungeon()->DrawMinions(renderer);
			//mainCore::getDungeon()->getPlayer()->Draw(renderer);
			//mainCore::getDungeon()->DrawGameLayout(renderer);
			_optionMenu->Draw(renderer);
			break;
		case pause_state:
			//mainCore::getDungeon()->DrawMap(renderer);
			//mainCore::getDungeon()->DrawMinions(renderer);
			//mainCore::getDungeon()->getPlayer()->Draw(renderer);
			//mainCore::getDungeon()->DrawGameLayout(renderer);
			_pauseMenu->Draw(renderer);
			break;
	}
}

void menuManagement::setBGColor(SDL_Renderer* renderer) {
	switch (currentState) {
		case mainMenu_state:
			//mainCore::getDungeon()->setBGColor(renderer);
			break;
		case loading_state:
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			break;
		case gaming_state:
			//mainCore::getDungeon()->setBGColor(renderer);
			break;
	}
}

void menuManagement::enter() {
	switch(currentState) {
		case mainMenu_state:
			_mainMenu->enter();
			break;
		case gaming_state:
			//mainCore::getDungeon()->setDrawLines(!mainCore::getDungeon()->getDrawLines());
			break;
		case option_state:
			_optionMenu->enter();
			break;
		case pause_state:
			_pauseMenu->enter();
			break;
	}
}

void menuManagement::escape() {
	switch (currentState) {
		case gaming_state:
			break;
		case option_state:
			_optionMenu->escape();
			break;
		case pause_state:
			_pauseMenu->escape();
			break;
		case mainMenu_state:
			_mainMenu->escape();
			break;
	}
}

void menuManagement::setKey(int id) {
	switch (currentState) {
		case option_state:
			_optionMenu->setKey(id);
			break;
	}
}

void menuManagement::keyPressed(int dir) {
	switch (currentState) {
		case mainMenu_state:
			_mainMenu->updateActiveButton(dir);
			break;
		case option_state:
			_optionMenu->updateActiveButton(dir);
			break;
		case pause_state:
			_pauseMenu->updateActiveButton(dir);
			break;
	}
}

//enum gameState ID starts from 0.
void menuManagement::resetActiveOptionID(gameState id) {
	switch (id) {
		case mainMenu_state:
			//_mainMenu->activeMenuOption = 0;
			break;
		case option_state:
			//_optionMenu->activeMenuOption = 0;
			break;
		case pause_state:
			//_pauseMenu->activeMenuOption = 0;
			break;
	}
}

//Getters and Setters.
int menuManagement::getID() {
	return currentState;
}
void menuManagement::setID(gameState id) {
	this->currentState = id;
}

Image* menuManagement::getActiveOption() {
	return activeOption;
}

void menuManagement::setActiveOption(SDL_Renderer* renderer) {
	activeOption = new Image("active_option", renderer);
}

loadingMenu* menuManagement::getLoadingMenu() {
	return _loadingMenu;
}

optionMenu* menuManagement::getOptionMenu() {
	return _optionMenu;
}
