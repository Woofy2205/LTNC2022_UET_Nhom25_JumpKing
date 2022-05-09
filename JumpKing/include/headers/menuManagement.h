#pragma once
#ifndef MENUMANAGEMENT_H
#define MENUMANAGEMENT_H

#include"image.h"			//For loading images purposes.
//Then list all types of menu below.
#include"mainMenu.h"
#include"loadingMenu.h"
#include"optionMenu.h"
#include"pauseMenu.h"

class menuManagement {
private:
	Image* activeOption;
	mainMenu* _mainMenu;
	loadingMenu* _loadingMenu;
	optionMenu* _optionMenu;
	pauseMenu* _pauseMenu;

public:
	//Constructor.
	menuManagement(void);
	//Destructor.
	~menuManagement(void);

	enum gameState {
		mainMenu_state,
		loading_state,
		gaming_state,
		option_state,
		pause_state,
	};

	gameState currentState;

	void Update();
	void Draw(SDL_Renderer* renderer);
	void setBGColor(SDL_Renderer* renderer);

	void enter();
	void escape();
	void setKey(int keyId);
	void keyPressed(int dir);

	//enum gameState ID starts from 0.
	void resetActiveOptionID(gameState id);

	//Getters and Setters.
	int getID();
	void setID(gameState viewID);

	Image* getActiveOption();
	void setActiveOption(SDL_Renderer* rR);

	loadingMenu* getLoadingMenu();
	optionMenu* getOptionMenu();

};
#endif