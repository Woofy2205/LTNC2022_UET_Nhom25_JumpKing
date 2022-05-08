#pragma once
#ifndef MENUOPTION_H
#define MENUOPTION_H

#include<bits/stdc++.h>

using namespace std;

class menuOption {
private:
	string text;
	int x;
	int y;
public:
	//Constructors.
	menuOption(string text, int x, int y);
	//Destructors.
	~menuOption(void);
	//Getters and Setters.
	string getText();
	int getX();
	int getY();

	void setText(string text);

};

#endif