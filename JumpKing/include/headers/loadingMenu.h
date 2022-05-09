#pragma once

#ifndef LOADINGMENU_H
#define LOADINGMENU_H

#include"menu.h"

//subclass mainMenu, an instance of Menu.
class loadingMenu : public Menu {
private:
	int time;
public:
	/*
	* boolean gameState
	* return false if the game is over.
	* return true if the game is loading.
	*/
	bool loadingState;
	
	//Constructor.
	loadingMenu(void);
	//Destructor.
	~loadingMenu(void);

	/*
	* Functions.
	* Update and Draw are up-casting functions from virtual Menu::void.
	*/
	void Update();
	void Draw(SDL_Renderer* renderer);
	void updateTime();
};

#endif
