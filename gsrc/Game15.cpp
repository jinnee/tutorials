#include "Game15.h"

Game15::Game15(SDL_Surface* screen) {
    this->screen = screen;
}

void Game15::setSurface(SDL_Surface* screen) {
    this->screen = screen;
}

void Game15::init() {
    btnToMainMenu = new Button();
    btnToMainMenu->setX(377+11);
    btnToMainMenu->setY(10+31+5+31+5);
    btnToMainMenu->setTilesXY(1,2);
    btnToMainMenu->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "toMainMenu.png");
    btnToMainMenu->setName("btnToMainMenu");
    SpriteManager::addSprite(btnToMainMenu);

    btnNewGame = new Button();
    btnNewGame->setX(377+11);
    btnNewGame->setY(10);
    btnNewGame->setTilesXY(1,2);
    btnNewGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "newGame.png");
    btnNewGame->setName("btnNewGame");
    SpriteManager::addSprite(btnNewGame);

    btnRestartGame = new Button();
    btnRestartGame->setX(377+11);
    btnRestartGame->setY(10+31+5);
    btnRestartGame->setTilesXY(1,2);
    btnRestartGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "restart.png");
    btnRestartGame->setName("btnRestartGame");
    SpriteManager::addSprite(btnRestartGame);

    mBackground = new Background();
    mBackground->setName("background_board");
    mBackground->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "board.png");
    SpriteManager::addSprite(mBackground);
}

void Game15::render() {
    if( GameState::inGame == 1 ) {
        mBackground->render(screen);
        btnToMainMenu->render(screen);
        btnNewGame->render(screen);
        btnRestartGame->render(screen);

        if (btnToMainMenu->isMouseButtonDown()) {
            GameState::inGame = 0;
            delete mBackground;
            delete btnToMainMenu;
            delete btnNewGame;
            delete btnRestartGame;

            SpriteManager::deleteSprite("background_board");
            SpriteManager::deleteSprite("btnToMainMenu");
            SpriteManager::deleteSprite("btnNewGame");
            SpriteManager::deleteSprite("btnRestartGame");
        }
    }
}

void Game15::update(double deltaTime) {
}

void Game15::freeResources() {

}

Game15::~Game15() {

    if(mBackground) {
        delete mBackground;
        mBackground = 0;
    }

    if(btnToMainMenu) {
        delete btnToMainMenu;
        btnToMainMenu = 0;
    }
    if(btnNewGame) {
        delete btnNewGame;
        btnNewGame = 0;
    }
    if(btnRestartGame) {
        delete btnRestartGame;
        btnRestartGame = 0;
    }
    cout << "delete Game15" << endl;

}

