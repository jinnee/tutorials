#ifndef FIFTEENGAME_H
#define FIFTEENGAME_H
#include <iostream>

#include "../include/Game.h"
#include "../include/Background.h"

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
};

#endif // FIFTEENGAME_H
