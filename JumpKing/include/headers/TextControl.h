#pragma once

#ifndef TEXT_H
#define TEXT_H

#include"header.h"
#include"image.h"

using namespace std;

class TextControl {
private:
	Image* Font;
	SDL_Rect Crop;
	SDL_Rect Rect;

	int fontSize;
	int xLeft, next_xLeft;

	int getPosition(int num);
	void checkExtra(int num);
public:
	//Constructors.
	TextControl(void);
	//Destructors.
	~TextControl(void);

	//Functions.
	void Draw(SDL_Renderer* renderer, string text, int x, int y, int fontSize = 16);
	void Draw(SDL_Renderer* renderer, string text, int x, int y, int fontSize, int r, int g, int b);
	void DrawCenterX(SDL_Renderer* renderer, string text, int y, int fontSize = 16, int r = 255, int g = 255, int b = 255);
	void Draw(SDL_Renderer* renderer, string text, int x, int y, int _width, int _height);
	void DrawWS(SDL_Renderer* renderer, string text, int x, int y, int r, int g, int b, int fontSize = 16);

	//Getters and Setters.
	int getTextWidth(string text, int fontSize = 16);
	void setFont(SDL_Renderer* renderer, string path);
};

#endif

