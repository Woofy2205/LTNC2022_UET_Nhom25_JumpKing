#pragma once

#ifndef CORE_H
#define CORE_H

#include "map.h"

class mainCore {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* e;

	// Frames.
	long frameTime;
	static const int minFrameTime = 16;
	long FPSTime;
	int nFPS, iFPS;

	// Controller.
	static bool movePressed;	//generalization for detecting active controlling key.
	static bool menuPressed;	//same idea for generalization as above, I think.
	static bool keyS, keyW, keyA, keyD;
	//keyShift is removed since jumpKing doesn't dash.
	//Because A, D is the main controller while S, W only take part in Menu's up and down,
	//we created 2 exclusive boolean below for smooth and friendly control of character's movement.
	static bool keyAPressed, keyDPressed;
	//while true = RIGHT, false = LEFT (IMPORTANT!)
	//.

	bool firstDir;				//Previous direction of moving, maybe remove after overall reviewing.

	static mapp* Map;

	void input();
	void mouseInput();
	void inputCharacter();
	void inputMenu();

public:
	//Constructor.
	mainCore(void);
	//Destructor.
	~mainCore(void);

	static bool quitGame;	//boolean for quitting the game.
	void mainLoop();		//main Loop for the whole game.

	void Update();
	void Draw();

	void resetMove();		//(not sure)reset all moves to checkpoint.
	static void resetKeys();//reset all custom changes to Keys.

	static bool mouseLeftClick;
	static int mouseX, mouseY;
	//Getter.
	static mapp* getMap();
};

#endif