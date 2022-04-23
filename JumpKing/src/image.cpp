#include"image.h"

Image::Image(void) {
}

Image::Image(string path, SDL_Renderer* renderer) {
	setImg(path, renderer);									//the setImg() will be cover later on
}

Image::~Image(void) {
	SDL_DestroyTexture(img);								//SDL func to delete the pointer ò SDL_Texture
}

//Functions.
void Image::Draw(SDL_Renderer* renderer, int _x, int _y) {
	imgRect.x = _x;
	imgRect.y = _y;
	SDL_RenderCopy(renderer, img, NULL, &imgRect);			//SDL func to copy a portion of texture to some target (here is the SDL_Rect but get the NULL value)
}

void Image::Draw(SDL_Renderer* renderer, int _x, int _y, bool rotate) {			//bool rotate to get the opinion (rotate or not)		
	imgRect.x = _x;
	imgRect.y = _y;
	// if u want to rotate the image
	if (rotate) {
		SDL_RenderCopyEx(renderer, img, NULL, &imgRect, 180.0, NULL, SDL_FLIP_VERTICAL);	//similar to RenderCopy but can flip the image
	}
	else {
		SDL_RenderCopy(renderer, img, NULL, &imgRect);										// if u dont want to -> similar to default one
	}
}

void Image::PpenDraw(SDL_Renderer* renderer, int _x, int _y) {
	imgRect.x = _x;
	imgRect.y = _y;

	SDL_RenderCopyEx(renderer, img, NULL, &imgRect, 180.0, NULL, SDL_FLIP_HORIZONTAL);		//similar to the above mentioned but flip to horizontal
}

void Image::Draw(SDL_Renderer* renderer, SDL_Rect frame, SDL_Rect crop) {
	SDL_RenderCopy(renderer, img, &crop, &frame);
}

/*
* Getters and Setters.
*/

void Image::setImg(string path, SDL_Renderer* renderer) {
	path = "files/images/" + path + ".bmp";
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());										//IMG_Load is just a function to load the image to a surface
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));

	img = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	int iWidth, iHeight;

	SDL_QueryTexture(img, NULL, NULL, &iWidth, &iHeight);

	imgRect.x = 0;
	imgRect.y = 0;
	imgRect.w = iWidth;
	imgRect.h = iHeight;
	SDL_FreeSurface(loadedSurface);							//delete the pointer of SDL_Surface
}

SDL_Texture* Image::getImg() {
	return this->img;							//simple af
}

SDL_Rect Image::getRect() {						//simple af
	return this->imgRect;
}