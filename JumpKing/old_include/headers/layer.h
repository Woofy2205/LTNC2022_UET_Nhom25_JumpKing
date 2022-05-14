#pragma once

#ifndef LAYER_H
#define LAYER_H


class layer {
private:
	int blockID;
	int num;
	int pos;
	
	//after each level, mainChar is cleansed.
	//no effects from previous levels will be active on our mainChar.

	bool blockAnimation;

	//boolean direction with 2 value: 1 = up, 2 = down.
	bool direction;


public:
	//Constructor.
	layer(void);
	layer(int blockID);
	//Destructor.
	~layer(void);
	

	//Methods.
	void startBlockAnimation();
	int updatePos();

	//Getters and Setters.
	int getBlockID();
	void setBlockID(int blockID);
	int getPos();
	int getNum();
	void setNum(int num);
};

#endif


