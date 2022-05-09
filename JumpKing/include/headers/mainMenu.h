#pragma once
#pragma once

#ifndef MAINMENU_H
#define MAINMENU_H

#include"menu.h"

//subclass mainMenu, an instance of Menu.
class mainMenu : public Menu {
private:
	bool selectLevel;
	int currentLevelID;
	int nextLevelID;
	SDL_Rect levelSelection;
public:
	//Constructor.
	mainMenu(void);
	//Destructor.
	~mainMenu(void);

	/*
	* Functions.
	* Update, Draw and updateActiveButton are up-casting functions from virtual Menu::void.
	*/
	void Update();
	void Draw(SDL_Renderer* renderer);
	void enter();
	void escape();
	void updateActiveButton(int dir);
};

#endif