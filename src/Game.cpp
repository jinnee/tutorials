#include "../include/Game.h"

Game::Game():SpriteManager()
{
    mSdlApplication = new SdlApplication();
    isCursorInWindow = false;
    done =false;
    thisTime = 0.0;
    lastTime = 0.0;
    deltaTime = 0.0;
}

Game::~Game() {
    SDL_FreeSurface(screen);
    mSdlApplication->close();
}

SDL_PixelFormat* Game::getPixelFormat() {
    return mSdlApplication->getPixelFormat();
}

void Game::setTitle(char* title) {
    this->title = title;
    mSdlApplication->setTitle(this->title);
}

void Game::start(int sw, int sh){
    mSdlApplication->setTitle("SDL Application");
    mSdlApplication->setWindowSize(sw, sh);
    mSdlApplication->init();
    mSdlApplication->create();
    screen = mSdlApplication->getSurface();
    window = mSdlApplication->getWindow();

    ImageInstruments::setPixelFormat(this->getPixelFormat());

    this->init();
    done = false;
    // цикъл на играта
    while (!done)
    {
        this->g_events();
        this->g_update();
        this->g_render();
    } // край цикъл не играта
    // освобождаване на ресурси,
    this->freeResources();
}

// обработка на съобщенията
void Game::g_events() {
    //има отношение към натоваренноста на процесора
    SDL_Delay(20);
    // прихващане на съобщенията
    while (SDL_PollEvent(&event)) {
        int vectorOfSpritesSize = vectorOfSprites.size();

        for (int i = 0; i < vectorOfSpritesSize; i++) {
            // кое е съобщението
            switch (event.type)
            {
                case SDL_MOUSEMOTION:
                    old_mouse_x = event.motion.xrel;
                    old_mouse_y = event.motion.yrel;
                    mouse_x = event.motion.x;
                    mouse_y = event.motion.y;

                    if ( vectorOfSprites[i]->getType() == Constants::SpriteTypes::MOUSE_CURSOR ) {
                        vectorOfSprites[i]->setPosition(mouse_x, mouse_y);
                    }
                    if (vectorOfSprites[i]->getType() != Constants::SpriteTypes::BACKGROUND) {
                        vectorOfSprites[i]->setMousePosXY(mouse_x, mouse_y);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT) {
                        if (vectorOfSprites[i]->getName() == SpriteManager::mouseEventFrom  ) {
                            vectorOfSprites[i]->setMouseButtonDown(true);
                            vectorOfSprites[i]->setMousePosXY(event.button.x, event.button.y);
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if(event.button.button == SDL_BUTTON_LEFT) {
                        if (vectorOfSprites[i]->getName() == SpriteManager::mouseEventFrom) {
                            vectorOfSprites[i]->setMouseButtonDown(false);
                            vectorOfSprites[i]->setMousePosXY(event.button.x, event.button.y);
                        }
                    }
                    break;
                case SDL_MOUSEWHEEL:
                    break;
                case SDL_WINDOWEVENT:
                    switch (event.window.event) {
                        case SDL_WINDOWEVENT_LEAVE:
                            isCursorInWindow = false;
                            break;
                        case SDL_WINDOWEVENT_ENTER:
                            isCursorInWindow = true;
                            break;
                        default:
                            break;
                     }
                    break;
                // Изход при затваряне на прозореца
                case SDL_QUIT:
                    done = true;
                    break;
                default:
                    vectorOfSprites[i]->setMouseButtonDown(false);
                    break;
            } // край на switch
        } // край на for

        // ако нямаме въведени спрайтове
        if (vectorOfSpritesSize == 0) {
            if (event.type == SDL_QUIT) {
                done = true;
            }
        }
    } // край на обработка на съобщенията
}

void Game::g_update() {
    lastTime = thisTime;
    thisTime = SDL_GetTicks();
    deltaTime = (thisTime - lastTime) / 1000.0;
    this->update(deltaTime);
}

void Game::g_render() {
        // изчистване на екрана
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
        //виртуална функция - изпълнява се в класа наследяващ Game
        this->render();
        // update на екрана
        SDL_UpdateWindowSurface( window );
}

void Game::setDone(bool done) {
    this->done = done;
}

void Game::setWindowSize(int w,int h) {
    this->mSdlApplication->setWindowSize(w, h);
}

int Game::getWidth() {
    return mSdlApplication->getWidth();
}

int Game::getHeight() {
    return mSdlApplication->getHeight();
}
