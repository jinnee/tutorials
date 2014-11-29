#ifndef FIFTEENGAME_H
#define FIFTEENGAME_H
#include <iostream>

#include "../include/Game.h"

using namespace std;
class FifteenGame : public Game {
public:
    void init();
    void update(double deltaTime);
    void render();
    void freeResources();

    FifteenGame();
    ~FifteenGame();
private:
};

#endif // FIFTEENGAME_H
