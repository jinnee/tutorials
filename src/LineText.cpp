#include "../include/LineText.h"

LineText::LineText(): StaticSprite(){
    name = Constants::SpriteTypes::LINE_TEXT;
    type = Constants::SpriteTypes::LINE_TEXT;
    text = L"Line text";
    width = 0;
    height = 0;
    numberOfLetters = 0;
    this->setX(0);
    this->setY(0);
}

void LineText::setText(wstring text){
    this->text = text;
    numberOfLetters = text.length();
}

void LineText::setFont(BmpFont* bf)
{
    this->bmpFont = bf;

    this->width = this->bmpFont->getWidth();
    this->height = this->bmpFont->getHeight();
}

LineText::~LineText(){
    //dtor
}

void LineText::render(SDL_Surface* screen) {
    SDL_Rect src, dest;
    unsigned int textLength = (this->text).length();
    map<int, int> programFontMap = bmpFont->getFontMap();

    for (unsigned int i = 0; i < textLength; ++i)
    {
          src.x = (programFontMap[this->text[i]]) * this->width;
          src.y = 0;
          src.w = this->width;
          src.h = this->height;

          dest.x = this->position.x + (i * this->width);
          dest.y = this->position.y;
          dest.w = this->width;
          dest.h = this->height;

          SDL_BlitSurface(this->bmpFont->getImage(), &src, screen, &dest);
    }
}

int LineText::getHeight() {
    return bmpFont->getHeight();
}

int LineText::getWidth() {
    return bmpFont->getWidth() * numberOfLetters;
}
