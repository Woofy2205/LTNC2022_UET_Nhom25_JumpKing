#include"block.h"

Block::Block(void) {
}

//Constructor.
Block::Block(int blockID, Material* materials, bool blockCollision, bool blockDeath, bool blockUse, bool blockVisible) {
	this->blockID = blockID;
	this->blockCollision = blockCollision;
	this->blockDeath = blockDeath;
	this->blockUse = blockUse;
	this->blockVisible = blockVisible;
	this->materials = materials;
}

//Destructor.
Block::~Block(void) {
	delete materials;
}

//Functions.
void Block::Draw(SDL_Renderer* renderer, int x, int y) {
	materials->getImg()->Draw(renderer, x, y);
}

//Getters and Setters.
int Block::getBlockID() {
	return blockID;
}

bool Block::getCollision() {
	return blockCollision;
}

bool Block::getDeath() {
	return blockDeath;
}

bool Block::getUse() {
	return blockUse;
}

bool Block::getVisible() {
	return blockVisible;
}

Material* Block::getMaterial() {
	return materials;
}

void Block::setBlockID(int ID) {
	this->blockID = ID;
}