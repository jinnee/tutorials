#ifndef GAME15_H
#define GAME15_H

#include "../include/SpriteManager.h"
#include "../include/AbstractGame.h"
#include "../include/AnimatedSprite.h"
#include "../include/Button.h"
#include "../include/Background.h"
#include "FConstants.h"
#include "GameState.h"

class Game15 : public AbstractGame {
public:
    Game15(SDL_Surface* screen);

    void init();
    void render();
    void update(double deltaTime);
    void freeResources();
    void setSurface(SDL_Surface* screen);

    virtual ~Game15();
private:
    Button* btnToMainMenu;
    Button* btnNewGame;
    Button* btnRestartGame;
    Background* mBackground;
    SDL_Surface* screen;
    int buttonsTopMenu;
    int buttonsLeftMargin;
    int buttonsHeight;
    int buttonsDistance;
};


#endif // GAME15_H
