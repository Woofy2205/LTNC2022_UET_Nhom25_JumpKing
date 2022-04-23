#pragma once

#ifndef MATERIAL_H
#define MATERIAL_H
#include<bits/stdc++.h>
#include"image.h"

using namespace std;

class Material {
private:
	//Declarations.
	vector<Image*> tMaterial;
	vector<int> imgDelay;

	bool rotate;
	int imgCurrentFrame;
	int imgStartingFrame;
	int imgEndingFrame;

	int timeTracker;

public:
	/*
	* Constructors.
	*/
	Material(void);
	Material(SDL_Renderer* renderer, vector<string> tMaterial, vector<int> imgDelay, bool rotate);
	/*
	* Destructors.
	*/
	~Material(void);

	//Functions.
	void Update();

	/*
	* Getters and Setters.
	*/
	Image* getImg();
	Image* getImg(int imageID);
};

#endif // !MATERIAL_H