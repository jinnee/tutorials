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

    // зареждаме курсора
    string cursor_path = FConstants::STANDART_CURSOR;
    Cursor::setPath(cursor_path);
    cursor = Cursor::getCursor();
    addSprite(cursor);

    // анимиран спрайт
    sparks = new AnimatedSprite();
    // показва геометрията на спрайта - 12 фрейма (кадъра) в в 1 ред
    sparks->setTilesXY(12, 1);
    // зареждаме картинката
    sparks->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "magicStars.png");
    // определяме име
    sparks->setName("sparks");
    // кои фреймове ще показваме
    sparks->setFrameBeginEnd(0, 12);
    // с каква скорост ще се показват фреймовете
    sparks->calculate(10);
    // разполагаме го в горният десен ъгъл на началният екран
    sparks->setX(getWidth() - sparks->getSpriteWidth() - 20);
    sparks->setY(20);
    // добавяме към SpriteManager
    addSprite(sparks);

    // бутон за излизане
    btnExitGame = new Button();
    btnExitGame->setTilesXY(1,2);
    btnExitGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "exitGame.png");
    btnExitGame->setName("btnExitGame");
    btnExitGame->setX((getWidth() - btnExitGame->getSpriteWidth())/2);
    int exitBtnBottom = getHeight() - btnExitGame->getSpriteHeight() - 25;
    btnExitGame->setY(exitBtnBottom);
    addSprite(btnExitGame);

    btnGoGame = new Button();
    btnGoGame->setTilesXY(1,2);
    btnGoGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "goGame.png");
    btnGoGame->setName("btnGoGame");
    btnGoGame->setX((getWidth() - btnGoGame->getSpriteWidth())/2);
    btnGoGame->setY(exitBtnBottom - 2*btnGoGame->getSpriteHeight() - 30);
    addSprite(btnGoGame);

    btnAboutGame = new Button();
    btnAboutGame->setTilesXY(1,2);
    btnAboutGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "aboutGame.png");
    btnAboutGame->setName("btnAboutGame");
    btnAboutGame->setX((getWidth() - btnAboutGame->getSpriteWidth())/2);
    btnAboutGame->setY(exitBtnBottom - btnAboutGame->getSpriteHeight() - 15);
    addSprite(btnAboutGame);

}

void FifteenGame::update(double deltaTime) {
    if (sparks) {
        sparks->update(deltaTime);
    }
}

void FifteenGame::render() {
    // показваме
    background->render(screen);
    sparks->render(screen);
    btnExitGame->render(screen);
    btnGoGame->render(screen);
    btnAboutGame->render(screen);
    cursor->render(screen);
}

void FifteenGame::freeResources() {
}

FifteenGame::~FifteenGame() {
    background = 0;
    delete background;
    cursor = 0;
    delete cursor;
    sparks = 0;
    delete sparks;
    btnExitGame = 0;
    delete btnExitGame;
    btnGoGame = 0;
    delete btnGoGame;
    btnAboutGame = 0;
    delete btnAboutGame;
}

