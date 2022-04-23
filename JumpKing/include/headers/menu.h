#pragma once

#ifndef MENU_H
#define MENU_H

#include<bits/stdc++.h>
#include"header.h"
#include"menuOption.h"

using namespace std;

class Menu {
public:
	//Constructor.
	Menu(void);
	//Destructor.
	~Menu(void);

	vector<menuOption*> menuOptionList;

	int menuOptionAct;
	int menuOptionCnt;

	//abstract functions.
	virtual void Update();
	virtual void Draw(SDL_Renderer* renderer);

	virtual void updateActiveButton(int directory);
};

#endif