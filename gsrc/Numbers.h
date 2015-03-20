#ifndef NUMBERS_H
#define NUMBERS_H

#include <algorithm>
#include "../include/AnimatedSprite.h"

class Numbers
{
public:
    Numbers();
    ~Numbers();
    void setSurface(SDL_Surface* screen);
    void render();
    void newGame();
private:
    enum DIRECTIONS {
        LEFT = 1, RIGHT, TOP, BOTTOM
    } mDirections;

    int startX;
    int startY;
    int numberWidth;
    int numberHeight;
    int* modelNumbers;

    SDL_Surface* screen;
    AnimatedSprite* objectNumbers;
    AnimatedSprite* number;
    vector<AnimatedSprite*> vectorOfNumbers;

    int* getNumberOrder();
    int moveDecision(int);
};

#endif // NUMBERS_H
