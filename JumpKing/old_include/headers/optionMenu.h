#pragma once

#ifndef OPTIONMENU_H
#define OPTIONMENU_H

#include "Menu.h"

//subclass optionMenu, an instance of Menu.
class optionMenu : public Menu
{
private:
	SDL_Rect optionRect;
	SDL_Rect SetKey;

	bool inSetKey, resetSetKey;
	bool escTo_mainMenu;
public:
	//Constructor.
	optionMenu(void);
	//Destructor.
	~optionMenu(void);

	/*
	* Functions.
	* Update, Draw and updateActiveButton are up-casting functions from virtual Menu::void.
	*/
	void Update();
	void Draw(SDL_Renderer* rR);
	void updateActiveButton(int iDir);

	void enter();
	void escape();
	void setKey(int keyID);
	void setEscTo_mainMenu(bool escTo_mainMenu);
};

#endif

