#pragma once

#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
private:
	int x, y;

public:
	//Constructor.
	Vector(void);
	Vector(int x, int y);
	//Destructor.
	~Vector(void);

	//Getters and Setters.
	int getX();
	void setX(int X);
	int getY();
	void setY(int Y);
};

#endif