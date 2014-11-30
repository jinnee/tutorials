#include <dirent.h>
#include <stdio.h>

#include "FifteenGame.h"

FifteenGame::FifteenGame() {

}

void FifteenGame::init() {
    this->setTitle("Игра 15");

    // създаваме си обекта background
    background = new Background();
    // зареждаме картинката
    background->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "background.png");
    // прибавяме към SpriteManager - Game наследява SpriteManager
    addSprite(background);
}

void FifteenGame::update(double deltaTime) {
}

void FifteenGame::render() {
    // показваме
    background->render(screen);
}

void FifteenGame::freeResources() {
}

FifteenGame::~FifteenGame() {
    // премахваме обекта
    delete background;
}

