#include "../include/ImageInstruments.h"

ImageInstruments::ImageInstruments() {
    image = NULL;
}

void ImageInstruments::setImage(string filename) {
    SDL_Surface* loadedSurface = IMG_Load(filename.c_str());

    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", filename.c_str(), IMG_GetError());
    } else {
        SDL_SetColorKey(loadedSurface, SDL_RLEACCEL|SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0));
        image = SDL_ConvertSurface(loadedSurface, pixFormat, 0);
        if (image == NULL) {
            printf("Unable to optimize image %s! SDL Error: %s\n", filename.c_str(), SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }
}

void ImageInstruments::setImage(SDL_Surface* image) {
    this->image = image;
}

SDL_Surface* ImageInstruments::getImage() {
    return image;
}

ImageInstruments::~ImageInstruments() {
}

SDL_PixelFormat* ImageInstruments::pixFormat = NULL;
