#include"material.h"

//Constructors.
Material::Material(void) {
}

Material::Material(SDL_Renderer* renderer, vector<string> tMaterial, vector<int> imgDelay, bool rotate) {
	this->imgDelay = imgDelay;
	this->rotate = rotate;

	this->imgCurrentFrame = 0;
	this->imgEndingFrame = (int)tMaterial.size() - 1;
	this->imgStartingFrame = 0;

	for (int i = 0; i < this->imgEndingFrame + 1; i++) {
		this->tMaterial.push_back(new Image(tMaterial[i], renderer));
	}

	this->timeTracker = 0;
}

Material::~Material(void) {
	for (vector<Image*>::iterator i = tMaterial.begin(); i < tMaterial.end(); i++) {
		delete(*i);
	}
}

void Material::Update() {
	if (SDL_GetTicks64() - imgDelay[imgCurrentFrame] > timeTracker) {
		timeTracker = (int)SDL_GetTicks64();
		if (imgCurrentFrame == imgEndingFrame) {
			imgCurrentFrame = 0;
		}
		else {
			imgCurrentFrame++;
		}
	}
}

Image* Material::getImg() {
	return tMaterial[imgCurrentFrame];
}

Image* Material::getImg(int imageID) {
	return tMaterial[imageID];
}