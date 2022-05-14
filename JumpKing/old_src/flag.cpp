#include "Flag.h"
#include "Core.h"

using namespace std;

/* ******************************************** */

Flag::Flag(int xPos, int yPos) {
	this->xPos = xPos;
	this->yPos = yPos;

	this->yTextPos = config::gameHeight - 3 * 32;
	this->points = -1;

	this->blockID = mainCore::getDungeon()->getLayerType() == 4 || mainCore::getDungeon()->getLayerType() == 3 ? 168 : 42;

	this->endFlagExtraXPos = this->endFlagY = 0;
}

Flag::~Flag(void) {

}


void Flag::Update() {
	yPos += 4;
	yTextPos -= 4;
}

void Flag::UpdateEndPointFlag() {
	if (endFlagY <= 56) endFlagY += 2;
}

void Flag::Draw(SDL_Renderer* renderer, Image* img) {
	img->Draw(renderer, (int)(xPos + mainCore::getDungeon()->getXPos()), yPos);

	if (points > 0) {
		config::getText()->Draw(renderer, to_string(points), (int)(xPos + mainCore::getDungeon()->getXPos() + 42),yTextPos - 22,8,16);
	}
}

void Flag::DrawEndPointFlag(SDL_Renderer* renderer, Image* img) {
	img->Draw(renderer, (int)(xPos + mainCore::getDungeon()->getXPos() + endFlagExtraXPos + 7 * 32 - 14), config::gameHeight + 14 - 6 * 32 - endFlagY);
}
