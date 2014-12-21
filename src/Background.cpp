#include "../include/Background.h"

Background::Background() : StaticSprite()
{
    type = Constants::SpriteTypes::BACKGROUND;
    name = "background";
    setX(0);
    setY(0);
}

Background::~Background()
{
    //dtor
}

void Background::render(SDL_Surface* screen) {
    if ( this->isCursorInSprite() ) {
        SpriteManager::mouseEventFrom = this->getName();
        StaticSprite::render(screen);
    } else {
        StaticSprite::render(screen);
    }
}
