#include "../include/Cursor.h"

void Cursor::changeCursor(string &pathCursor) {
    SDL_FreeSurface(this->getImage());
    this->pathCursor = pathCursor;
    setImage(pathCursor);
}

void Cursor::render(SDL_Surface* screen) {
    StaticSprite::render(screen);
}

Cursor* Cursor::getCursor() {
    if (cursor == 0) {
        return cursor = new Cursor();
    }
    return cursor;
}

Cursor::Cursor(): AnimatedSprite() {
    SDL_ShowCursor(0);
    type = Constants::SpriteTypes::MOUSE_CURSOR;
    name = "MouseCursor";
    setX(0);
    setY(0);
    if (Cursor::pathCursor != "") {
        setImage(Cursor::pathCursor);
    }
}

void Cursor::setPath(string &pathCursor) {
    Cursor::pathCursor = pathCursor;
}

Cursor::~Cursor() {
}

Cursor* Cursor::cursor = 0;
string Cursor::pathCursor = "";
