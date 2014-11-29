#ifndef IMAGENSTRUMENTS_H
#define IMAGENSTRUMENTS_H

#include <cstdlib>
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <map>
#include <SDL2/SDL_image.h>

#include <iostream>
using namespace std;
#include "Constants.h"
#include "Functions.h"

class ImageInstruments
{
public:
    ImageInstruments();
    virtual ~ImageInstruments();
    SDL_Surface* getImage();
    void setImage(string);
    void setImage(SDL_Surface*);
    static void setPixelFormat(SDL_PixelFormat* pixelFormat) {
        pixFormat = pixelFormat;
    }
protected:
    SDL_Surface* image;
private:
    static SDL_PixelFormat* pixFormat;
};

#endif // IMAGENSTRUMENTS_H
