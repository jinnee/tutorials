#include "../include/SdlApplication.h"

SdlApplication::SdlApplication() {
    this->title = "Application";
    this->width = 640;
    this->height = 480;
    this->appWindow = NULL;
    this->imageFlags = IMG_INIT_PNG;
}

SdlApplication::~SdlApplication() {
}

bool SdlApplication::init() {
    //инициализиране на SDL
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0) {
        return false;
    } else {
	if (!(IMG_Init(imageFlags) & imageFlags)) {
		return false;
	} else {
		return true;
	}
    }
}

void SdlApplication::create() {
    //Установяване на видео режима
    this->appWindow = SDL_CreateWindow(this->title // заглавие на прозореца
            // x координата на прозореца.
            // Освен SDL_WINDOWPOS_UNDEFINED може да се използва конкратно число или SDL_WINDOWPOS_CENTERED
            , SDL_WINDOWPOS_UNDEFINED
            // y координата на прозореца.
            , SDL_WINDOWPOS_UNDEFINED
            , this->width // ширина на екрана
            , this->height // височина на екрана
            // флагове определящи характеристики на прозореца
            // пълният списък може да се види тук https://wiki.libsdl.org/SDL_CreateWindow#flags
            , SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
            );

}

void SdlApplication::close() {
    SDL_DestroyWindow(this->appWindow);
    this->appWindow = NULL;
    SDL_Quit();
}

void SdlApplication::setTitle(char* title) {
    this->title = title;
    SDL_SetWindowTitle(this->appWindow, title);

}

void SdlApplication::setWindowSize(int w, int h) {
    this->width = w;
    this->height = h;
    SDL_SetWindowSize(this->appWindow, w, h);
}

SDL_PixelFormat* SdlApplication::getPixelFormat() {
    return SDL_GetWindowSurface(this->appWindow)->format;
}

SDL_Surface* SdlApplication::getSurface() {
    return SDL_GetWindowSurface(this->appWindow);
}

SDL_Window* SdlApplication::getWindow() {
    return this->appWindow;
}
