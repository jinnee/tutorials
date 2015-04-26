#ifndef NUMBERS_H
#define NUMBERS_H

#include <algorithm>
#include "../include/AnimatedSprite.h"

class Numbers
{
public:
    Numbers();
    ~Numbers();
    //
    void setSurface(SDL_Surface* screen);
    //
    void render();
    // започваме играта отначало
    void restartGame();
    // започваме нова игра
    void newGame();
private:
    // посоки на движение на плочка
    enum DIRECTIONS {
        LEFT = 1, RIGHT, TOP, BOTTOM
    } mDirections;

    // x позиция на първата плочка
    int tilePosX;
    // y позиция на първата плочка
    int tilePosY;
    // широчина на плочката
    int tileWidth;
    // височина на плочката
    int tileHeight;
    int* currentPositionOfNumbers;
    // Първоначална подредба
    int initialPosition[16];
    // Позицията към която се стремим
    int targetPosition[16];
    // повърхността върху която ще рисуваме
    SDL_Surface* screen;
    // използва се нулевата плочка
    AnimatedSprite* emptyTile;
    // обект, който използваме за попълване на vectorOfTiles
    AnimatedSprite* tile;
    // вектор съдържащ плочките
    vector<AnimatedSprite*> vectorOfTiles;

    // връща начална позиция
    int* getValidNumbersPosition();
    // преценява може ли да се премести дадена плочка и накъде
    int moveDecision(int);
    // инициализиране
    void clear();
    // попълва vectorOfTiles с данните от getNumberOrder
    void initVectorOfTiles(bool);
    // връща true, ако играта е достигнала крайна позиция
    bool isFinish(int*);
};

#endif // NUMBERS_H

