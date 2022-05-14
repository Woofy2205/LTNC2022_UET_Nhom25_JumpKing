#include"textControl.h"
#include"config.h"

using namespace std;


//Constructor
TextControl :: TextControl(void){
    //Rectangle to crop the text to
    Crop.x = 0;
    Crop.y = 0;
    Crop.h = 4;
    Crop.w = 4;

    //Rectangle 
    Rect.x = 0;
    Rect.y = 0;
    Rect.h = 8;
    Rect.w = 8;

    this->fontSize = 8;
    this->xLeft = 0;
    this->next_xLeft = 0;
}

//Destructor
TextControl :: ~TextControl(void){
    delete Font;
}

//private function
int TextControl :: getPosition(int num){
    if (num >= 43 && num < 91) {
        checkExtra(num);
        return (num - 43) * Crop.w + Crop.w;
    }

    if (num >= 118 && num < 123) { // v w x y z
        return (num - 70) * Crop.w + Crop.w;
    }

    return 0;
}

void TextControl :: checkExtra(int num){
    switch (num) {
    case 44: case 46: case 58: case 59:
        next_xLeft += 4 * fontSize / Rect.w;
        break;
    }
}

//Draw function (write actually)
void TextControl::Draw(SDL_Renderer* renderer, string text, int x, int y, int fontSize) {
    this->fontSize = fontSize;
    this->xLeft = 0;
    this->next_xLeft = 0;

    for (int i = 0; i < text.size(); i++) {
        Crop.x = getPosition(text.at(i));
        Rect.x = x + fontSize * i - xLeft;
        Rect.y = y;
        Rect.w = fontSize;
        Rect.h = fontSize;
        Font->Draw(renderer, Crop, Rect);
        xLeft += next_xLeft;
        next_xLeft = 0;
    }
}

void TextControl::Draw(SDL_Renderer* renderer, string text, int x, int y, int fontSize, int r, int g, int b) {
    this->fontSize = fontSize;
    this->xLeft = 0;
    this->next_xLeft = 0;

    for (int i = 0; i < text.size(); i++) {
        SDL_SetTextureColorMod(Font->getImg(), r, g, b);
        Crop.x = getPosition(text.at(i));
        Rect.x = x + fontSize * i - xLeft;
        Rect.y = y;
        Rect.w = fontSize;
        Rect.h = fontSize;
        Font->Draw(renderer, Crop, Rect);
        xLeft += next_xLeft;
        next_xLeft = 0;
        SDL_SetTextureColorMod(Font->getImg(), 255, 255, 255);
    }
}

void TextControl :: Draw(SDL_Renderer* renderer, string text, int x, int y, int _width, int _height){
    for (int i = 0; i < text.size(); i++) {
        Crop.x = getPosition(text.at(i));

        Rect.x = x + fontSize * i - xLeft;
        Rect.y = y;
        Rect.w = _width;
        Rect.h = _height;
        Font->Draw(renderer, Crop, Rect);
    }
}




void TextControl :: DrawCenterX(SDL_Renderer* renderer, string text, int y, int fontSize, int r, int g, int b){

    int x = config :: gameWidth / 2 - getTextWidth(text, fontSize) / 2;
	Draw(renderer, text, x, y, fontSize, r, g, b);
}

//Getters and Setters
int TextControl :: getTextWidth(string text, int fontSize){
    int res = (int)text.size() * fontSize;
    next_xLeft = 0;

    for (unsigned int i = 0; i < text.size(); i++) {
        checkExtra(text.at(i));
    }

    res -= next_xLeft;

    return res;
}

//Getters and Setters
void TextControl :: setFont(SDL_Renderer* renderer, string path){
    Font = new Image (path, renderer);
}
