// control sfx, menu manager, text we will use later on
#pragma once

#ifndef CFG_H
#define CFG_H

#include<bits/stdc++.h>
#include"menuManagement.h"
#include"TextControl.h"

using namespace std;

class config{
private:
    static menuManagement* menu_management;
    static TextControl* text_control;
    static Image* gameLogo;
    // Music* gameMusic;
public:
    static int gameWidth, gameHeight;       //what do i note here it's too obvious
    static bool pressSpace;                 //Space pressed?
    static int keyID_A, keyID_S, keyID_D, keyID_Space, keyID_Shift;
    static bool moveBack;
    
    //Constructor
    config(void);

    //Destructor
    ~config(void);

    //Functions
    static string getKey(int keyID);

    //Getters and Setters
	static Image* getLogo();
	static TextControl* getText();
	static menuManagement* getMenuManagement();
	// static Music* getMusic();

};

#endif


