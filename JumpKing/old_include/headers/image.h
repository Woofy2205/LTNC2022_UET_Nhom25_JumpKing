#pragma once

#ifndef IMAGE_H
#define IMAGE_H

#include<bits/stdc++.h>
#include"header.h"
using namespace std;


class Image {
private:
	SDL_Texture* img;					// pointer to some where that store the source texture (similar to some type of colors)
	SDL_Rect	 imgRect;				// the rectangle that we want to use Texture to paint on it

public:
	//Constructor.
	Image(void);
	Image(string path, SDL_Renderer* renderer);
	//Destructor.
	~Image(void);

	//Callout Functions.
	void Draw(SDL_Renderer* renderer, int x, int y);					//some type of creating a rectangle that contains every thing (picture, image)
	void Draw(SDL_Renderer* renderer, int x, int y, bool rotate);		//another draw func but it can rotate by the boolean var
	void PpenDraw(SDL_Renderer* renderer, int x, int y);				//some type of pen that can draw on other surfaces, it's useful, use to turn, flip object, kinda cool
	void Draw(SDL_Renderer* renderer, SDL_Rect frame, SDL_Rect crop);	//Draw image by cropping SDL_Rect crop from renderer to SDL_Rect frame.

	//Getters and Setters.
	SDL_Texture* getImg();												//return the img pointers of SDL_Texture type
	SDL_Rect getRect();													//return the rectangle we are rendering to
	void setImg(string str, SDL_Renderer* renderer);					//create a surface with some random images
};

#endif