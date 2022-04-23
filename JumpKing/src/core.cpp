#include "header.h"
#include "core.h"
#include "image.h"
#include "config.h"
#include "Text.h"
// #include "SDL_mixer.h"

//Global Initialization.

mapp* mainCore::Map = new mapp();
bool mainCore::mouseLeftClick = false;
int mainCore::mouseX = 0;
int mainCore::mouseY = 0;
bool mainCore::quitGame = false;

bool mainCore::movePressed = false;
bool mainCore::menuPressed = false;
bool mainCore::keyS = false;
bool mainCore::keyW = false;
bool mainCore::keyA = false;
bool mainCore::keyD = false;
bool mainCore::keyAPressed = false;
bool mainCore::keyDPressed = false;

//Constructor.
mainCore::mainCore(void) {
	this->quitGame = false;
	this->iFPS = 0;
	this->nFPS = 0;
	this->FPSTime = 0;
	SDL_Init(SDL_INIT_EVERYTHING);
}