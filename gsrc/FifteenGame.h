#ifndef FIFTEENGAME_H
#define FIFTEENGAME_H

#include "../include/Game.h"
#include "FConstants.h"

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
};

#endif // FIFTEENGAME_H
