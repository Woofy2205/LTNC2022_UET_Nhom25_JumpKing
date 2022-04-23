#pragma once

#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include "Menu.h"

//subclass optionMenu, an instance of Menu.
class OptionsMenu : public Menu
{
private:
	SDL_Rect Rect;
	SDL_Rect SetKey;

	bool inSetKey, resetSetKey;
	bool escTo_mainMenu;
	
public:
	//Constructor.
	OptionsMenu(void);
	//Destructor.
	~OptionsMenu(void);

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