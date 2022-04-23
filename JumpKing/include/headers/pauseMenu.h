#pragma once

#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include<bits/stdc++.h>
#include"menu.h"

//subclass pauseMenu, an instance of Menu.
class pauseMenu : public Menu {
private:
	SDL_Rect pauseRect;
public:
	//Constructor.
	pauseMenu(void);
	//Destructor.
	~pauseMenu(void);

	/*
	* Functions.
	* Update, updateActiveButton and Draw are up-casting functions from virtual Menu::void.
	*/
	void Update();
	void Draw(SDL_Renderer* renderer);
	void enter();
	void escape();
	void updateActiveButton(int directory);
};

#endif