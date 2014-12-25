#ifndef FIFTEENGAME_H
#define FIFTEENGAME_H

#include "../include/Game.h"
#include "FConstants.h"
#include "GameState.h"
#include "Game15.h"

class FifteenGame : public Game {
public:
    void init();
    void update(double deltaTime);
    void render();
    void freeResources();

    FifteenGame();
    ~FifteenGame();
private:
    Background* background;
    string cursor_ladybug;
    bool cursor_flag;
    Cursor* cursor;
    AnimatedSprite* sparks;
    Button* btnExitGame;
    Button* btnGoGame;
    Button* btnAboutGame;
    // урок 2 - шрифт за заглавието
    BmpFont* bmpFont;
    // урок 2 - заглавие на играта
    LineText* titleText;
    // урок 2 - прозорче с информация за играта
    TextMessage* aboutTextMessage;
    // урок 2 - шрифт за текста в aboutTextMessage
    BmpFont* bmpFont14;
    // урок 2 - клас на дъската
    Game15* mGame15;
};

#endif // FIFTEENGAME_H
