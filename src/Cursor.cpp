#include "../include/Cursor.h"

/**
 * Смяна на курсора
 * @brief Cursor::changeCursor
 * @param pathCursor
 */
void Cursor::changeCursor(string &pathCursor) {
    // освобождаваме старата картинка
    SDL_FreeSurface(this->getImage());
    this->pathCursor = pathCursor;
    // зареждаме новата
    setImage(pathCursor);
}

void Cursor::render(SDL_Surface* screen) {
    // показване
    StaticSprite::render(screen);
}


Cursor* Cursor::getCursor() {
    if (cursor == 0) {
        return cursor = new Cursor();
    }
    return cursor;
}

/**
 * Вземаме инстанция на курсора
 * @brief Cursor::Cursor
 */
Cursor::Cursor(): AnimatedSprite() {
    // скриваме стандартният курсор
    SDL_ShowCursor(0);
    type = Constants::SpriteTypes::MOUSE_CURSOR;
    name = "MouseCursor";
    // позициянираме го в горният ляв ъгъл на играта ни
    setX(0);
    setY(0);
    if (Cursor::pathCursor != "") {
        // зареждаме
        setImage(Cursor::pathCursor);
    }
}

void Cursor::setPath(string &pathCursor) {
    Cursor::pathCursor = pathCursor;
}

Cursor::~Cursor() {
    delete Cursor::cursor;
}

Cursor* Cursor::cursor = 0;
string Cursor::pathCursor = "";
