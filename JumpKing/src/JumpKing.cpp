#include "image.h"
#include "object.h"
#include "player.h"


using namespace std;


SDL_Window* window = SDL_CreateWindow("Jump King", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 360, 0);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

SDL_Event gE;

void close() {
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = NULL;
	IMG_Quit();
	SDL_Quit();

}

int main(int argc, char* args[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
	Image* background1 =new Image("image/background/bg4.png", renderer);
	Image* midground1 = new Image("image/background/1.png", renderer);
	Image* foreground1 = new Image("image/background/fg1.png", renderer);
	Image* potion1 =new Image("image/object/rsz_potion.png", renderer);
	Image* player = new Image("image/player/player1.png", renderer);
	Object pot1 = Object(39, 26);
	King king = King(50, 50);
	bool is_quit = false;
	while (!is_quit) {
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&gE)) {
			if (gE.type == SDL_QUIT) {
				is_quit = true;
			}
			king.handleEvents(gE);
		}
		king.move();
        SDL_RenderClear(renderer);
        background1->Draw(renderer, 0, 0);
		midground1->Draw(renderer, 0, 0);
		foreground1->Draw(renderer, 0, 0);

		if (pot1.collideWithCharacter(pot1.objRect, king.destRect) == false)
			pot1.Draw(renderer, potion1);
		else pot1.isTouched = true;
		
        king.Draw(renderer, player);
        SDL_RenderPresent(renderer);
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	close();
    return 0;
}