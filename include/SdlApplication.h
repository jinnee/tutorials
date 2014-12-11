#ifndef SDLAPPLICATION_H
#define	SDLAPPLICATION_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class SdlApplication
{
public:
    SdlApplication();
    bool init();
    void create();
    void close();
    
    void setTitle(char*);
    void setWindowSize(int,int);
    char* getTitle();
    void setIcon(string);
    SDL_PixelFormat* getPixelFormat();
    SDL_Surface* getSurface();
    SDL_Window* getWindow();
    virtual ~SdlApplication();
    int getWidth() {return width;}
    int getHeight() {return height;}
private:
    SDL_Window* appWindow;
    char* title;
    int imageFlags;
    int width;
    int height;
};

#endif	/* SDLAPPLICATION_H */
