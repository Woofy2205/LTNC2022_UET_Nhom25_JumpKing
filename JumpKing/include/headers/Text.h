#pragma once

#ifndef TEXT_H
#define TEXT_H

#include"header.h"
#include"image.h"

using namespace std;

class Text {
private:
	Image* Font;
	SDL_Rect Crop;
	SDL_Rect Rect;

	int fontSize;
	int xLeft, xtraLeft;

	int getPosition(int num);
	void checkExtra(int num);
public:
	//Constructors.
	Text(void);
	//Destructors.
	~Text(void);

	//Functions.
	void Draw(SDL_Renderer* renderer, string text, int x, int y, int fontSize = 16);
	void Draw(SDL_Renderer* renderer, string text, int x, int y, int fontSize, set<int, int, int> RGB);
	void DrawCenterX(SDL_Renderer* renderer, string text,
		int x, int y, int fontSize = 16,
		int r = 255, int g = 255, int b = 255);
	void Draw(SDL_Renderer* renderer, string text, int x, int y, int w, int h);
	void DrawWS(SDL_Renderer* renderer, string text, int x, int y, int r, int g, int b, int fontSize = 16);

	//Getters and Setters.
	int getTextWidth(string text, int fontSize = 16);
	void setFont(SDL_Renderer* renderer, string path);
};

#endif