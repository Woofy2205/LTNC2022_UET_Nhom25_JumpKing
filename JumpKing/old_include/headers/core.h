#pragma once

#ifndef CORE_H
#define CORE_H

#include "dungeon.h"

class mainCore {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* event;

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

	static dungeon* Dungeon;

	void input();
	void mouseInput();
	void inputCharacter();
	void inputMenu();

public:

	//variables
	static bool mouseLeftClick;
	static bool mouseRightClick;
	static int mouseX, mouseY;

	//Constructor.
	mainCore(void);
	//Destructor.
	~mainCore(void);

	//main loop to start the game
	static bool quitGame;		//boolean for quitting the game.
	void mainLoop();			//main Loop for the whole game.

	//update the game state and controller
	void Update();
	void Draw();

	//resetkeys and moves
	void resetMove();			//(not sure)reset all moves to checkpoint.
	static void resetKeys();	//reset all custom changes to Keys.

	//Getter.
	static dungeon* getDungeon();
};

#endif

