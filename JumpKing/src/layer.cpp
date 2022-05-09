#include"layer.h"

using namespace std;

//Constructor
layer :: layer(void){

}

layer :: layer(int blockID){
    this->blockID = blockID;
    this->num = 0;
    this->pos = 0;
    this->blockAnimation = false;
    this->direction = true;
}

//Destructor
layer :: ~layer(void){

}

//Methods
void layer :: startBlockAnimation(){
    this->blockAnimation = true;
    this->direction = true;
    this->pos = 0;
}

int layer :: updatePos(){
    //something i dont really inderstand
	if (blockAnimation) {
		if (direction){
			if (pos < 10){
				if (pos < 5) {
					pos += 2;
				}
				else {
					pos ++;
				}
			}
			else {
				direction = false;
			}
		}
		else {
			if (pos > 0) {
				if (pos > 5) {
					pos -= 2;
				}
				else {
					pos -= 1;
				}
			}
			else {
				blockAnimation = false;
			}
		}
	}
    return pos;
}

//Getters and Setters
int layer :: getBlockID(){
    return blockID;
}

void layer :: setBlockID(int blockID){
    this->blockID = blockID;
}

int layer :: getPos(){
    return pos;
}

int layer :: getNum(){
    return num;
}

void layer :: setNum(int num){
    this->num = num;
}

