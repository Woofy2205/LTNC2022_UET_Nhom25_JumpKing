#include"vector.h"

using namespace std;

//Constructors.
Vector::Vector(void) { 
}

Vector::Vector(int x, int y) {
	this->x = x;
	this->y = y;
}


//Destructor.
Vector::~Vector(void) { 
}


//Getters and Setters.
int Vector::getX() {
	return x;
}

void Vector::setX(int x) {
	this->x = x;
}

int Vector::getY() {
	return y;
}

void Vector::setY(int y) {
	this->y = y;
}