#include "Timer.h"

// set time = the real miliseconds SDL lib begin to initialize
void Timer::setTime() {
	start = SDL_GetTicks();
}

// get the real time elapsed
int Timer::getTimeElapsed() {
	return SDL_GetTicks() - start;
}