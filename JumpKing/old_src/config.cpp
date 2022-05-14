#include"config.h"

using namespace std;

//Constructor
config :: config(void){

}
//Destructor
config :: ~config(void){
    delete menu_management;
    delete text_control;
    delete gameLogo;
}

int config :: gameWidth = 1440;
int config :: gameHeight = 1080;

TextControl* config :: text_control = new TextControl();
Image* config :: gameLogo = new Image();
menuManagement* config :: menu_management = new menuManagement();
// Music* CCFG::oMusic = new Music();

//variables of boolean and interger
bool config :: pressSpace = false;

int config :: keyID_A = 0;
int config :: keyID_D = 0;
int config :: keyID_S = 0;
int config :: keyID_Space = 0;
int config :: keyID_Shift = 0;

bool config :: moveBack = false;

//Function to get the key from keyboard
string config :: getKey(int keyID){

    if(keyID >= 97 && keyID <= 122) {
		return string(1, '0' + (keyID - 32) - 48);
	}

	if(keyID >= 48 && keyID <= 57) {
		return string(1, '0' + (keyID - 32) - 48);
	}

	switch(keyID) {
		case SDLK_ESCAPE:
			return "ESCAPE";
		case SDLK_SPACE:
			return "SPACE";
		case SDLK_LSHIFT:
			return "LSHIFT";
		case SDLK_RSHIFT:
			return "RSHIFT";
		case SDLK_UP:
			return "UP";
		case SDLK_DOWN:
			return "DOWN";
		case SDLK_RIGHT:
			return "RIGHT";
		case SDLK_LEFT:
			return "LEFT";
		case SDLK_LCTRL:
			return "LCTRL";
		case SDLK_RCTRL:
			return "RCTRL";
    }
    return "NONE";
}

//Getters and Setters
TextControl* config::getText() {
	return text_control;
}

menuManagement* config :: getMenuManagement() {
	return menu_management;
}

Image* config :: getLogo() {
	return gameLogo;
}

// Music* CCFG::getMusic() {
// 	return oMusic;
// }
