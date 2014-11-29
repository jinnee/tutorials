#ifndef GAME_H
#define GAME_H

#include "SpriteManager.h"
#include "AbstractGame.h"
#include "SdlApplication.h"
#include "Cursor.h"
#include "Background.h"
#include "Button.h"

class Game : public SpriteManager, public AbstractGame
{
    public:
        double deltaTime;
        SDL_Surface* screen;
        Game();
        virtual ~Game();
        void start();
        SDL_PixelFormat* getPixelFormat();
        void setTitle(char* title);
        void setWindowSize(int,int);
        void setDone(bool);
        int getWidth();
        int getHeight();

    private:
        bool done;
        double thisTime;
        double lastTime;
        SDL_Event event;
        SDL_Window* window;
        char* title;
        SdlApplication *mSdlApplication;
        int mouse_x, mouse_y;
        int old_mouse_x, old_mouse_y;
        bool isCursorInWindow;

        void g_events();
        void g_update();
        void g_render();
};

#endif // GAME_H
