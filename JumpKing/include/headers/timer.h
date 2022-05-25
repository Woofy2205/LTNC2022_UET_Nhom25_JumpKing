#pragma once
#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include "header.h"
#include <iostream>
#include <string>
#include <stdio.h>
class Timer
{
public:
	// constructor and destructor
	Timer() { start = 0; }
	~Timer(){}

	// function to set, reset and get the final time
	void setTime();
	void reset();
	int getTimeElapsed();

private:
	// start time = 0
	int start;
};


#endif