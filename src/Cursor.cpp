#include "../include/Cursor.h"

Cursor::Cursor(string &pathCursor): AnimatedSprite() {
    SDL_ShowCursor(0);
    type = Constants::SpriteTypes::MOUSE_CURSOR;
    name = "MouseCursor";
    setX(0);
    setY(0);
    this->pathCursor = pathCursor;
    setImage(this->pathCursor);
}

Cursor::~Cursor() {
    //dtor
}

void Cursor::changeCursor(string &pathCursor) {
    SDL_FreeSurface(this->getImage());
    this->pathCursor = pathCursor;
    setImage(pathCursor);
}

void Cursor::render(SDL_Surface* screen) {
    StaticSprite::render(screen);
}
