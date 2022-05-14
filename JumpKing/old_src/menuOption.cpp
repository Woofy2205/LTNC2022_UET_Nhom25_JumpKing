#include"menuOption.h"
using namespace std;

//Constructors.
menuOption::menuOption(string text, int x, int y) {
	this->text = text;
	this->x = x;
	this->y = y;
}

menuOption::~menuOption(void) {
	
}

string menuOption::getText() {
	return this->text;
}

int menuOption::getX() {
	return this->x;
}

int menuOption::getY() {
	return this->y;
}

void menuOption::setText(string text) {
	this->text = text;
}

